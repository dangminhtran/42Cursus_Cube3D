/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:51:55 by dangtran          #+#    #+#             */
/*   Updated: 2025/04/27 18:02:10 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos.x + game->player.dir.x * game->settings.move_speed;
	new_y = game->player.pos.y + game->player.dir.y * game->settings.move_speed;
	if (is_valid_position(game, new_x, game->player.pos.y))
		game->player.pos.x = new_x;
	if (is_valid_position(game, game->player.pos.x, new_y))
		game->player.pos.y = new_y;
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos.x - game->player.dir.x * game->settings.move_speed;
	new_y = game->player.pos.y - game->player.dir.y * game->settings.move_speed;
	if (is_valid_position(game, new_x, game->player.pos.y))
		game->player.pos.x = new_x;
	if (is_valid_position(game, game->player.pos.x, new_y))
		game->player.pos.y = new_y;
}

void	move_left(t_game *game)
{
	double	perp_x;
	double	perp_y;
	double	new_x;
	double	new_y;

	perp_x = -game->player.dir.y;
	perp_y = game->player.dir.x;
	new_x = game->player.pos.x + perp_x * game->settings.move_speed;
	new_y = game->player.pos.y + perp_y * game->settings.move_speed;
	if (is_valid_position(game, new_x, game->player.pos.y))
		game->player.pos.x = new_x;
	if (is_valid_position(game, game->player.pos.x, new_y))
		game->player.pos.y = new_y;
}

void	move_right(t_game *game)
{
	double	perp_x;
	double	perp_y;
	double	new_x;
	double	new_y;

	perp_x = game->player.dir.y;
	perp_y = -game->player.dir.x;
	new_x = game->player.pos.x + perp_x * game->settings.move_speed;
	new_y = game->player.pos.y + perp_y * game->settings.move_speed;
	if (is_valid_position(game, new_x, game->player.pos.y))
		game->player.pos.x = new_x;
	if (is_valid_position(game, game->player.pos.x, new_y))
		game->player.pos.y = new_y;
}

int	is_valid_position(t_game *game, double x, double y)
{
	int		map_x;
	int		map_y;
	double	buffer;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_y < 0 || map_x >= game->map.map_height
		|| map_y >= game->map.map_width)
		return (0);
	if (game->map.map[map_x][map_y] == '1')
		return (0);
	buffer = 0.2;
	if (fabs(x - map_x) < buffer || fabs(x - (map_x + 1)) < buffer || fabs(y
			- map_y) < buffer || fabs(y - (map_y + 1)) < buffer)
	{
		if ((map_x + 1 < game->map.map_height && game->map.map[map_x
				+ 1][map_y] == '1' && fabs(x - (map_x + 1)) < buffer) || (map_x
				- 1 >= 0 && game->map.map[map_x - 1][map_y] == '1' && fabs(x
					- map_x) < buffer) || (map_y + 1 < game->map.map_width
				&& game->map.map[map_x][map_y + 1] == '1' && fabs(y - (map_y
						+ 1)) < buffer) || (map_y - 1 >= 0
				&& game->map.map[map_x][map_y - 1] == '1' && fabs(y
					- map_y) < buffer))
		{
			return (0);
		}
	}
	return (1);
}
