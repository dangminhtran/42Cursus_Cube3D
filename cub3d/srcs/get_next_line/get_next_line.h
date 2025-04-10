/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:45:44 by yamartin          #+#    #+#             */
/*   Updated: 2024/05/20 16:29:51 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char					*get_next_line(int fd);

typedef struct s_list_gnl
{
	char				*content;
	struct s_list_gnl	*next;
}						t_list_gnl;

# define TRUE 1
# define FALSE 0

char					*get_next_line(int fd);
void					read_then_stock_list(int fd, t_list_gnl **lst,
							int *readed_ptr);
void					add_stock_list(t_list_gnl **lst, char *buffer,
							int readed);
void					ft_get_line(t_list_gnl *lst, char **line);
void					ft_clean_list(t_list_gnl **lst);
int						ft_check_newline(t_list_gnl *lst);
t_list_gnl				*ft_lst_last(t_list_gnl *lst);
int						ft__strlen(const char *str);
void					ft_gener_line(char **line, t_list_gnl *lst);
void					ft_free_list(t_list_gnl *lst);

#endif
