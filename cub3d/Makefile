####################################################
# DEFINITION :
NAME = cub3d
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = lib/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
INCLUDES = -I./includes -I$(MLX_DIR) -I$(LIBFT_DIR)

SRCES = srcs/main/cub3d.c srcs/parsing/stock_file.c srcs/get_next_line/get_next_line_utils.c \
srcs/get_next_line/get_next_line.c srcs/parsing/get_data.c srcs/parsing/get_map.c srcs/parsing/parsing.c \
srcs/parsing/utils_parsing.c srcs/parsing/parse_map.c srcs/parsing/parse_data.c srcs/player/move_player.c \
srcs/player/controls_player.c srcs/player/move_camera.c srcs/render/raycasting.c srcs/render/texture.c \
srcs/inits/init.c srcs/inits/exit.c

OBJECTS = $(SRCES:.c=.o)

####################################################
# RULES
all: $(MLX) $(LIBFT) $(NAME)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(LIBFT) $(MLX) -lXext -lX11 -lm

####################################################
# CLEAR/RESET
clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean re all fclean

####################################################
# PATTERN RULE TO COMPILE .c FILES TO .o FILES
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@