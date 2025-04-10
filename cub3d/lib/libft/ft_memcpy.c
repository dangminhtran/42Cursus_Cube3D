/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:15:37 by yamartin          #+#    #+#             */
/*   Updated: 2023/11/26 18:33:33 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*c;

	s = dest;
	c = (unsigned char *)src;
	while (n > 0)
	{
		*s++ = *c++;
		n--;
	}
	return (dest);
}

/*int main() {
    char source[] = "Hello, world!";
    char destination[20];
    char dest2[20];

    bzero(destination, 20);
    bzero(dest2, 20);
    ft_memcpy(destination, source, 6);
    printf("Après ft_memcpy : %s\n", destination);


    memcpy(destination, source, 6);
    memcpy(dest2, source, 6);
    printf("Après memcpy : %s\n", dest2);

 
    if (memcmp(dest2, destination, 6) == 0) {
        printf("Les résultats concordent.\n");
    } else {
        printf("Les résultats diffèrent.\n");
    }

    return 0;
}*/
