/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:10:01 by yamartin          #+#    #+#             */
/*   Updated: 2025/04/09 15:05:05 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_map_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N'
				&& map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W'
				&& map[i][j] != '\n' && map[i][j] != ' ' && map[i][j] != '\t')
				return (printf("Unvalid map char !\n"), -1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_doubles(char **map)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				if (flag == 1)
					return (printf("Too many cardinal point\n"), -1);
					
				flag = 1;
			}
			j++;
		}
		i++;
	}
	if (flag == 0)
		return (printf("Need a cardinal point\n"), -1);
	return (0);
}

int	find_empty_area(t_map_data *map_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	get_special_map(map_data);
	while (i < map_data->map_height)
	{
		j = 0;
		while (j < map_data->map_width - 1)
		{
			if (map_data->special_map[i][j] == '0'
				|| map_data->special_map[i][j] == 'N'
				|| map_data->special_map[i][j] == 'S'
				|| map_data->special_map[i][j] == 'E'
				|| map_data->special_map[i][j] == 'W')
			{
				if (check_around(i, j, map_data->special_map) == -1)
					return (printf("Error : Wall or empty area.\n"), -1);
			}
			j++;
		}
		i++;
	}	
	return (0);
}

int	check_around(int i, int j, char **map)
{
	if (map[i + 1][j] == 'z')
		return (-1);
	if (map[i - 1][j] == 'z')
		return (-1);
	if (map[i][j + 1] == 'z')
		return (-1);
	if (map[i][j - 1] == 'z')
		return (-1);
	return (0);
}

int	parse_map(t_map_data *map_data)
{
	if (check_map_char(map_data->map) == -1)
		return (-1);
	if (check_doubles(map_data->map) == -1)
		return (-1);
	if (find_empty_area(map_data) == -1)
		return (-1);
	return (0);
}