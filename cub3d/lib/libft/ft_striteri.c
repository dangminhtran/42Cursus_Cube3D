/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:28:12 by yamartin          #+#    #+#             */
/*   Updated: 2023/11/26 20:56:29 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	index;

	index = 0;
	if (!s)
		return ;
	while (s[index])
	{
		f(index, s + index);
		index++;
	}
}

/*void	iter(unsigned int i, char * s) 
{
	*s += i;
}

int main()
{
    char str[] = "0000000000";
    ft_striteri(str, &iter);
	printf("%s", str);
    return 0;
	
}*/
