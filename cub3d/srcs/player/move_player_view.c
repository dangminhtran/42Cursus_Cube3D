#include "cub3d.h"

/**
 * @brief Fait tourner la caméra vers la gauche
 * Rotation dans le sens inverse des aiguilles d'une montre sur les vecteurs direction dir et plan plane
 * 
 * @details
 * - Utilise les fonctions cos et sin pour une rotation 2D :
 * x′ = x⋅cos(θ)−y⋅sin(θ)
 * y′ = x⋅sin(θ)+y⋅cos(θ)
 * 
 */
int	ft_move_player_view_left(t_game *game, t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir.x;
	old_plane_x = player->plane.x;
	player->dir.x = (player->dir.x * game->settings.cos_neg_rot_speed) \
		- (player->dir.y * game->settings.sin_neg_rot_speed);
	player->dir.y = (old_dir_x * game->settings.sin_neg_rot_speed) \
		+ (player->dir.y * game->settings.cos_neg_rot_speed);
	player->plane.x = (player->plane.x * game->settings.cos_neg_rot_speed) \
		- (player->plane.y * game->settings.sin_neg_rot_speed);
	player->plane.y = (old_plane_x * game->settings.sin_neg_rot_speed) \
		+ (player->plane.y * game->settings.cos_neg_rot_speed);
	return (1);
}

/**
 * @brief Fait tourner la caméra vers la droite
 * Rotation dans le sens des aiguilles d'une montre sur les vecteurs direction dir et plan plane
 * 
 * @details
 * On utilise cos_rot_speed et sin_rot_speed pour tourner dans l’autre sens.
 * Change la direction du regard sans changer la position du joueur.
 *
 */
int	ft_move_player_view_right(t_game *game, t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir.x;
	old_plane_x = player->plane.x;
	player->dir.x = (player->dir.x * game->settings.cos_rot_speed) \
		- (player->dir.y * game->settings.sin_rot_speed);
	player->dir.y = (old_dir_x * game->settings.sin_rot_speed) \
		+ (player->dir.y * game->settings.cos_rot_speed);
	player->plane.x = (player->plane.x * game->settings.cos_rot_speed) \
		- (player->plane.y * game->settings.sin_rot_speed);
	player->plane.y = (old_plane_x * game->settings.sin_rot_speed) \
		+ (player->plane.y * game->settings.cos_rot_speed);
	return (1);
}

int	ft_move_player_view_up(t_player *player)
{
	(void)player;
	return (1);
}

int	ft_move_player_view_down(t_player *player)
{
	(void)player;
	return (1);
}