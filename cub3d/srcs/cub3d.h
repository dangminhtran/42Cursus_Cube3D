/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:05:34 by yamartin          #+#    #+#             */
/*   Updated: 2025/04/16 16:46:26 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

# include "../lib/libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>


# define M_UP				0x00001
# define M_DOWN				0x00002
# define M_LEFT				0x00004
# define M_RIGHT			0x00008

# define M_VIEW_UP			0x00010
# define M_VIEW_DOWN		0x00020
# define M_VIEW_LEFT		0x00040
# define M_VIEW_RIGHT		0x00080

typedef struct s_display // == t_window ?
{
	void		*mlx_ptr;
	void		*mlx_wind;
	int			player_posx;
	int			player_posy;
}				t_display;

typedef struct s_textures
{
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*floor_color;
	char		*ceiling_color;
	int			ceiling_rgb[3];
	int			floor_rgb[3];
	char		**textures;
}				t_textures;

typedef struct s_map_data
{
	char		**map_file;
	char		**map;
	char		**special_map;
	int			map_width;
	int			map_height;
	int			file_size;
	int			count;
	t_vector	spawn;
	t_textures	*textures;
}				t_map_data;


// Définition des directions
typedef struct s_vector
{
	int		x;
	int		y;
}	t_vector;

// Définition des coordonnées
typedef struct s_coord
{
	double		x;
	double		y;
}	t_coord;

// Définition de la fenêtre
typedef struct s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			height;
	int			width;
	t_frame		frame;
}	t_window;


typedef struct s_frame
{
	t_coord		ray_dir;
	t_vector	map;
	t_coord		side_dist;
	t_coord		delta_dist;
	t_coord		camera;
	t_vector	step;
	t_coord		wall;
	t_vector	mouse;
	int			hit;
	char		hit_value;
	int			side;
	double		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			color;
}	t_frame;

typedef struct s_player
{
	t_coord		pos;
	t_coord		dir;
	t_coord		plane;
	int			move;
	double		speed;
	double		rot_speed;
}	t_player;

typedef struct s_settings
{
	double		fov;
	double		move_speed;
	double		sprint_speed;
	double		rot_speed;
	double		cos_rot_speed;
	double		sin_rot_speed;
	double		cos_neg_rot_speed;
	double		sin_neg_rot_speed;
}	t_settings;

typedef struct s_game
{
	t_window			window;
	t_map_data			map;
	t_textures		textures;
	//		parsing;
	t_frame			frame;
	t_player		player;
	t_settings		settings;
}	t_game;


void			open_window(t_display *display);
int				quit(t_display *display);
int				keypress(int keycode, t_display *display);
void			free_mlx(t_display *display);
char			**ft_stock_file(char *name_file, char **tab);
int				ft_get_map_size(char *name_file);
int				is_empty_line(char *line);
void			get_map_width(t_map_data *map_data, int count, char **map);
int				get_only_map(t_map_data *map_data, int start_index);
int				get_textures(t_map_data *map_data);
int				parse_textures_lines(t_textures *textures);
int				general_parsing(t_map_data *map_data, char **av);
void			ft_free(char **map, int count);
void			ft_free_data(t_map_data *map_data);
int				check_map_char(char **map);
int				parse_map(t_map_data *map_data);
int				ft_strlen2(char *str);
void			init_data(t_map_data *map_data);
void			init_textures(t_textures *textures);
int				check_doubles(char **map);
void			get_special_map(t_map_data *map_data);
int				find_empty_area(t_map_data *map_data);
int				check_around(int i, int j, char **map);
int				ft_is_space(char c);
int				get_ceiling_rgb(t_textures *textures);
int				get_floor_rgb(t_textures *textures);
int				only_numbers_or_space(char *line);
int				is_valid_rgb(char *line);
int				line_counter(char **tableau);
void			get_player_pos(t_map_data *map_data, t_display *display);
int				is_valid_extension(char *str);

#endif
