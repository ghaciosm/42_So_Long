NAME = so_long
FLAGS = -Wall -Wextra -Werror
LFLAGS = -framework OpenGL -framework AppKit
PRINTF = ft_printf/libftprintf.a
LINE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
MLX = mlx/libmlx.a
	
all : $(NAME)

$(NAME) :
	make -C ft_printf
	make -C mlx
	gcc *.c $(PRINTF) $(LINE) $(LFLAGS) $(FLAGS) $(MLX) -o $(NAME)

clean :
	make clean -C ft_printf
	make clean -C mlx

fclean : clean
	rm -rf $(NAME)
	make fclean -C ft_printf

re : fclean all
