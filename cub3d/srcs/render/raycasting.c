/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:12:21 by dangtran          #+#    #+#             */
/*   Updated: 2025/04/27 18:18:47 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cast_rays(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->window.width)
	{
		game->frame.camera.x = 2 * x / (double)game->window.width - 1;
		game->frame.ray_dir.x = game->player.dir.x + game->player.plane.x
			* game->frame.camera.x;
		game->frame.ray_dir.y = game->player.dir.y + game->player.plane.y
			* game->frame.camera.x;
		game->frame.map.x = (int)game->player.pos.x;
		game->frame.map.y = (int)game->player.pos.y;
		if (game->frame.ray_dir.x == 0)
			game->frame.delta_dist.x = 1e30;
		else
			game->frame.delta_dist.x = fabs(1 / game->frame.ray_dir.x);
		if (game->frame.ray_dir.y == 0)
			game->frame.delta_dist.y = 1e30;
		else
			game->frame.delta_dist.y = fabs(1 / game->frame.ray_dir.y);
		if (game->frame.ray_dir.x < 0)
		{
			game->frame.step.x = -1;
			game->frame.side_dist.x = (game->player.pos.x - game->frame.map.x)
				* game->frame.delta_dist.x;
		}
		else
		{
			game->frame.step.x = 1;
			game->frame.side_dist.x = (game->frame.map.x + 1.0
					- game->player.pos.x) * game->frame.delta_dist.x;
		}
		if (game->frame.ray_dir.y < 0)
		{
			game->frame.step.y = -1;
			game->frame.side_dist.y = (game->player.pos.y - game->frame.map.y)
				* game->frame.delta_dist.y;
		}
		else
		{
			game->frame.step.y = 1;
			game->frame.side_dist.y = (game->frame.map.y + 1.0
					- game->player.pos.y) * game->frame.delta_dist.y;
		}
		perform_dda(game);
		if (game->frame.side == 0)
			game->frame.perp_wall_dist = (game->frame.side_dist.x
					- game->frame.delta_dist.x);
		else
			game->frame.perp_wall_dist = (game->frame.side_dist.y
					- game->frame.delta_dist.y);
		game->frame.line_height = (int)(game->window.height
				/ game->frame.perp_wall_dist);
		game->frame.draw_start = -game->frame.line_height / 2
			+ game->window.height / 2;
		if (game->frame.draw_start < 0)
			game->frame.draw_start = 0;
		game->frame.draw_end = game->frame.line_height / 2 + game->window.height
			/ 2;
		if (game->frame.draw_end >= game->window.height)
			game->frame.draw_end = game->window.height - 1;
		draw_vertical_line(game, x);
		x++;
	}
}

void	perform_dda(t_game *game)
{
	game->frame.hit = 0;
	while (game->frame.hit == 0)
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
		if (game->frame.map.y >= 0 && game->frame.map.x >= 0
			&& game->frame.map.y < game->map.map_width
			&& game->frame.map.x < game->map.map_height)
		{
			if (game->map.map[game->frame.map.x][game->frame.map.y] == '1')
			{
				game->frame.hit = 1;
				game->frame.hit_value = '1';
			}
		}
		else
		{
			game->frame.hit = 1;
			game->frame.hit_value = '1';
		}
	}
}

void	draw_vertical_line(t_game *game, int x)
{
	int		y;
	int		tex_x;
	int		tex_y;
	double	wall_x;
	double	step;
	double	tex_pos;
	int		color;
	t_image	*texture;

	//	int var[2];
	//	var[0] = ((var[1] = 0))
	if (game->frame.side == 0)
		wall_x = game->player.pos.y + game->frame.perp_wall_dist
			* game->frame.ray_dir.y;
	else
		wall_x = game->player.pos.x + game->frame.perp_wall_dist
			* game->frame.ray_dir.x;
	wall_x -= floor(wall_x);
	if (game->frame.side == 0)
	{
		if (game->frame.ray_dir.x > 0)
			texture = &game->textures.east_img;
		else
			texture = &game->textures.west_img;
	}
	else
	{
		if (game->frame.ray_dir.y > 0)
			texture = &game->textures.south_img;
		else
			texture = &game->textures.north_img;
	}
	tex_x = (int)(wall_x * game->textures.tex_width);
	if ((game->frame.side == 0 && game->frame.ray_dir.x > 0)
		|| (game->frame.side == 1 && game->frame.ray_dir.y < 0))
		tex_x = game->textures.tex_width - tex_x - 1;
	step = 1.0 * game->textures.tex_height / game->frame.line_height;
	tex_pos = (game->frame.draw_start - game->window.height / 2
			+ game->frame.line_height / 2) * step;
	y = 0;
	while (y < game->frame.draw_start)
	{
		put_pixel(game, x, y,
			game->textures.ceiling_rgb[0] << 16 | game->textures.ceiling_rgb[1] << 8 | game->textures.ceiling_rgb[2]);
		y++;
	}
	while (y < game->frame.draw_end)
	{
		tex_y = (int)tex_pos & (game->textures.tex_height - 1);
		tex_pos += step;
		color = get_texture_color(texture, tex_x, tex_y);
		if (game->frame.side == 1)
			color = (color >> 1) & 8355711;
		put_pixel(game, x, y, color);
		y++;
	}
	while (y < game->window.height)
	{
		put_pixel(game, x, y,
			game->textures.floor_rgb[0] << 16 | game->textures.floor_rgb[1] << 8 | game->textures.floor_rgb[2]);
		y++;
	}
}

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < game->window.width && y >= 0 && y < game->window.height)
	{
		dst = game->window.frame.img.addr + (y
				* game->window.frame.img.size_line + x
				* (game->window.frame.img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	render_frame(t_game *game)
{
	clear_image(game);
	cast_rays(game);
	update_game_state(game);
	mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
		game->window.frame.img.img, 0, 0);
	return (0);
}
