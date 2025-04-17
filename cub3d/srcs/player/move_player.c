#include "cub3d.h"

// Test d'une fonction is_blocking
void	is_blocking(t_game *game, t_coord *pos)
{
	if (pos->x < 0 || pos->x >= game->map.map_width|| pos->y < 0 \
		|| pos->y >= game->map.map_height)
	{
		pos->x = game->player.pos.x;
		pos->y = game->player.pos.y;
	}
	else if (game->map.map[(int)pos->y][(int)pos->x] == '1')
	{
		if (game->map.map[(int)pos->y][(int)game->player.pos.x] == '1')
			pos->y = game->player.pos.y;
		if (game->map.map[(int)game->player.pos.y][(int)pos->x] == '1')
			pos->x = game->player.pos.x;
		if (game->map.map[(int)pos->y][(int)pos->x] == '1')
		{
			pos->x = game->player.pos.x;
			pos->y = game->player.pos.y;
		}
	}
}

static int	ft_move_player_up(t_game *game, t_player *player, double speed)
{
	t_coord	new_pos;

	new_pos.x = player->pos.x + player->dir.x * speed;
	new_pos.y = player->pos.y + player->dir.y * speed;
	is_blocking(game, &new_pos);
	player->pos.x = new_pos.x;
	player->pos.y = new_pos.y;
	return (1);
}

static int	ft_move_player_down(t_game *game, t_player *player, double speed)
{
	t_coord	new_pos;

	new_pos.x = player->pos.x - player->dir.x * speed;
	new_pos.y = player->pos.y - player->dir.y * speed;
	is_blocking(game, &new_pos);
	player->pos.x = new_pos.x;
	player->pos.y = new_pos.y;
	return (1);
}

static int	ft_move_player_left(t_game *game, t_player *player, double speed)
{
	t_coord	new_pos;

	new_pos.x = player->pos.x + player->dir.y * speed;
	new_pos.y = player->pos.y - player->dir.x * speed;
	is_blocking(game, &new_pos);
	player->pos.x = new_pos.x;
	player->pos.y = new_pos.y;
	return (1);
}

static int	ft_move_player_right(t_game *game, t_player *player, double speed)
{
	t_coord	new_pos;

	new_pos.x = player->pos.x - player->dir.y * speed;
	new_pos.y = player->pos.y + player->dir.x * speed;
	is_blocking(game, &new_pos);
	player->pos.x = new_pos.x;
	player->pos.y = new_pos.y;
	return (1);
}

int	ft_move_player(t_game *game, t_player *player)
{
	double	speed;

	ft_move_speed(game, player, &speed);
	if (player->move & M_UP)
		ft_move_player_up(game, player, speed);
	if (player->move & M_DOWN)
		ft_move_player_down(game, player, speed);
	if (player->move & M_LEFT)
		ft_move_player_left(game, player, speed);
	if (player->move & M_RIGHT)
		ft_move_player_right(game, player, speed);
	if (player->move & M_VIEW_LEFT)
		ft_move_player_view_left(game, player);
	if (player->move & M_VIEW_RIGHT)
		ft_move_player_view_right(game, player);
	if (player->move & M_VIEW_UP)
		ft_move_player_view_up(player);
	if (player->move & M_VIEW_DOWN)
		ft_move_player_view_down(player);
	return (1);
}