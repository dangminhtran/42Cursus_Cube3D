/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:54:11 by yamartin          #+#    #+#             */
/*   Updated: 2023/11/17 18:17:26 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
//convertit le debut de la chaine nptr en int
int	ft_atoi(const char *nptr)
{
	int	x;
	int	nb;

	x = 1;
	nb = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			x *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
		nb = (nb * 10) + (*(nptr)++ - 48);
	return (nb * x);
}

/*int main(int ac, char **av)
{
	char *s = NULL;
	printf("%d\n", atoi(s));
}*/