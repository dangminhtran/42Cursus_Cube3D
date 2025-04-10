/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:05:19 by yamartin          #+#    #+#             */
/*   Updated: 2023/11/24 17:52:06 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int nb)
{
	int	size;

	size = 1;
	nb /= 10;
	while (nb)
	{
		nb /= 10;
		size *= 10;
	}
	return (size);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	i;
	int		size;

	i = n;
	if (i < 0)
	{
		ft_putchar_fd(45, fd);
		i *= -1;
	}
	size = get_size(i);
	while (size)
	{
		ft_putchar_fd((i / size) + 48, fd);
		i %= size;
		size /= 10;
	}
}

/*int main()
{
	ft_putnbr_fd(100, 1);
	return (0);
}*/