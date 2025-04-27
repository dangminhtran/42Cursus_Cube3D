/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:14:10 by dangtran          #+#    #+#             */
/*   Updated: 2025/04/27 18:18:12 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clear_image(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->window.height)
	{
		x = 0;
		while (x < game->window.width)
		{
			put_pixel(game, x, y, 0);
			x++;
		}
		y++;
	}
}

int	close_window(t_game *game)
{
	mlx_loop_end(game->window.mlx_ptr);
	return (0);
}

void	exit_error(t_game *game, char *message)
{
	printf("Error: %s\n", message);
	cleanup_game(game);
	exit(1);
}

void	cleanup_game(t_game *game)
{
	cleanup_textures(game);
	if (game->window.frame.img.img)
		mlx_destroy_image(game->window.mlx_ptr, game->window.frame.img.img);
	if (game->window.win_ptr)
		mlx_destroy_window(game->window.mlx_ptr, game->window.win_ptr);
	if (game->window.mlx_ptr)
	{
		mlx_destroy_display(game->window.mlx_ptr);
		free(game->window.mlx_ptr);
	}
	ft_free_data(&game->map);
}
