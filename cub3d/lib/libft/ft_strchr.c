/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:29:04 by yamartin          #+#    #+#             */
/*   Updated: 2023/11/26 21:04:15 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//cherche la premiere occurence de c dans s
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char) c == '\0')
		return ((char *)s + i);
	return (NULL);
}
/*
int main()
{
 	printf ("%s", strchr("he\0llo", '\0'));
}*/