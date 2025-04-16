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

void	open_window(t_display *display)
{
	display->mlx_ptr = mlx_init();
	display->mlx_wind = mlx_new_window(display->mlx_ptr, 1920, 500, "cub3d");
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