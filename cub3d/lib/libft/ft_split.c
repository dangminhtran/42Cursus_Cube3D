/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:34:07 by yamartin          #+#    #+#             */
/*   Updated: 2023/11/26 23:28:24 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (s[0] == c && s[0])
		i++;
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == '\0')
			count++;
		if (s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_nextword(char *s, size_t pos, char c)
{
	size_t	i;

	i = pos;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
			return (i);
	}
	return (i);
}

static size_t	ft_wordlen(char *s, size_t pos, char c)
{
	size_t	i;

	i = pos;
	while (s[i])
	{
		if (s[i] == c)
			return (i - pos);
		i++;
	}
	return (i - pos);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	wl;
	size_t	pos;
	char	**tab;

	i = 0;
	pos = ft_nextword((char *)s, 0, c);
	tab = malloc(sizeof (char *) * (ft_countword(s, c) + 1));
	if (!tab)
		return (NULL);
	while (i < ft_countword(s, c))
	{
		wl = ft_wordlen((char *)s, pos, c);
		tab[i] = ft_substr(s, pos, wl);
		pos = ft_nextword((char *)s, pos + wl, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

/*int		main(void)
{
	int i = 0;
	char **tab;
		
	tab = ft_split("bonjour je m'appel Ya   dgaerbaergrabtrt draerg", ' ');
	while (i < 6)
	{
		printf("string %d : %s\n", i, tab[i]);
		i++;
	}
	return (0);
}*/