NAME = libftprintf.a

libft_path = ./libft

SRCS = ft_printf.c ft_printf_utils.c ft_printf_conversors.c ft_printf_conversor_x.c

OBJS = $(SRCS:%.c=%.o)

CC = clang 
CFLAGS = -Wall -Werror -Wextra -g      

$(NAME): $(OBJS)
	make all -C $(libft_path)
	cp $(libft_path)/libft.a libftprintf.a
	ar -crs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf ${OBJS}
	rm -rf ./a.out
	make clean -C ${libft_path}

fclean: clean
	rm -rf ${NAME}
	make fclean -C ${libft_path}

re: fclean all