#include "../cub3d.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307) // ESC
	{
		mlx_loop_end(game->window.mlx_ptr);
		return (0);
	}
	if (keycode == 119)
		move_forward(game);
	if (keycode == 115)
		move_backward(game);
	if (keycode == 97 || keycode == 65361)
		rotate_left(game);
	if (keycode == 100 || keycode == 65363)
		rotate_right(game);
	return (0);
}

// TODO - Ne marche pas
void	move_forward(t_game *game)
{
	double new_x = game->player.pos.x + game->player.dir.x * game->settings.move_speed;
	double new_y = game->player.pos.y + game->player.dir.y * game->settings.move_speed;
	
	//  Check si c'est un mur
	if (is_valid_position(game, new_x, game->player.pos.y))
		game->player.pos.x = new_x;
	if (is_valid_position(game, game->player.pos.x, new_y))
		game->player.pos.y = new_y;
}

void	move_backward(t_game *game)
{
	double new_x = game->player.pos.x - game->player.dir.x * game->settings.move_speed;
	double new_y = game->player.pos.y - game->player.dir.y * game->settings.move_speed;
	
	// Check si c'est un mur
	if (is_valid_position(game, new_x, game->player.pos.y))
		game->player.pos.x = new_x;
	if (is_valid_position(game, game->player.pos.x, new_y))
		game->player.pos.y = new_y;
}

void	rotate_left(t_game *game)
{
	// Rotation de la direction selon la matrice de rotation:
	// [ cos(a) -sin(a) ]
	// [ sin(a)  cos(a) ]
	double old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * game->settings.cos_rot_speed - 
						game->player.dir.y * game->settings.sin_rot_speed;
	game->player.dir.y = old_dir_x * game->settings.sin_rot_speed + 
						game->player.dir.y * game->settings.cos_rot_speed;
	
	// Rotation de la caméra
	double old_plane_x = game->player.plane.x;
	game->player.plane.x = game->player.plane.x * game->settings.cos_rot_speed - 
						game->player.plane.y * game->settings.sin_rot_speed;
	game->player.plane.y = old_plane_x * game->settings.sin_rot_speed + 
						game->player.plane.y * game->settings.cos_rot_speed;
}

void	rotate_right(t_game *game)
{
	// Rotation de la direction selon la matrice de rotation avec des angles négatifs
	// [ cos(-a) -sin(-a) ]
	// [ sin(-a)  cos(-a) ]
	double old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * game->settings.cos_neg_rot_speed - 
						game->player.dir.y * game->settings.sin_neg_rot_speed;
	game->player.dir.y = old_dir_x * game->settings.sin_neg_rot_speed + 
						game->player.dir.y * game->settings.cos_neg_rot_speed;
	
	// Rootation de la caméra
	double old_plane_x = game->player.plane.x;
	game->player.plane.x = game->player.plane.x * game->settings.cos_neg_rot_speed - 
						game->player.plane.y * game->settings.sin_neg_rot_speed;
	game->player.plane.y = old_plane_x * game->settings.sin_neg_rot_speed + 
						game->player.plane.y * game->settings.cos_neg_rot_speed;
}

int	is_valid_position(t_game *game, double x, double y)
{
	int map_x = (int)x;
	int map_y = (int)y;
	
	// Si la position est en dehors de la carte
	if (map_x < 0 || map_y < 0 || map_x >= game->map.map_height || map_y >= game->map.map_width)
		return (0);
	
	// Si la position est sur un mur
	if (game->map.map[map_x][map_y] == '1')
		return (0);
	
	// POur éviter de se coller aux murs
	double buffer = 0.2;
	
	// Verifier si la position est proche d'un mur
	if (fabs(x - map_x) < buffer || fabs(x - (map_x + 1)) < buffer ||
		fabs(y - map_y) < buffer || fabs(y - (map_y + 1)) < buffer)
	{
		// Est-ce que la position est proche d'un mur ?
		if ((map_x + 1 < game->map.map_height && game->map.map[map_x + 1][map_y] == '1' && fabs(x - (map_x + 1)) < buffer) ||
			(map_x - 1 >= 0 && game->map.map[map_x - 1][map_y] == '1' && fabs(x - map_x) < buffer) ||
			(map_y + 1 < game->map.map_width && game->map.map[map_x][map_y + 1] == '1' && fabs(y - (map_y + 1)) < buffer) ||
			(map_y - 1 >= 0 && game->map.map[map_x][map_y - 1] == '1' && fabs(y - map_y) < buffer))
		{
			return (0);
		}
	}
	return (1);
}
