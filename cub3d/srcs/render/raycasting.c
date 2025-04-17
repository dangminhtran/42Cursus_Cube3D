#include "../cub3d.h"

static int	get_next_square(t_game *game)
{
	if (game->frame.side_dist.x < game->frame.side_dist.y)
	{
		game->frame.side_dist.x += game->frame.delta_dist.x;
		game->frame.map.x += game->frame.step.x;
		game->frame.side = 0;
	}
	else
	{
		game->frame.side_dist.y += game->frame.delta_dist.y;
		game->frame.map.y += game->frame.step.y;
		game->frame.side = 1;
	}
	return (1);
}

static int	get_hit_value(t_game *game)
{
	if ((game->frame.step.x < 0 && game->frame.map.x < 0) \
		|| (game->frame.step.y < 0 && game->frame.map.y < 0) \
		|| ((game->frame.map.x >= game->map.map_width) && game->frame.step.x >= 0)
		|| ((game->frame.map.y >= game->map.map_height) && game->frame.step.y >= 0))
	{
		game->frame.hit = 1;
	}
	else if (game->frame.map.x >= 0 && game->frame.map.y >= 0
		&& game->frame.map.x < game->map.map_width \
			&& game->frame.map.y < game->map.map_height)
		game->frame.hit_value = \
			game->map.map[game->frame.map.y][game->frame.map.x];
	return (1);
}

static int	check_hit(t_game *game)
{
	if (game->frame.hit_value == '1')
		game->frame.hit = 1;
	else if (game->frame.hit_value == '0')
		game->frame.hit = 0;
	return (1);
}
	// else if (game->frame.hit_value == 'D')
	// {
	// 	game->frame.hit = 1;
	// 	game->frame.hit_value = 'D';
	// }

int	ft_raycasting_dda(t_game *game)
{
	while (game->frame.hit == 0)
	{
		get_next_square(game);
		get_hit_value(game);
		if (game->frame.hit_value != '0')
			check_hit(game);
	}
	return (1);
}

void	ft_raycasting_step(t_game *game)
{
	if (game->frame.ray_dir.x < 0)
	{
		game->frame.step.x = -1;
		game->frame.side_dist.x = (game->player.pos.x - game->frame.map.x) \
			* game->frame.delta_dist.x;
	}
	else
	{
		game->frame.step.x = 1;
		game->frame.side_dist.x = (game->frame.map.x + 1.0 - game->player.pos.x)
			* game->frame.delta_dist.x;
	}
	if (game->frame.ray_dir.y < 0)
	{
		game->frame.step.y = -1;
		game->frame.side_dist.y = (game->player.pos.y - game->frame.map.y) \
			* game->frame.delta_dist.y;
	}
	else
	{
		game->frame.step.y = 1;
		game->frame.side_dist.y = (game->frame.map.y + 1.0 - game->player.pos.y)
			* game->frame.delta_dist.y;
	}
}

static int	ft_raycasting_wall_2(t_game *game)
{
	if (game->frame.side == 0)
		game->frame.wall.x = game->player.pos.y \
			+ game->frame.perp_wall_dist * game->frame.ray_dir.y;
	else
		game->frame.wall.x = game->player.pos.x \
			+ game->frame.perp_wall_dist * game->frame.ray_dir.x;
	game->frame.wall.x -= (int)game->frame.wall.x;
	return (1);
}

int	ft_raycasting_wall(t_game *game)
{
	if (game->frame.side == 0)
		game->frame.perp_wall_dist = game->frame.side_dist.x \
			- game->frame.delta_dist.x;
	else if (game->frame.side == 1)
		game->frame.perp_wall_dist = game->frame.side_dist.y \
			- game->frame.delta_dist.y;
	game->frame.line_height = (int)(game->window.height \
		/ game->frame.perp_wall_dist);
	game->frame.draw_start = (int)(-game->frame.line_height / 2 \
		+ game->window.height / 2);
	if (game->frame.draw_start < 0)
		game->frame.draw_start = 0;
	if (game->frame.draw_start > game->window.height)
		game->frame.draw_start = game->window.height;
	game->frame.draw_end = (int)(game->frame.line_height / 2 \
		+ game->window.height / 2);
	if (game->frame.draw_end > game->window.height)
		game->frame.draw_end = game->window.height;
	if (game->frame.draw_end < 0)
		game->frame.draw_end = 0;
	return (ft_raycasting_wall_2(game));
}