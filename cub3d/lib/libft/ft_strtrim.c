/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:52:47 by yamartin          #+#    #+#             */
/*   Updated: 2023/11/24 17:55:15 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"
/*fonction (de merde) qui supprime les occurences de set dans s1
seulement au debut et a la fin de s1 (jusqu'a rencontrer un caractere
qui n'est pas dans set, au debut comme a la fin de s1)*/
static size_t	ft_isin(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
	set++;
	}
	return (0);
}

static size_t	ft_checkstart(char	const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_isin(s1[i], set))
		i++;
	return (i);
}

static size_t	ft_checkend(char const *s1, char const *set, size_t start)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (i > start && ft_isin(s1[i], set))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!set || !s1)
		return (NULL);
	start = ft_checkstart(s1, set);
	if (s1[start] == '\0')
		return (ft_strdup(""));
	end = ft_checkend(s1, set, start);
	return (ft_substr(s1, start, end - start + 1));
}

/*int main (int ac, char **av)
{
	(void) ac;

	printf("%s", ft_strtrim(av[1], av[2]));
	return (0);
}*/