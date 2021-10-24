NAME = libftprintf.a

libft_path = ./libft

SRCS = ft_printf.c

OBJS = $(SRCS:%.c=%.o)

CC = clang 
CFLAGS = -Wall -Werror -Wextra       

$(NAME): $(OBJS)
	make all -C $(libft_path)
	ar -crs $(NAME) $(OBJS)
	cp $(libft_path)/libft.a libftprintf.a

all: $(NAME)

clean: clean
	rm -rf ${OBJS}
	rm -rf ./a.out
	make clean -C ${libft_path}

fclean: clean
	rm -rf ${NAME}
	make fclean -C ${libft_path}

re: fclean all