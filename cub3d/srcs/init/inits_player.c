#include "../cub3d.h"

/**
 * @brief A cause de la norme 42.
 * Ajuste le vecteur plan de caméra (player.plane)
 * pour qu'il soit perpendiculaire au vecteur direction du joueur (player.dir)
 * Le plan de caméra permet de calculer les extrémités du champ de vision pour générer les rayons.
 * Si mal initialisé, l'affichage sera distordu.
 * 
 * @details
 * - Si la direction du joueur est (0, 0), on initialise le plan de caméra à (0.5, 0) ou (0, -0.5)
 * - Si le plan de caméra est entre 0 et 0.5, on l'ajuste à (1 - plan.x, plan.y) ou (plan.x, 1 - plan.y)
 * - Si le plan de caméra est entre 0 et 0.5, on l'ajuste à (plan.x, 1 - plan.y) ou (1 - plan.x, plan.y)
 */
static int	mini_set_dir_player(t_game *game, char c)
{
	(void)c;
	if (!game->player.dir.x && !game->player.plane.x)
		game->player.plane.x = 0.5 * game->player.dir.y;
	if (!game->player.dir.y && !game->player.plane.y)
		game->player.plane.y = -0.5 * game->player.dir.x;
	if (game->player.plane.x > 0 && game->player.plane.x < 0.5)
		game->player.plane.x = 1 - game->player.plane.x;
	if (game->player.plane.y > 0 && game->player.plane.y < 0.5)
		game->player.plane.y = 1 - game->player.plane.y;
	return (1);
}

/**
 * @brief Initialise la direction du joueur et le plan de caméra.
 * Le plan de caméra est perpendiculaire à la direction du joueur.
 * La direction du joueur est déterminée par le caractère dans la carte (N, S, E, W).
 * Le plan de caméra est ajusté pour être perpendiculaire à la direction du joueur.
 * Baser plane sur le ratio écran permet un FOV constant, même si la fenêtre est redimensionnée.
 * 
 * @details
 * - N : direction vers le haut (0, -1), plan de caméra (width/height, 0)
 * - S : direction vers le bas (0, 1), plan de caméra (-width/height, 0)
 * - E : direction vers la droite (1, 0), plan de caméra (0, width/height)
 * - W : direction vers la gauche (-1, 0), plan de caméra (0, -width/height)
 */
static int	set_dir_player(t_game *game, char c)
{
	if (ft_uppercase_char(c) == 'N')
	{
		ft_init_coord(&game->player.dir, 0, -1);
		ft_init_coord(&game->player.plane, ((double)game->window.width /
			(double)game->window.height), 0);
	}
	else if (ft_uppercase_char(c) == 'S')
	{
		ft_init_coord(&game->player.dir, 0, 1);
		ft_init_coord(&game->player.plane, -((double)game->window.width /
			(double)game->window.height), 0);
	}
	else if (ft_uppercase_char(c) == 'E')
	{
		ft_init_coord(&game->player.dir, 1, 0);
		ft_init_coord(&game->player.plane, 0, ((double)game->window.width /
			(double)game->window.height));
	}
	else if (ft_uppercase_char(c) == 'W')
	{
		ft_init_coord(&game->player.dir, -1, 0);
		ft_init_coord(&game->player.plane, 0, -((double)game->window.width /
			(double)game->window.height));
	}
	return (mini_set_dir_player(game, c));
}

/**
 * @brief Initialise la position du joueur et sa vitesse.
 * La position du joueur est initialisée à la position de spawn dans la carte.
 * La vitesse du joueur est initialisée à la vitesse de mouvement définie dans les paramètres.
 * 
 * @details
 * - La position du joueur est initialisée à (x + 0.5, y + 0.5) pour le centrer sur le carré de la carte.
 * - La vitesse de mouvement est initialisée à la vitesse de mouvement définie dans les paramètres.
 */
int	ft_init_player(t_game *game)
{
	set_dir_player(game,
		game->map.map[game->map.spawn.y][game->map.spawn.x]);
	game->map.map[game->map.spawn.y][game->map.spawn.x] = '0';
	ft_init_coord(&game->player.pos, game->map.spawn.x + 0.5,
		game->map.spawn.y + 0.5);
	game->player.speed = game->settings.move_speed;
	game->player.rot_speed = game->settings.rot_speed;
	return (1);
}