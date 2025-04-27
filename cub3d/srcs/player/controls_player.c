/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:01:08 by dangtran          #+#    #+#             */
/*   Updated: 2025/04/27 18:02:08 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		mlx_loop_end(game->window.mlx_ptr);
		return (0);
	}
	if (keycode == XK_w || keycode == XK_W)
		game->keys.forward = 1;
	if (keycode == XK_s || keycode == XK_S)
		game->keys.backward = 1;
	if (keycode == XK_a || keycode == XK_A)
		game->keys.left = 1;
	if (keycode == XK_d || keycode == XK_D)
		game->keys.right = 1;
	if (keycode == XK_Right)
		game->keys.rot_right = 1;
	if (keycode == XK_Left)
		game->keys.rot_left = 1;
	return (0);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_W)
		game->keys.forward = 0;
	if (keycode == XK_s || keycode == XK_S)
		game->keys.backward = 0;
	if (keycode == XK_a || keycode == XK_A)
		game->keys.left = 0;
	if (keycode == XK_d || keycode == XK_D)
		game->keys.right = 0;
	if (keycode == XK_Right)
		game->keys.rot_right = 0;
	if (keycode == XK_Left)
		game->keys.rot_left = 0;
	return (0);
}

void	update_game_state(t_game *game)
{
	if (game->keys.forward)
		move_forward(game);
	if (game->keys.backward)
		move_backward(game);
	if (game->keys.left)
		move_right(game);
	if (game->keys.right)
		move_left(game);
	if (game->keys.rot_left)
		rotate_right(game);
	if (game->keys.rot_right)
		rotate_left(game);
}
