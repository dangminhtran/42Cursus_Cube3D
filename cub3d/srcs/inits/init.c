/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:12:06 by dangtran          #+#    #+#             */
/*   Updated: 2025/04/27 18:16:07 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_player(t_game *game)
{
	game->player.pos.x = game->map.spawn.x + 0.5;
	game->player.pos.y = game->map.spawn.y + 0.5;
	if (game->map.map[game->map.spawn.x][game->map.spawn.y] == 'N')
	{
		game->player.dir.x = 0;
		game->player.dir.y = -1;
		game->player.plane.x = 0.66;
		game->player.plane.y = 0;
	}
	else if (game->map.map[game->map.spawn.x][game->map.spawn.y] == 'S')
	{
		game->player.dir.x = 0;
		game->player.dir.y = 1;
		game->player.plane.x = -0.66;
		game->player.plane.y = 0;
	}
	else if (game->map.map[game->map.spawn.x][game->map.spawn.y] == 'E')
	{
		game->player.dir.x = 1;
		game->player.dir.y = 0;
		game->player.plane.x = 0;
		game->player.plane.y = 0.66;
	}
	else if (game->map.map[game->map.spawn.x][game->map.spawn.y] == 'W')
	{
		game->player.dir.x = -1;
		game->player.dir.y = 0;
		game->player.plane.x = 0;
		game->player.plane.y = -0.66;
	}
	game->settings.move_speed = 0.03;
	game->settings.rot_speed = 0.03;
	game->settings.cos_rot_speed = cos(game->settings.rot_speed);
	game->settings.sin_rot_speed = sin(game->settings.rot_speed);
	game->settings.cos_neg_rot_speed = cos(-game->settings.rot_speed);
	game->settings.sin_neg_rot_speed = sin(-game->settings.rot_speed);
}

void	init_game(t_game *game)
{
	game->keys.forward = 0;
	game->keys.backward = 0;
	game->keys.left = 0;
	game->keys.right = 0;
	game->keys.rot_left = 0;
	game->keys.rot_right = 0;
	game->window.mlx_ptr = mlx_init();
	if (!game->window.mlx_ptr)
		exit_error(game, "MLX initialization failed");
	game->window.width = 1024;
	game->window.height = 768;
	game->window.win_ptr = mlx_new_window(game->window.mlx_ptr,
			game->window.width, game->window.height, "cub3D");
	if (!game->window.win_ptr)
		exit_error(game, "Window creation failed");
	game->window.frame.img.img = mlx_new_image(game->window.mlx_ptr,
			game->window.width, game->window.height);
	if (!game->window.frame.img.img)
		exit_error(game, "Image creation failed");
	game->window.frame.img.addr = mlx_get_data_addr(game->window.frame.img.img,
			&game->window.frame.img.bits_per_pixel,
			&game->window.frame.img.size_line, &game->window.frame.img.endian);
	load_textures(game);
	init_player(game);
}
