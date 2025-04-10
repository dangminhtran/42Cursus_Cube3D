/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:39:11 by yamartin          #+#    #+#             */
/*   Updated: 2025/03/26 16:44:14 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**ft_stock_file(char *name_file, char **tab)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(name_file, O_RDONLY);
	if (fd == -1)
		return (write(2, "invalid file\n", 13), exit(1), NULL);
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tab[i] = ft_strdup(line);
		if (!tab[i])
			return (NULL);
		free(line);
		line = NULL;
		i++;
	}
	tab[i] = NULL;
	close(fd);
	return (tab);
}

int	ft_get_map_size(char *name_file)
{
	int		map_size;
	char	*line;
	int		fd;

	fd = open(name_file, O_RDONLY);
	if (fd == -1)
		return (write(2, "invalid file\n", 13), exit(1), 0);
	map_size = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map_size++;
		free(line);
	}
	close(fd);
	return (map_size);
}

int	valid_name(char *str)
{
	char	*cub;

	cub = ft_strnstr(str, ".ber", ft_strlen2(str));
	if (cub == NULL)
		return (printf("error: file name does not contain '.cub'\n"), -1);
	if (ft_strlen2(cub) != 4)
		return (printf("error file name"), -1);
	return (0);
}
