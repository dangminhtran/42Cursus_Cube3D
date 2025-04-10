/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:06:42 by yamartin          #+#    #+#             */
/*   Updated: 2025/03/24 15:55:00 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == '\t' || line[i] == '\v' || line[i] == '\n'
				|| line[i] == '\r' || line[i] == '\f' || line[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}

void	ft_free(char **map, int count)
{
	while (count >= 0)
	{
		free(map[count]);
		count--;
	}
	free(map);
}

void	ft_free_data(t_map_data *map_data)
{
	if (!map_data->textures)
		return ;
	if (map_data->textures->no_texture)
		free(map_data->textures->no_texture);
	if (map_data->textures->so_texture)
		free(map_data->textures->so_texture);
	if (map_data->textures->we_texture)
		free(map_data->textures->we_texture);
	if (map_data->textures->ea_texture)
		free(map_data->textures->ea_texture);
	if (map_data->textures->textures)
		ft_free(map_data->textures->textures, map_data->count);
	if (map_data->map_file)
		ft_free(map_data->map_file, map_data->file_size);
	if (map_data->map)
		ft_free(map_data->map, map_data->map_height);
}

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	init_data(t_map_data *map_data)
{
	map_data->count = 0;
	map_data->map_height = 0;
	map_data->map_width = 0;
}

void	init_textures(t_textures *textures)
{
	textures->no_texture = NULL;
	textures->so_texture = NULL;
	textures->we_texture = NULL;
	textures->ea_texture = NULL;
}
