NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR    = libft
PRINTF_DIR   = ft_printf

LIBFT    = $(LIBFT_DIR)/libft.a
PRINTF   = $(PRINTF_DIR)/libftprintf.a

SRCS = map_pars.c map_utils.c map_utils2.c \
       gnl/get_next_line.c gnl/get_next_line_utils.c \
       ft_printf/ft_printf.c ft_printf/print_char.c \
       ft_printf/print_hexa.c ft_printf/print_num.c \
       ft_printf/print_ptr.c ft_printf/print_string.c \
       ft_printf/print_unsigned.c

OBJS = $(SRCS:.c=.o)

MLX = -Lmlx -lmlx -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX) $(LIBFT) $(PRINTF)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

mc : all clean

re: fclean all