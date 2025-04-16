/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:49:30 by yamartin          #+#    #+#             */
/*   Updated: 2025/04/15 14:36:56 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_textures(t_map_data *map_data)
{
	int	i;

	i = 0;
	map_data->count = 0;
	init_textures(map_data->textures);
	map_data->textures->textures = malloc(sizeof(char *) * 10);
	if (!map_data->textures->textures)
		return (-1);
	while (map_data->map_file[i] && map_data->count < 6)
	{
		if (!is_empty_line(map_data->map_file[i]))
		{
			map_data->textures->textures[map_data->count] = ft_strdup(map_data->map_file[i]);
			if (!map_data->textures->textures[map_data->count])
				return (-1);
			map_data->count++;
		}
		i++;
	}
	map_data->textures->textures[map_data->count] = NULL;
	if (map_data->count < 6) // 6
		return (printf("Error ! Missing textures.\n"), -1);
	while (is_empty_line(map_data->map_file[i]))
		i++;
	// retourne l'index du debut de la map
	return (i);
}

int	line_counter(char **tableau)
{
	int	i;

	i = 0;
	while (tableau[i] != NULL)
		i++;
	return (i);
}

void	get_player_pos(t_map_data *map_data, t_display *display)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_data->map[i])
	{
		printf("%s", map_data->map[i]);
		j = 0;
		while (map_data->map[i][j])
		{
			if (map_data->map[i][j] == 'N' || map_data->map[i][j] == 'S'
				|| map_data->map[i][j] == 'E' || map_data->map[i][j] == 'W')
			{
				display->player_posx = i;
				display->player_posy = j;
			}
			j++;
		}
		i++;
	}
}
