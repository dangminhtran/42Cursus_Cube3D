#include "../cub3d.h"

void	init_player(t_game *game)
{
	game->player.pos.x = game->map.spawn.y + 0.5;  // Centre de la cellule
	game->player.pos.y = game->map.spawn.x + 0.5;

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

	game->settings.move_speed = 0.05;
	game->settings.rot_speed = 0.03;
	
	// Valeurs trigos pour la vitesse de rotation
	game->settings.cos_rot_speed = cos(game->settings.rot_speed);
	game->settings.sin_rot_speed = sin(game->settings.rot_speed);
	game->settings.cos_neg_rot_speed = cos(-game->settings.rot_speed);
	game->settings.sin_neg_rot_speed = sin(-game->settings.rot_speed);
}

void	cast_rays(t_game *game)
{
	int x;
	
	x = 0;
	while (x < game->window.width)
	{
		// Calcul de la position et direction du rayon
		game->frame.camera.x = 2 * x / (double)game->window.width - 1;
		game->frame.ray_dir.x = game->player.dir.x + game->player.plane.x * game->frame.camera.x;
		game->frame.ray_dir.y = game->player.dir.y + game->player.plane.y * game->frame.camera.x;
		
		game->frame.map.x = (int)game->player.pos.x;
		game->frame.map.y = (int)game->player.pos.y;
	
		// Longueur du rayon de la position actuelle au prochain côté x ou y
		if (game->frame.ray_dir.x == 0)
			game->frame.delta_dist.x = 1e30; // Eviter la division par zéro
		else
			game->frame.delta_dist.x = fabs(1 / game->frame.ray_dir.x);
			
		if (game->frame.ray_dir.y == 0)
			game->frame.delta_dist.y = 1e30; 
		else
			game->frame.delta_dist.y = fabs(1 / game->frame.ray_dir.y);
		
		// Calcul du pas et de la distance initiale
		if (game->frame.ray_dir.x < 0)
		{
			game->frame.step.x = -1;
			game->frame.side_dist.x = (game->player.pos.x - game->frame.map.x) * game->frame.delta_dist.x;
		}
		else
		{
			game->frame.step.x = 1;
			game->frame.side_dist.x = (game->frame.map.x + 1.0 - game->player.pos.x) * game->frame.delta_dist.x;
		}
		
		if (game->frame.ray_dir.y < 0)
		{
			game->frame.step.y = -1;
			game->frame.side_dist.y = (game->player.pos.y - game->frame.map.y) * game->frame.delta_dist.y;
		}
		else
		{
			game->frame.step.y = 1;
			game->frame.side_dist.y = (game->frame.map.y + 1.0 - game->player.pos.y) * game->frame.delta_dist.y;
		}
		
		perform_dda(game);
		
		// Calculer la distance projetée sur la direction de la caméra
		if (game->frame.side == 0)
			game->frame.perp_wall_dist = (game->frame.side_dist.x - game->frame.delta_dist.x);
		else
			game->frame.perp_wall_dist = (game->frame.side_dist.y - game->frame.delta_dist.y);

		// Calculer la hauteur de la ligne à dessiner sur l'écran
		game->frame.line_height = (int)(game->window.height / game->frame.perp_wall_dist);
	
		// Calculer le pixel le plus bas et le plus haut à remplir dans la bande actuelle
		game->frame.draw_start = -game->frame.line_height / 2 + game->window.height / 2;
		if (game->frame.draw_start < 0)
			game->frame.draw_start = 0;
			
		game->frame.draw_end = game->frame.line_height / 2 + game->window.height / 2;
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
		// Sauter à la prochaine case de la carte, soit en x, soit en y
		if (game->frame.side_dist.x < game->frame.side_dist.y)
		{
			game->frame.side_dist.x += game->frame.delta_dist.x;
			game->frame.map.x += game->frame.step.x;
			game->frame.side = 0; // x-side hit
		}
		else
		{
			game->frame.side_dist.y += game->frame.delta_dist.y;
			game->frame.map.y += game->frame.step.y;
			game->frame.side = 1; // y-side hit
		}
		
		// Checker si on a touché un mur
		if (game->frame.map.y >= 0 && game->frame.map.x >= 0 && 
			game->frame.map.y < game->map.map_width && 
			game->frame.map.x < game->map.map_height)
		{
			if (game->map.map[game->frame.map.x][game->frame.map.y] == '1')
			{
				game->frame.hit = 1; // Hit a wall
				game->frame.hit_value = '1';
			}
		}
		else
		{
			// Si on sort de la carte, on considère que c'est un mur
			game->frame.hit = 1;
			game->frame.hit_value = '1';
		}
	}
}

void	draw_vertical_line(t_game *game, int x)
{
	int y;
	int color;

	// Choix de la couleur du mur en fonction de l'orientation (N, S, E, W)
	if (game->frame.side == 0)
	{
		if (game->frame.ray_dir.x > 0)
			color = 0x00EA9999; // Coté Est - Rose
		else
			color = 0x00B22222; // Côté Ouest - Rouge
	}
	else
	{
		if (game->frame.ray_dir.y > 0)
			color = 0x0090EE90; // Côté Sud - vert clair
		else
			color = 0x00006400; // Côté nord - vert foncé
	}
	
	// On divise la couleur par 2 pour l'assombrir
	if (game->frame.side == 1)
		color = (color >> 1) & 8355711;
	
	// Dessiner le plafond (haut de l'écran)
	y = 0;
	while (y < game->frame.draw_start)
	{
		put_pixel(game, x, y, game->textures.ceiling_rgb[0] << 16 | 
					game->textures.ceiling_rgb[1] << 8 | 
					game->textures.ceiling_rgb[2]);
		y++;
	}
	
	// Dessiner le mur (partie centrale)
	while (y < game->frame.draw_end)
	{
		put_pixel(game, x, y, color);
		y++;
	}
	
	// Dessiner le sol (bas de l'écran)
	while (y < game->window.height)
	{
		put_pixel(game, x, y, game->textures.floor_rgb[0] << 16 | 
					game->textures.floor_rgb[1] << 8 | 
					game->textures.floor_rgb[2]);
		y++;
	}
}

void	put_pixel(t_game *game, int x, int y, int color)
{
	char *dst;
	
	if (x >= 0 && x < game->window.width && y >= 0 && y < game->window.height)
	{
		dst = game->window.frame.img.addr + (y * game->window.frame.img.size_line + 
				x * (game->window.frame.img.bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

int	render_frame(t_game *game)
{
	clear_image(game);
	cast_rays(game);
	mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr, 
							game->window.frame.img.img, 0, 0);
	return (0);
}

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
