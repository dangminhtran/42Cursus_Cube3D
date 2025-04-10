/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:28:40 by yamartin          #+#    #+#             */
/*   Updated: 2023/11/23 15:16:44 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nxt;
	t_list	*cour;

	if (!lst || !del)
		return ;
	cour = *lst;
	while (cour != NULL)
	{
		nxt = cour->next;
		ft_lstdelone(cour, del);
		cour = nxt;
	}
	*lst = NULL;
}
