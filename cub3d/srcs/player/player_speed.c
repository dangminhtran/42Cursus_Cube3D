#include "../cub3d.h"

/**
 * @brief Calcule une vitesse en fonction du nombre de directions actives,
 *  en réduisant la vitesse si le joueur se déplace en diagonale ou dans plusieurs directions.
 * 
 * @param
 * t_game *game : le contexte global du jeu // pas utilisé !!
 * t_player *player : infos sur le joueur, notamment les directions pressées.
 * double *speed : pointeur vers la vitesse.
 */
void	ft_speed(t_game *game, t_player *player, double *speed)
{
	int		moves;

	moves = 0;
	*speed = player->speed;
	if (player->move & M_UP)
		moves++;
	if (player->move & M_DOWN)
		moves++;
	if (player->move & M_LEFT)
		moves++;
	if (player->move & M_RIGHT)
		moves++;
    // Si deux touches opposées sont pressées, on annule le mouvement
	if ((player->move & M_UP) && (player->move & M_DOWN))
		moves -= 2;
	if ((player->move & M_LEFT) && (player->move & M_RIGHT))
		moves -= 2;
    // Diviser la vitesse pour éviter un déplacement plus rapide en diagonale
	if (moves > 1)
    // Si + de deux directions alors division ajustée par (moves - 1)
		*speed /= sqrt(2) * (moves - 1);
	return ;
}
