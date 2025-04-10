/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:48:27 by yamartin          #+#    #+#             */
/*   Updated: 2024/05/20 16:29:45 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_newline(t_list_gnl *lst)
{
	int			i;
	t_list_gnl	*curr;

	if (lst == NULL)
		return (FALSE);
	curr = ft_lst_last(lst);
	i = 0;
	while (curr->content[i])
	{
		if (curr->content[i] == '\n')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_list_gnl	*ft_lst_last(t_list_gnl *lst)
{
	t_list_gnl	*curr;

	curr = lst;
	while (curr && curr->next)
		curr = curr->next;
	return (curr);
}

int	ft__strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_gener_line(char **line, t_list_gnl *lst)
{
	int	i;
	int	len;

	len = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		lst = lst->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

void	ft_free_list(t_list_gnl *lst)
{
	t_list_gnl	*curr;
	t_list_gnl	*next;

	curr = lst;
	while (curr)
	{
		free(curr->content);
		next = curr->next;
		free(curr);
		curr = next;
	}
}
