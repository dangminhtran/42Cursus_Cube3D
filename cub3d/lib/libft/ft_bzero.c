/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:16:34 by yamartin          #+#    #+#             */
/*   Updated: 2023/11/26 17:06:17 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
//#include<string.h>
#include "libft.h"
//remplit d'octet nul les n premiers caractere de s
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n > 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}

/*int main()
{
	char s[] = "meuda is realf";
	char c[] = "meuda is realb";
	int i = 0;
	
	ft_bzero(s, 5);
	bzero(c, 5);
	while (i < 5)
		i++;
	return (0);
}*/
