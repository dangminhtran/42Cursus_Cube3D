/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:05:15 by yamartin          #+#    #+#             */
/*   Updated: 2025/04/16 16:55:13 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	general_parsing(t_map_data *map_data, char **av)
{
	int	start_map_index;

	start_map_index = get_textures(map_data);
	if (is_valid_extension(av[1]))
		return (-1);
	if (start_map_index == -1)
		return (-1);
	if (parse_textures_lines(map_data->textures) == -1)
		return (-1);
	if (get_only_map(map_data, start_map_index) == -1)
		return (-1);
	if (parse_map(map_data) == -1)
		return (-1);
	return (0);
}

int	is_valid_extension(char *str)
{
	char	*ber;

	ber = ft_strnstr(str, ".cub", ft_strlen(str));
	if (ber == NULL)
		return (printf("error: file name does not contain '.cub' extension\n"),
			1);
	if (ft_strlen(ber) != 4)
		return (printf("error file name\n"), 1);
	return (0);
}

// TODO - Verifier si c'est un .cub       ---DONE---
// TODO - Stocker la data du player (pos) ---DONE---
