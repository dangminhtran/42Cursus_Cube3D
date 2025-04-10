/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:28:21 by yamartin          #+#    #+#             */
/*   Updated: 2023/11/10 17:46:28 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h> 
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	d = dest;
	s = src;
	if (d < s)
		while (n-- > 0)
			*d++ = *s++;
	else
		while (n-- > 0)
			*(d + n) = *(s + n);
	return (dest);
}

/*int main()
{
    char source[] = "Hello, world!";
    char destination[20];

    ft_memmove(destination, source + 6, 5);
    printf("Après ft_memmove : %s\n", destination);

    memmove(destination, source + 6, 5);
    printf("Après memmove : %s\n", destination);

    return 0;
}*/
