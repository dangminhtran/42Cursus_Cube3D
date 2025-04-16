/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:51:55 by yamartin          #+#    #+#             */
/*   Updated: 2025/04/15 14:19:25 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_only_map(t_map_data *map_data, int start_index)
{
	int	count;
	int	i;

	count = 0;
	i = start_index - 1;
	while (map_data->map_file[++i])
		count++;
	map_data->map = malloc(sizeof(char *) * (count + 1));
	if (!map_data->map)
		return (-1);
	i = start_index - 1;
	count = 0;
	while (map_data->map_file[++i])
	{
		map_data->map[count] = ft_strdup(map_data->map_file[i]);
		// printf("%s", map_data->map[count]);
		if (!map_data->map[count])
		{
			ft_free(map_data->map_file, count - 1);
			return (-1);
		}
		count++;
	}
	map_data->map[count] = NULL;
	map_data->map_height = count;
	get_map_width(map_data, count, map_data->map);
	return (0);
}

void	get_map_width(t_map_data *map_data, int count, char **map)
{
	int	len;
	int	i;

	i = 0;
	map_data->map_width = 0;
	while (i < count)
	{
		len = ft_strlen(map[i]);
		if (len > map_data->map_width)
			map_data->map_width = len;
		i++;
	}
}

void	get_special_map(t_map_data *map_data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	map_data->special_map = malloc(sizeof(char *) * (map_data->map_height + 2));
	while (i < map_data->map_height + 2)
	{
		map_data->special_map[i] = malloc(sizeof(char) * (map_data->map_width
					+ 1));
		j = 0;
		while (j < map_data->map_width)
		{
			if (i == 0)
				map_data->special_map[i][j] = 'z';
			else if (i == map_data->map_height + 1)
				map_data->special_map[i][j] = 'z';
			else if (j < ft_strlen2(map_data->map[i - 1]) && map_data->map[i
				- 1][j] != '\n' && map_data->map[i - 1][j] != ' '
				&& map_data->map[i - 1][j] != '\t')
				map_data->special_map[i][j] = map_data->map[i - 1][j];
			else
				map_data->special_map[i][j] = 'z';
			j++;
		}
		map_data->special_map[i][j] = '\0';
		// printf("%s\n", map_data->special_map[i]);
		i++;
	}
	map_data->special_map[i] = NULL;
}
