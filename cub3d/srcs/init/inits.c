
#include "cub3d.h"

/**
 * @brief Initialise une structure de coordonnées t_coord. 
 * Pour la position du joueur & les directions de rayons.
 */
int	ft_init_coord(t_coord *coord, double x, double y)
{
	coord->x = x;
	coord->y = y;
	return (1);
}

/**
 * @brief Initialise une structure de coordonnées t_vector. 
 * Pour la direction du joueur & le pas de rayons (sur la grille).
 */
int	ft_init_vector(t_vector *vec, int x, int y)
{
	vec->x = x;
	vec->y = y;
	return (1);
}

// int	ft_init_image(t_game *game, t_image *img)
// {
// 	(void)game;
// 	img->img = NULL;
// 	img->addr = NULL;
// 	img->size.x = 0;
// 	img->size.y = 0;
// 	img->bits_per_pixel = 0;
// 	img->size_line = 0;
// 	img->endian = 0;
// 	return (1);
// }

// Initialise la fenêtre du jeu
// int	ft_init_window(t_game *game)
// {
// 	game->window.mlx_ptr = NULL;
// 	game->window.win_ptr = NULL;
// 	game->window.height = -1;
// 	game->window.width = -1;
// 	ft_init_image(game, &game->window.frame);
// 	return (1);
}

/**
 * @brief Initialise les champs pour le raycasting.
 * Infos sur le rayon projeté à l'écran
 */
// int	ft_init_frame(t_frame *frame)
// {
// 	ft_init_coord(&frame->ray_dir, 0, 0);
// 	ft_init_vector(&frame->map, 0, 0);
// 	ft_init_coord(&frame->side_dist, 0, 0);
// 	ft_init_coord(&frame->delta_dist, 0, 0);
// 	ft_init_vector(&frame->step, 0, 0);
// 	ft_init_coord(&frame->wall, 0, 0);
// 	frame->hit = 0;
// 	frame->hit_value = 0;
// 	frame->side = -1;
// 	frame->perp_wall_dist = 0;
// 	frame->line_height = 0;
// 	frame->draw_start = 0;
// 	frame->draw_end = 0;
// 	frame->color = 0;
// 	return (1);
// }

// TODO - A essayer init des structures avec (struct *){ 0 } pour gagner des lignes



