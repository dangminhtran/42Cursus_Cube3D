/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:58:41 by yamartin          #+#    #+#             */
/*   Updated: 2023/11/14 14:10:18 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	valeur;

	p = s;
	valeur = (unsigned char) c;
	while (n > 0)
	{
		*p = valeur;
		p++;
		n--;
	}
	return (s);
}

/*int main() {
    char str1[] = "Bonjour, le monde!";
    char str2[] = "Bonjour, le monde!";

    size_t n = 10;

    // Utilisation de votre fonction ft_memset
    ft_memset(str1, 'X', n);
    printf("Après ft_memset : %s\n", str1);

    // Utilisation de la fonction memset de la bibliothèque standard
    memset(str2, 'X', n);
    printf("Après memset : %s\n", str2);

    // Comparaison des résultats
    if (strcmp(str1, str2) == 0) {
        printf("Les résultats concordent.\n");
    } else {
        printf("Les résultats diffèrent.\n");
    }

    return 0;
}*/
