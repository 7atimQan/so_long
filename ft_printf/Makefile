NAME	= libftprintf.a
CC		= cc
FLAGS	= -Wall -Wextra -Werror
SRCS	= print_char.c print_hexa.c print_num.c print_ptr.c print_string.c print_unsigned.c ft_printf.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re