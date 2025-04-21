/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:38:10 by yamartin          #+#    #+#             */
/*   Updated: 2025/04/15 14:51:01 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

/* void	open_window(t_display *display)
{
	display->mlx_ptr = mlx_init();
	display->mlx_wind = mlx_new_window(display->mlx_ptr, 1920, 500, "cub3d");
	mlx_hook(display->mlx_wind, 17, 0, quit, display);
	mlx_hook(display->mlx_wind, 2, 1L << 0, keypress, display);
	mlx_loop(display->mlx_ptr);
	free_mlx(display);
} */

// TODO - Test - Minh - A REFAIRE
void	open_window(t_display *display)
{
	display->mlx_ptr = mlx_init();
	display->mlx_wind = mlx_new_window(display->mlx_ptr, 1920, 500, "cub3d");

	display->image.img = mlx_new_image(display->mlx_ptr, 1920, 500);
	display->image.addr = mlx_get_data_addr(display->image.img,
		&display->image.bits_per_pixel,
		&display->image.size_line,
		&display->image.endian);

	// Fond rouge
	draw_background(display, 0x00FF0000);
	mlx_put_image_to_window(display->mlx_ptr, display->mlx_wind, display->image.img, 0, 0);

	// mlx_loop_hook(win->mlx_ptr, render_loop, game);
	mlx_hook(display->mlx_wind, 17, 0, quit, display);
	mlx_hook(display->mlx_wind, 2, 1L << 0, keypress, display);
	mlx_loop(display->mlx_ptr);

	free_mlx(display);
}

int	keypress(int keycode, t_display *display)
{
	if (keycode == 65307)
		mlx_loop_end(display->mlx_ptr);
	return (0);
}

int	quit(t_display *display)
{
	mlx_loop_end(display->mlx_ptr);
	return (0);
}

void	free_mlx(t_display *display)
{
	mlx_clear_window(display->mlx_ptr, display->mlx_wind);
	mlx_destroy_window(display->mlx_ptr, display->mlx_wind);
	mlx_destroy_display(display->mlx_ptr);
	free(display->mlx_ptr);
}

void verLine(t_display *info, int x, int y1, int y2, int color)
{
    int y;
    
    y = y1;
    while (y <= y2)
    {
        mlx_pixel_put(info->mlx_ptr, info->mlx_wind, x, y, color);
        y++;
    }
}

// TODO - Test Minh
void	ft_draw_background(t_display *display, int color)
{
	int	x, y;

	y = 0;
	while (y < 500)
	{
		x = 0;
		while (x < 1920)
		{
			// Calcul de l'offset mémoire (chaque pixel est un int)
			*(int *)(display->image.addr + (y * display->image.size_line + x * (display->image.bits_per_pixel / 8))) = color;
			x++;
		}
		y++;
	}
}

void put_pixel(t_display *display, int x, int y, int color)
{
	if (x >= 0 && x < 1920 && y >= 0 && y < 500)
	{
		char *dst = display->image.addr + (y * display->image.size_line + x * (display->image.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void ft_draw_line(t_display *display, int x0, int y0, int x1, int y1, int color)
{
	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int err = dx + dy, e2;

	while (1)
	{
		put_pixel(display, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = 2 * err;
		if (e2 >= dy) { err += dy; x0 += sx; }
		if (e2 <= dx) { err += dx; y0 += sy; }
	}
}

void draw_player(t_display *display, t_player *player)
{
	int px = (int)(player->pos.x * 64); // 64 = taille d'une "case" de la carte
	int py = (int)(player->pos.y * 64);

	draw_square(display, px - 2, py - 2, 0x00FF0000); // carré rouge

	// Direction
	int dx = (int)((player->pos.x + player->dir.x) * 64);
	int dy = (int)((player->pos.y + player->dir.y) * 64);
	draw_line(display, px, py, dx, dy, 0x0000FF00); // ligne verte direction
}

void draw_square(t_display *display, int x, int y, int color)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			put_pixel(display, x + i, y + j, color);
		}
	}
}