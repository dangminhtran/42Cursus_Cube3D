/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:16:01 by yamartin          #+#    #+#             */
/*   Updated: 2025/04/27 18:14:59 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	setup_hooks(t_game *game)
{
	mlx_hook(game->window.win_ptr, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->window.win_ptr, 3, 1L << 1, handle_keyrelease, game);
	mlx_hook(game->window.win_ptr, 17, 0, close_window, game);
	mlx_loop_hook(game->window.mlx_ptr, render_frame, game);
}

void	get_player_spawn(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'N' || game->map.map[i][j] == 'S'
				|| game->map.map[i][j] == 'E' || game->map.map[i][j] == 'W')
			{
				game->map.spawn.x = i;
				game->map.spawn.y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (printf("Error: Need a map file!\n"), 1);
	ft_memset(&game, 0, sizeof(t_game));
	game.map.file_size = ft_get_map_size(av[1]);
	game.map.map_file = malloc(sizeof(char *) * (game.map.file_size + 1));
	if (!game.map.map_file)
		return (printf("Error: Memory allocation failed\n"), 1);
	game.map.map_file = ft_stock_file(av[1], game.map.map_file);
	init_data(&game.map);
	game.map.textures = &game.textures;
	if (general_parsing(&game.map, av) == -1)
	{
		ft_free_data(&game.map);
		return (1);
	}
	get_player_spawn(&game);
	init_game(&game);
	setup_hooks(&game);
	mlx_loop(game.window.mlx_ptr);
	cleanup_game(&game);
	return (0);
}
