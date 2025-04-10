/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:12:40 by yamartin          #+#    #+#             */
/*   Updated: 2023/11/17 18:04:35 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	lens1;
	size_t	lens2;
	char	*c;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	if (!s1 || s1[0] == '\0')
		return (ft_strdup(s2));
	if (!s2 || s2[0] == '\0')
		return (ft_strdup(s1));
	len = lens1 + lens2;
	c = malloc(sizeof (char) * len + 1);
	if (!c)
		return (NULL);
	ft_memcpy(c, s1, lens1);
	ft_memcpy(c + lens1, s2, lens2 + 1);
	return (c);
}
