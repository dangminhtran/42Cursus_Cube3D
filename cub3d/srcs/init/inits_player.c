#include "../cub3d.h"

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
		ft_init_coord(&game->player.plane, - ((double)game->window.width /
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

int	ft_init_player(t_game *game)
{
	set_dir_player(game, game->map.map[game->map.spawn.y][game->map.spawn.x]);
	game->map.map[game->map.spawn.y][game->map.spawn.x] = '0';
	ft_init_coord(&game->player.pos, game->map.spawn.x + 0.5,
		game->map.spawn.y + 0.5);
	game->player.speed = game->settings.move_speed; // TODO - comment recuperer ce speed ?
	game->player.rot_speed = game->settings.rot_speed; // TODO - comment recuperer ce rot_speed ?
	return (1);
}