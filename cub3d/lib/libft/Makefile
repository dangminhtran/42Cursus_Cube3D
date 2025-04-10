####################################################
# DEFINITION :

NAME = libft.a
CC = clang
FLAGS = -Wall -Werror -Wextra

SRCES = \
		ft_atoi.c ft_memchr.c ft_split.c ft_strncmp.c \
		ft_bzero.c ft_memcmp.c ft_strchr.c ft_strnstr.c \
		ft_calloc.c ft_memcpy.c ft_strdup.c ft_strtrim.c \
		ft_isalnum.c ft_memmove.c ft_striteri.c ft_substr.c \
		ft_isalpha.c ft_memset.c ft_strjoin.c ft_tolower.c \
		ft_isascii.c ft_putchar_fd.c ft_strlcat.c ft_toupper.c \
		ft_isdigit.c ft_putendl_fd.c  ft_strlcpy.c ft_isprint.c ft_strrchr.c \
		ft_putnbr_fd.c ft_strlen.c ft_itoa.c ft_putstr_fd.c ft_strmapi.c
BONUSSRCES = \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstadd_back.c

OBJECTS = $(SRCES:.c=.o)
BONUSOBJECTS = $(BONUSSRCES:.c=.o)
####################################################
#EXECUTION

all: $(NAME)

$(NAME): $(OBJECTS)
			$(AR) -r $(NAME) $?

bonus: $(OBJECTS) $(BONUSOBJECTS)
			$(AR) -r $(NAME) $?

%.o: %.c
		$(CC) -c $(FLAGS) $<
####################################################
#CLEAR/RESET
clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: clean re all bonus fclean
