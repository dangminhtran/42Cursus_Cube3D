
#include "cub3d.h"

int	ft_init_coord(t_coord *coord, double x, double y)
{
	coord->x = x;
	coord->y = y;
	return (1);
}

int	ft_init_vector(t_vector *vec, int x, int y)
{
	vec->x = x;
	vec->y = y;
	return (1);
}

int	ft_init_window(t_game *game)
{
	game->window.mlx_ptr = NULL;
	game->window.win_ptr = NULL;
	game->window.height = -1;
	game->window.width = -1;
	ft_init_image(game, &game->window.frame);
	return (1);
}

int	ft_init_frame(t_frame *frame)
{
	ft_init_coord(&frame->ray_dir, 0, 0);
	ft_init_vector(&frame->map, 0, 0);
	ft_init_coord(&frame->side_dist, 0, 0);
	ft_init_coord(&frame->delta_dist, 0, 0);
	ft_init_vector(&frame->step, 0, 0);
	ft_init_coord(&frame->wall, 0, 0);
	frame->hit = 0;
	frame->hit_value = 0;
	frame->side = -1;
	frame->perp_wall_dist = 0;
	frame->line_height = 0;
	frame->draw_start = 0;
	frame->draw_end = 0;
	frame->color = 0;
	return (1);
}

ft_init_settings(t_settings *settings)
{
	settings->fov = 0;
	settings->move_speed = 0;
	settings->sprint_speed = 0;
	settings->rot_speed = 0;
	settings->cos_rot_speed = 0;
	settings->sin_rot_speed = 0;
	settings->cos_neg_rot_speed = 0;
	settings->sin_neg_rot_speed = 0;
	return (1);
}



