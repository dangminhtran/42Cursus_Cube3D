####################################################
# DEFINITION :

NAME = cub3d
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LIBFT = lib/libft
FT_LIBFT = lib/libft/libft.a
MLX = lib/minilibx-linux/libmlx_Linux.a
SRCES = srcs/main/cub3d.c srcs/exec/display.c srcs/parsing/stock_file.c srcs/get_next_line/get_next_line_utils.c \
srcs/get_next_line/get_next_line.c srcs/parsing/get_data.c srcs/parsing/get_map.c srcs/parsing/parsing.c \
srcs/parsing/utils_parsing.c srcs/parsing/parse_map.c srcs/parsing/parse_data.c \

OBJECTS = $(SRCES:.c=.o)

####################################################
# RULES

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(FT_LIBFT) $(MLX) -lXext -lX11

####################################################
# CLEAR/RESET

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: clean re all fclean

####################################################
# PATTERN RULE TO COMPILE .c FILES TO .o FILES

# Generic rule to compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I./lib/minilibx-linux/