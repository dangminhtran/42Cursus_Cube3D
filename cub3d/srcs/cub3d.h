/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamartin <yamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:05:34 by yamartin          #+#    #+#             */
/*   Updated: 2025/04/25 16:50:08 by yamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

# include "../lib/libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>

typedef struct s_vector
{
	int			x;
	int			y;
}				t_vector;

typedef struct s_coord
{
	double		x;
	double		y;
}				t_coord;

typedef struct s_image
{
	void		*img;
	char		*addr;
	t_vector	size;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_image;

typedef struct s_frame
{
	t_coord ray_dir;       // direction of the ray
	t_vector map;          // position on the map grid
	t_coord side_dist;     // distance to next x or y side
	t_coord delta_dist;    // distance between sides
	t_vector step;         // step direction (either 1 or -1)
	double perp_wall_dist; // perpendicular distance to the wall
	int side;              // was a NS or EW wall hit?
	int hit;               // was a wall hit?
	char hit_value;        // what was hit
	int line_height;       // height of the wall slice
	int draw_start;        // where to start drawing the wall
	int draw_end;          // where to end drawing the wall
	t_coord camera;        // camera plane coordinates
	t_image img;           // image for the current frame
}				t_frame;

typedef struct s_window
{
	void *mlx_ptr;   // MLX pointer
	void *win_ptr;   // Window pointer
	int width;       // Window width
	int height;      // Window height
	t_frame frame;   // Frame data
	int player_posx; // Player position X (from t_display)
	int player_posy; // Player position Y (from t_display)
}				t_window;

typedef struct s_player
{
	t_coord pos;   // Player position
	t_coord dir;   // Direction vector
	t_coord plane; // Camera plane
}				t_player;

typedef struct s_settings
{
	double move_speed;        // Movement speed
	double rot_speed;         // Rotation speed
	double cos_rot_speed;     // Precalculated cosine of rotation speed
	double sin_rot_speed;     // Precalculated sine of rotation speed
	double cos_neg_rot_speed; // Precalculated cosine of negative rotation speed
	double sin_neg_rot_speed; // Precalculated sine of negative rotation speed
}				t_settings;

typedef struct s_textures
{
	char **textures;     // Array of raw texture lines from map file
	char *no_texture;    // North texture path
	char *so_texture;    // South texture path
	char *we_texture;    // West texture path
	char *ea_texture;    // East texture path
	char *floor_color;   // Floor color string
	char *ceiling_color; // Ceiling color string

	char *north_path;   // Path to north texture
	char *south_path;   // Path to south texture
	char *west_path;    // Path to west texture
	char *east_path;    // Path to east texture
	int floor_rgb[3];   // Floor RGB values
	int ceiling_rgb[3]; // Ceiling RGB values

	t_image north_img; // North texture image
	t_image south_img; // South texture image
	t_image east_img;  // East texture image
	t_image west_img;  // West texture image
	int tex_width;     // Width of textures
	int tex_height;    // Height of textures
}				t_textures;

typedef struct s_map_data
{
	char **map;           // 2D map array
	char **map_file;      // Raw map file content
	char **special_map;   // Map with borders for validation
	int map_width;        // Map width
	int map_height;       // Map height
	int file_size;        // File size
	int count;            // Texture count
	t_vector spawn;       // Player spawn position
	t_textures *textures; // Textures data
}				t_map_data;

typedef struct s_keys
{
	int forward;   // W
	int backward;  // S
	int left;      // A
	int right;     // D
	int rot_left;  // Flèche gauche
	int rot_right; // Flèche droite
}				t_keys;

typedef struct s_game
{
	t_window	window;
	t_frame		frame;
	t_map_data	map;
	t_player	player;
	t_settings	settings;
	t_keys		keys;
	t_textures	textures;
}				t_game;

/* cub3d.c */
void			init_game(t_game *game);
void			setup_hooks(t_game *game);
int				close_window(t_game *game);
void			exit_error(t_game *game, char *message);
void			cleanup_game(t_game *game);
void			get_player_spawn(t_game *game);

/* move_player.c */
int				handle_keypress(int keycode, t_game *game);
void			move_forward(t_game *game);
void			move_backward(t_game *game);
void			move_left(t_game *game);
void			move_right(t_game *game);
void			rotate_left(t_game *game);
void			rotate_right(t_game *game);
int				is_valid_position(t_game *game, double x, double y);
int				handle_keyrelease(int keycode, t_game *game);
void			update_game(t_game *game);
void			update_game_state(t_game *game);

/* raycasting.c */
void			init_player(t_game *game);
void			cast_rays(t_game *game);
void			perform_dda(t_game *game);
void			draw_vertical_line(t_game *game, int x);
void			put_pixel(t_game *game, int x, int y, int color);
int				render_frame(t_game *game);
void			clear_image(t_game *game);

/* texture.c */
void			setup_texture_paths(t_textures *textures);
void			load_textures(t_game *game);
int				get_texture_color(t_image *img, int x, int y);
void			cleanup_textures(t_game *game);
void			print_texture_paths(t_textures *textures);

/* stock_file.c */
int				ft_get_map_size(char *path);
char			**ft_stock_file(char *path, char **map);

/* get_map.c */
int				get_only_map(t_map_data *map_data, int start_index);
void			get_map_width(t_map_data *map_data, int count, char **map);
void			get_special_map(t_map_data *map_data);

/* get_data.c */
int				get_textures(t_map_data *map_data);
int				line_counter(char **tableau);
void			get_player_pos(t_map_data *map_data, t_window *window);

/* parse_data.c */
char			*trim_path(char *path);
int				parse_textures_lines(t_textures *textures);
int				ft_is_space(char c);
int				get_ceiling_rgb(t_textures *textures);
int				get_floor_rgb(t_textures *textures);
int				is_valid_rgb(char *line);

/* parse_map.c */
int				check_map_char(char **map);
int				check_doubles(char **map);
int				find_empty_area(t_map_data *map_data);
int				check_around(int i, int j, char **map);
int				parse_map(t_map_data *map_data);

/* parsing.c */
int				general_parsing(t_map_data *map_data, char **av);
int				is_valid_extension(char *str);

/* utils_parsing.c */
int				is_empty_line(char *line);
void			ft_free(char **map, int count);
void			ft_free_data(t_map_data *map_data);
int				ft_strlen2(char *str);
void			init_data(t_map_data *map_data);
void			init_textures(t_textures *textures);

// PAS UTILISES - TODO - A MERGE
void			open_window(t_window *window);
int				quit(t_window *window);
int				keypress(int keycode, t_window *window);
void			free_mlx(t_window *window);

#endif
