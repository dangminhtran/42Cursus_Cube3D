/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:52:52 by yamartin          #+#    #+#             */
/*   Updated: 2023/11/24 17:49:24 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//transforme un int en char en allouant l'espace memoire necessaire
static int	ft_dizaine(long dizaine, int len_nbr)
{
	while (dizaine > 0)
	{
		dizaine /= 10;
		len_nbr++;
	}
	return (len_nbr);
}

static char	*ft_calcul(char *str, long n, int i)
{
	while (n > 0)
	{
		str[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int nbr)
{
	long	n;
	int		len_nbr;
	long	dizaine;
	char	*str;
	int		i;

	n = nbr;
	len_nbr = 0;
	if (n <= 0)
	{
		n *= -1;
		len_nbr++;
	}
	dizaine = n;
	len_nbr = ft_dizaine(dizaine, len_nbr);
	str = (char *)malloc(sizeof(char) * (len_nbr + 1));
	if (!str)
		return (NULL);
	str[len_nbr] = '\0';
	if (n == 0)
		str[0] = '0';
	if (nbr < 0)
		str[0] = '-';
	i = len_nbr - 1;
	return (ft_calcul(str, n, i));
}

/*int main(void)
{
	int i = 0;
	int tab[5] = {-2147483648, -42, 42, 2147483647, 0};
	while (i < 5)
		printf("%s\n", ft_itoa(tab[i++]));
	return 0;
}*/
