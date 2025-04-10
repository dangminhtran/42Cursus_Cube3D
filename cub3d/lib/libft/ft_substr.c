/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:19:39 by yamartin          #+#    #+#             */
/*   Updated: 2023/11/22 14:06:48 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*c;

	i = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	c = malloc (sizeof (char) * len + 1);
	if (!c)
		return (NULL);
	while (i < len && start < ft_strlen(s))
	{
		c[i] = s[start];
		start++;
		i++;
	}
	c[i] = '\0';
	return (c);
}

/*int main ()
{
	char c[] = "yanis";
	
	printf("%s", ft_substr(c, 0, 4200));
	return (0);
}*/