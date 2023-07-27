
NAME = so_long

LIB = so_long.h

FLAGS = -Wall -Werror -Wextra

LIB_FLAGS = -lXext -lX11

LIBFT = ./libft/libft.a

FTPRINTF = ./ft_printf/libftprintf.a

MINILIB = ./minilibx-linux/libmlx_Linux.a

SRCS = main.c

CC = gcc

all: $(NAME)

$(NAME):	$(OBJ)
	make -C ./minilibx-linux
	make -C ./libft
	make -C ./ft_printf
	$(CC) $(FLAGS) $(SRCS) $(LIBFT) $(FTPRINTF) $(MINILIB) $(LIB_FLAGS) -o $(NAME)
	
clean:
	rm -f *.o
	make clean -C ./minilibx-linux
	make clean -C ./libft
	make clean -C ./ft_printf

fclean: clean
	rm $(NAME)

re: fclean all