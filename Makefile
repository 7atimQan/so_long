NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR    = libft
PRINTF_DIR   = ft_printf

LIBFT    = $(LIBFT_DIR)/libft.a
PRINTF   = $(PRINTF_DIR)/libftprintf.a

SRCS = map_pars.c map_utils.c map_utils2.c render_map.c main.c move_player.c\
       gnl/get_next_line.c gnl/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

MLX = -L/home/hqannouc/minilibx-linux -lmlx -lX11 -lXext

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX) $(LIBFT) $(PRINTF)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C libft clean
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re

.SECONDARY: $(OBJS)