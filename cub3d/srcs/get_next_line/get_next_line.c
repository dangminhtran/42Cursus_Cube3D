/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:32:35 by yamartin          #+#    #+#             */
/*   Updated: 2024/05/20 16:29:35 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list_gnl	*lst = NULL;
	char				*line;
	int					readed;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, &line, 0) < 0)
		return (NULL);
	readed = 1;
	line = NULL;
	read_then_stock_list(fd, &lst, &readed);
	if (lst == NULL)
		return (NULL);
	ft_get_line(lst, &line);
	ft_clean_list(&lst);
	if (line[0] == '\0')
	{
		ft_free_list(lst);
		lst = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

void	read_then_stock_list(int fd, t_list_gnl **lst, int *readed_ptr)
{
	char	*buffer;

	while (!ft_check_newline(*lst) && *readed_ptr != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return ;
		*readed_ptr = read(fd, buffer, BUFFER_SIZE);
		if ((*lst == NULL && (int)*readed_ptr == 0) || *readed_ptr == -1)
		{
			free(buffer);
			return ;
		}
		buffer[*readed_ptr] = '\0';
		add_stock_list(lst, buffer, *readed_ptr);
		free(buffer);
	}
}

void	add_stock_list(t_list_gnl **lst, char *buffer, int readed)
{
	int			i;
	t_list_gnl	*last;
	t_list_gnl	*new_node;

	new_node = malloc(sizeof(t_list_gnl));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (readed + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buffer[i] && i != readed)
	{
		new_node->content[i] = buffer[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	last = ft_lst_last(*lst);
	last->next = new_node;
}

void	ft_get_line(t_list_gnl *lst, char **line)
{
	int	i;
	int	j;

	if (lst == NULL)
		return ;
	ft_gener_line(line, lst);
	if (*line == NULL)
		return ;
	j = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				(*line)[j++] = lst->content[i++];
				break ;
			}
			(*line)[j++] = lst->content[i++];
		}
		lst = lst->next;
	}
	(*line)[j] = '\0';
}

void	ft_clean_list(t_list_gnl **lst)
{
	t_list_gnl	*last;
	t_list_gnl	*clean;
	int			i;
	int			j;

	clean = malloc(sizeof(t_list_gnl));
	if (lst == NULL || clean == NULL)
		return ;
	clean->next = NULL;
	last = ft_lst_last(*lst);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n' && last->content[i])
		i++;
	clean->content = malloc(sizeof(char) * (ft__strlen(last->content) - i) + 1);
	if (clean == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean->content[j++] = last->content[i++];
	clean->content[j] = '\0';
	ft_free_list(*lst);
	*lst = clean;
}
