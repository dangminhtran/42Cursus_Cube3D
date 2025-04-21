#include "../cub3d.h"

/**
 * @brief DDA : pour détecter les collisions avec les murs
 * 
 * @details
 * - On avance dans la direction du rayon jusqu'à ce qu'on touche un mur
 * - On utilise la distance entre le joueur et le mur pour calculer la distance
 * side_dist stocke la distance actuelle jusqu’au prochain bord de case en X et Y.
 * delta_dist est la distance entre deux cases consécutives dans cette direction.
 * Incrémentation de map.x ou map.y selon la direction où le rayon va toucher en premier.
 * side : si l’impact est vertical (0) ou horizontal (1)
 * 
 */
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

/**
 * @brief Récupère la valeur du mur touché
 * 
 * @details
 * - Si le rayon sort de la carte, on marque le hit
 * - Sinon, on récupère la valeur du mur touché (hit_value)
 * 
 * @param game Le jeu en cours.
 * @return int 1 si tout va bien
 */
static int	get_hit_value(t_game *game)
{
	if ((game->frame.step.x < 0 && game->frame.map.x < 0)
		|| (game->frame.step.y < 0 && game->frame.map.y < 0)
		|| ((game->frame.map.x >= game->map.map_width) && game->frame.step.x >= 0)
		|| ((game->frame.map.y >= game->map.map_height) && game->frame.step.y >= 0))
	{
		game->frame.hit = 1;
	}
	else if (game->frame.map.x >= 0 && game->frame.map.y >= 0
		&& game->frame.map.x < game->map.map_width
			&& game->frame.map.y < game->map.map_height)
		game->frame.hit_value =
			game->map.map[game->frame.map.y][game->frame.map.x];
	return (1);
}

/**
 * @brief Vérifie si le mur touché est un mur solide
 * 
 * @details
 * - Si le mur est solide (1), on marque le hit
 * - Sinon, on marque le hit à 0
 */
static int	check_hit(t_game *game)
{
	if (game->frame.hit_value == '1')
		game->frame.hit = 1;
	else if (game->frame.hit_value == '0')
		game->frame.hit = 0;
	return (1);
}

/**
 * @brief Fonction principale de raycasting
 * Effecteur une boucle DDA jusqu'à qu'un mur soit trouvé
 * Avance d'une case à la fois get_next_square
 * Récupère la valeur du mur touché get_hit_value
 * Vérifie si le mur est solide check_hit et stoppe.
 * 
 */
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

/**
 * @brief Initialise les valeurs pour le DDA
 * Etape avant ft_raycasting_dda
 * 
 * @details
 * step: indique si le rayon va à gauche ou à droite, en haut ou en bas
 * side_dist: distance jusqu'au prochain bord de case
 */
void	ft_raycasting_step(t_game *game)
{
	// X direction
	if (game->frame.ray_dir.x < 0)
	{
		game->frame.step.x = -1;
		game->frame.side_dist.x = (game->player.pos.x - game->frame.map.x)
			* game->frame.delta_dist.x;
	}
	else
	{
		game->frame.step.x = 1;
		game->frame.side_dist.x = (game->frame.map.x + 1.0 - game->player.pos.x)
			* game->frame.delta_dist.x;
	}

	// Y direction
	if (game->frame.ray_dir.y < 0)
	{
		game->frame.step.y = -1;
		game->frame.side_dist.y = (game->player.pos.y - game->frame.map.y)
			* game->frame.delta_dist.y;
	}
	else
	{
		game->frame.step.y = 1;
		game->frame.side_dist.y = (game->frame.map.y + 1.0 - game->player.pos.y)
			* game->frame.delta_dist.y;
	}
}

/**
 * @brief Calcule la coordonné exacte d'impact sur la texture murale
 * 
 * @details
 * wall.x : pour choisir le bon point d'échantillonnage de la texture
 * on garde la fraction déciamle pour connaitre la mosition sur le mur (entre 0.0 et 1.0)
 */
static int	mini_ft_raycasting_wall(t_game *game)
{
	if (game->frame.side == 0)
		game->frame.wall.x = game->player.pos.y
			+ game->frame.perp_wall_dist * game->frame.ray_dir.y;
	else
		game->frame.wall.x = game->player.pos.x
			+ game->frame.perp_wall_dist * game->frame.ray_dir.x;
	game->frame.wall.x -= (int)game->frame.wall.x;
	return (1);
}

/**
 * @brief Calcule la distance réelle entre le joueur et le mur (per_wall_dist)
 * Déduit la hauteur du mur à dessiner (line_height)
 * draw_end / draw_start : définit les coordonnées Y du trait vertical à dessiner sur la colonne de pixel !!
 * Récupère la position d'impact sur la texture (mini_ft_raycasting_wall)
 */
int	ft_raycasting_wall(t_game *game)
{
	if (game->frame.side == 0)
		game->frame.perp_wall_dist = game->frame.side_dist.x
			- game->frame.delta_dist.x;
	else if (game->frame.side == 1)
		game->frame.perp_wall_dist = game->frame.side_dist.y
			- game->frame.delta_dist.y;
	game->frame.line_height = (int)(game->window.height
		/ game->frame.perp_wall_dist);
	game->frame.draw_start = (int)(-game->frame.line_height / 2
		+ game->window.height / 2);
	if (game->frame.draw_start < 0)
		game->frame.draw_start = 0;
	if (game->frame.draw_start > game->window.height)
		game->frame.draw_start = game->window.height;
	game->frame.draw_end = (int)(game->frame.line_height / 2
		+ game->window.height / 2);
	if (game->frame.draw_end > game->window.height)
		game->frame.draw_end = game->window.height;
	if (game->frame.draw_end < 0)
		game->frame.draw_end = 0;
	return (mini_ft_raycasting_wall(game));
}