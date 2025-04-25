#include "../cub3d.h"

// int	handle_keypress(int keycode, t_game *game)
// {
// 	if (keycode == 65307)
// 	{
// 		mlx_loop_end(game->window.mlx_ptr);
// 		return (0);
// 	}
// 	if (keycode == XK_w || keycode == XK_W)
// 		move_forward(game);
// 	if (keycode == XK_s || keycode == XK_S)w
// 		move_backward(game);
// 	if (keycode == XK_d || keycode == XK_D)
// 		move_left(game);
// 	if (keycode == XK_a || keycode == XK_A)
// 		move_right(game);
// 	if (keycode == XK_Right)
// 		rotate_left(game);
// 	if (keycode == XK_Left)
// 		rotate_right(game);

// 	return (0);
// }

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

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos.x + game->player.dir.x * game->settings.move_speed;
	new_y = game->player.pos.y + game->player.dir.y * game->settings.move_speed;
	//  Check si c'est un mur
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
	// Check si c'est un mur
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

	// Perpendiculaire à la direction (gauche)
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

	// Perpendiculaire à la direction (droite)
	perp_x = game->player.dir.y;
	perp_y = -game->player.dir.x;
	new_x = game->player.pos.x + perp_x * game->settings.move_speed;
	new_y = game->player.pos.y + perp_y * game->settings.move_speed;
	if (is_valid_position(game, new_x, game->player.pos.y))
		game->player.pos.x = new_x;
	if (is_valid_position(game, game->player.pos.x, new_y))
		game->player.pos.y = new_y;
}

void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	// Rotation de la direction selon la matrice de rotation:
	// [ cos(a) -sin(a) ]
	// [ sin(a)  cos(a) ]
	old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * game->settings.cos_rot_speed
		- game->player.dir.y * game->settings.sin_rot_speed;
	game->player.dir.y = old_dir_x * game->settings.sin_rot_speed
		+ game->player.dir.y * game->settings.cos_rot_speed;
	// Rotation de la caméra
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

	// Rotation de la direction selon la matrice de rotation avec des angles négatifs
	// [ cos(-a) -sin(-a) ]
	// [ sin(-a)  cos(-a) ]
	old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * game->settings.cos_neg_rot_speed
		- game->player.dir.y * game->settings.sin_neg_rot_speed;
	game->player.dir.y = old_dir_x * game->settings.sin_neg_rot_speed
		+ game->player.dir.y * game->settings.cos_neg_rot_speed;
	// Rootation de la caméra
	old_plane_x = game->player.plane.x;
	game->player.plane.x = game->player.plane.x
		* game->settings.cos_neg_rot_speed - game->player.plane.y
		* game->settings.sin_neg_rot_speed;
	game->player.plane.y = old_plane_x * game->settings.sin_neg_rot_speed
		+ game->player.plane.y * game->settings.cos_neg_rot_speed;
}

int	is_valid_position(t_game *game, double x, double y)
{
	int		map_x;
	int		map_y;
	double	buffer;

	map_x = (int)x;
	map_y = (int)y;
	// Si la position est en dehors de la carte
	if (map_x < 0 || map_y < 0 || map_x >= game->map.map_height
		|| map_y >= game->map.map_width)
		return (0);
	// Si la position est sur un mur
	if (game->map.map[map_x][map_y] == '1')
		return (0);
	// POur éviter de se coller aux murs
	buffer = 0.2;
	// Verifier si la position est proche d'un mur
	if (fabs(x - map_x) < buffer || fabs(x - (map_x + 1)) < buffer || fabs(y
			- map_y) < buffer || fabs(y - (map_y + 1)) < buffer)
	{
		// Est-ce que la position est proche d'un mur ?
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
