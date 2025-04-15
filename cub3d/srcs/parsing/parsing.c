/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:05:15 by yamartin          #+#    #+#             */
/*   Updated: 2025/04/15 13:51:27 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	general_parsing(t_map_data *map_data)
{
	int	start_map_index;

	start_map_index = get_textures(map_data);
	if (start_map_index == -1)
		return (-1);
	if (parse_textures_lines(map_data->textures) == -1)
		return (-1);
	if (get_only_map(map_data, start_map_index)  == -1)
		return (-1);
	if (parse_map(map_data) == -1)
		return (-1);
	return (0);
}

// TODO - Verifier si c'est un .cub
// TODO - Stocker la data du player (pos)
