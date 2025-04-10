/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:24:02 by yamartin          #+#    #+#             */
/*   Updated: 2023/11/26 23:45:51 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	j;

	j = 0;
	if (size > 0)
	{
		while (src[j] && size - 1 > j)
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = '\0';
	}
	return (ft_strlen(src));
}

/*int main()
{
	// char s[] = "efgh";
	// char c[] = "abcdz";
	char *c = strdup("ab");
	char *s = strdup("ab\0\0\0");
	
	printf("1ere chaine avant ; %s\n", c);
	printf("2eme chaine avant ; %s\n", s);

	ft_strlcpy(s, c, 5);
	
	printf("1ere chaine apres ; %s\n", c);
	printf("2eme chaine apres ; %s\n", s);
	
	return (0);
}*/

// taille == 5 ; nb caractere possible == 4
// a 
// b 
// c 
// d 
// \0 4
// taille == 6 ;  nb caractere possible == 5 
// \0
// b
// c 
// d
// z
// \0 
