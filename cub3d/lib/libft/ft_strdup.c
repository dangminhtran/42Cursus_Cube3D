/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:58:48 by yamartin          #+#    #+#             */
/*   Updated: 2023/11/16 01:33:02 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//alloue la memoire d'une nouvelle chaine pour y copier s dedans
char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*c;

	i = 0;
	c = malloc (sizeof (char) * ft_strlen(s) + 1);
	if (!c)
		return (NULL);
	while (s[i])
	{
		c[i] = s[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

/*int main ()
 {
	const char *s = "yanis";
	printf("%s", ft_strdup(s));
	return (0);
 }*/