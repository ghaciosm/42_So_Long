NAME = libmlx.a
FLAGS = -Wall -Wextra -Werror
LFLAGS = -framework OpenGL -framework AppKit
PRINTF = others/ft_printf/libftprintf.a
LINE = others/get_next_line/get_next_line.c others/get_next_line/get_next_line_utils.c
MLX = others/mlx/libmlx.a
	
all : $(NAME)
	gcc game/*.c $(PRINTF) $(LINE) $(LFLAGS) $(FLAGS) $(MLX) -o so_long
	@echo "SUCCESS"

$(NAME) : $(PRINTF) $(MLX)
	cp others/mlx/libmlx.a .

$(PRINTF) :
	make -C others/ft_printf

$(MLX) :
	make -C others/mlx

clean :
	make clean -C others/ft_printf
	make clean -C others/mlx

fclean : clean
	rm -rf so_long
	make fclean -C others/ft_printf

re : fclean all
