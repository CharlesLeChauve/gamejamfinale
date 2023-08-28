
NAME = so_long

#LIB = solong.h

FLAGS = -Wall -Wextra -g

LIB_FLAGS = -lXext -lX11

LIBFT = ./libft/libft.a

FTPRINTF = ./ft_printf/libftprintf.a

MINILIB = ./minilibx-linux/libmlx_Linux.a ./minilibx-linux/libmlx.a

#MINILIB2 = ./minilibx-linux/libmlx.a

SRCS = main.c mouvements.c check_cookiz.c

CC = gcc

all: $(NAME)

$(NAME):	$(OBJ)
	make -C ./minilibx-linux
#	make -C ./libft
#	make -C ./ft_printf
	$(CC) $(FLAGS) $(SRCS) $(LIBFT) $(MINILIB) $(FTPRINTF) -o $(NAME) $(LIB_FLAGS)
	
clean:
	rm -f *.o
	make clean -C ./minilibx-linux
	make clean -C ./libft
	make clean -C ./ft_printf

fclean: clean
	rm $(NAME)

re: fclean all

rere:
	rm -f *.o
	$(CC) $(FLAGS) $(SRCS) $(LIBFT) $(FTPRINTF) $(MINILIB) $(LIB_FLAGS) -o $(NAME)

