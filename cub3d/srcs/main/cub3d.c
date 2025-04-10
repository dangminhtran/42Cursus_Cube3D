/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:16:01 by yamartin          #+#    #+#             */
/*   Updated: 2025/03/21 13:41:42 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (printf("Need a map !\n"), 0);
	t_display display;
	t_map_data map_data;
	t_textures textures;
	
	// ft_memset(&map_data, 0, sizeof(t_map_data));
	// ft_memset(&display, 0, sizeof(t_display));
	map_data.map = 0;
	map_data.file_size = ft_get_map_size(av[1]);
	map_data.map_file = malloc(sizeof(char *) * (map_data.file_size + 1));
	map_data.textures = &textures;
	if (!map_data.map_file)
	return (0);
	map_data.map_file = ft_stock_file(av[1], map_data.map_file);
	init_data(&map_data);
	if (general_parsing(&map_data) == -1)
	{
		ft_free_data(&map_data);
		return (0);
	}
	open_window(&display);
	ft_free_data(&map_data);
	return (0);
}