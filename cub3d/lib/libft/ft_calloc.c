/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:41:22 by yamartin          #+#    #+#             */
/*   Updated: 2023/11/26 20:18:00 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*c;

	if (size && (nmemb * size) / size != nmemb)
		return (NULL);
	c = malloc (nmemb * size);
	if (!c)
		return (NULL);
	ft_memset(c, 0, nmemb * size);
	return (c);
}
