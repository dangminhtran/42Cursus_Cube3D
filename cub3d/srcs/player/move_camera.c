/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:58:49 by dangtran          #+#    #+#             */
/*   Updated: 2025/04/27 18:02:33 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * game->settings.cos_rot_speed
		- game->player.dir.y * game->settings.sin_rot_speed;
	game->player.dir.y = old_dir_x * game->settings.sin_rot_speed
		+ game->player.dir.y * game->settings.cos_rot_speed;
	old_plane_x = game->player.plane.x;
	game->player.plane.x = game->player.plane.x * game->settings.cos_rot_speed
		- game->player.plane.y * game->settings.sin_rot_speed;
	game->player.plane.y = old_plane_x * game->settings.sin_rot_speed
		+ game->player.plane.y * game->settings.cos_rot_speed;
}

void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * game->settings.cos_neg_rot_speed
		- game->player.dir.y * game->settings.sin_neg_rot_speed;
	game->player.dir.y = old_dir_x * game->settings.sin_neg_rot_speed
		+ game->player.dir.y * game->settings.cos_neg_rot_speed;
	old_plane_x = game->player.plane.x;
	game->player.plane.x = game->player.plane.x
		* game->settings.cos_neg_rot_speed - game->player.plane.y
		* game->settings.sin_neg_rot_speed;
	game->player.plane.y = old_plane_x * game->settings.sin_neg_rot_speed
		+ game->player.plane.y * game->settings.cos_neg_rot_speed;
}