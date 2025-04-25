/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:09:53 by yamartin          #+#    #+#             */
/*   Updated: 2025/04/17 11:17:41 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// TODO - AJOUT
char *trim_path(char *path)
{
    char *start;
    char *end;
    int len;

	start = path;
    while (*start && (*start == ' ' || *start == '\t'))
        start++;
    if (!*start)
        return ft_strdup("");
    end = start + ft_strlen(start) - 1;
    while (end > start && (*end == ' ' || *end == '\t' || *end == '\n'))
        end--;
    len = end - start + 1;
    return ft_substr(start, 0, len);
}

int	parse_textures_lines(t_textures *textures)
{
	int		i;
	char	*line;

	i = 0;
	while (textures->textures[i])
	{
		line = textures->textures[i];
		if (!ft_strncmp(line, "NO ", 3))
			textures->no_texture = trim_path(line + 3);
		else if (!ft_strncmp(line, "SO ", 3))
			textures->so_texture = trim_path(line + 3);
		else if (!ft_strncmp(line, "WE ", 3))
			textures->we_texture = trim_path(line + 3);
		else if (!ft_strncmp(line, "EA ", 3))
			textures->ea_texture = trim_path(line + 3);
		else if (!ft_strncmp(line, "F ", 2))
		{
			textures->floor_color = ft_strdup(line + 2);
			if (get_floor_rgb(textures) == -1)
				return (-1);
		}
		else if (!ft_strncmp(line, "C ", 2))
		{
			textures->ceiling_color = ft_strdup(line + 2);
			if (get_ceiling_rgb(textures) == -1)
				return (-1);
		}
		else
			return (printf("Error ! Wrong texture line  : %s", line), -1);
		i++;
	}
	if (!textures->no_texture || !textures->so_texture || !textures->we_texture
		|| !textures->ea_texture)
		return (printf("Error in stocking texture !\n"), -1);
	return (0);
}

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	get_ceiling_rgb(t_textures *textures)
{
	char	**ceiling;
	int		count;

	ceiling = ft_split(textures->ceiling_color, ',');
	count = line_counter(ceiling);
	if (!ceiling || count != 3 || is_valid_rgb(ceiling[0]) == -1
		|| is_valid_rgb(ceiling[1]) == -1 || is_valid_rgb(ceiling[2]) == -1)
	{
		ft_free(ceiling, count);
		return (printf("Error : Unvalid RGB line(ceiling).\n"), -1);
	}
	textures->ceiling_rgb[0] = ft_atoi(ceiling[0]);
	textures->ceiling_rgb[1] = ft_atoi(ceiling[1]);
	textures->ceiling_rgb[2] = ft_atoi(ceiling[2]);
	ft_free(ceiling, count);
	return (0);
}

int	get_floor_rgb(t_textures *textures)
{
	char	**floor;
	int		count;

	floor = ft_split(textures->floor_color, ',');
	count = line_counter(floor);
	if (!floor || count != 3 || is_valid_rgb(floor[0]) == -1
		|| is_valid_rgb(floor[1]) == -1 || is_valid_rgb(floor[2]) == -1)
	{
		ft_free(floor, count);
		return (printf("Error : Unvalid RGB line(floor).\n"), -1);
	}
	textures->floor_rgb[0] = ft_atoi(floor[0]);
	textures->floor_rgb[1] = ft_atoi(floor[1]);
	textures->floor_rgb[2] = ft_atoi(floor[2]);
	ft_free(floor, count);
	return (0);
}

int	is_valid_rgb(char *line)
{
	int	i;
	int	number;

	i = 0;
	while (ft_is_space(line[i]))
		i++;
	if (!ft_isdigit(line[i]))
		return (-1);
	number = ft_atoi(line + i);
	if (number < 0 || number > 255)
		return (-1);
	while (ft_isdigit(line[i]))
		i++;
	while (ft_is_space(line[i]))
		i++;
	if (line[i] != '\0')
		return (-1);
	return (0);
}


