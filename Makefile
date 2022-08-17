NAME = libmlx.a
FLAGS = -Wall -Wextra -Werror
LFLAGS = -framework OpenGL -framework AppKit
PRINTF = ft_printf/libftprintf.a
LINE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
MLX = mlx/libmlx.a
	
all :
	$(MAKE) tmp -j 8

tmp : $(NAME)
	gcc *.c $(PRINTF) $(LINE) $(LFLAGS) $(FLAGS) $(MLX) -o so_long
	@echo "SUCCESS"

$(NAME) : $(PRINTF) $(MLX)
	cp mlx/libmlx.a .

$(PRINTF) :
	make -C ft_printf

$(MLX) :
	make -C mlx

clean :
	make clean -C ft_printf
	make clean -C mlx

fclean : clean
	rm -rf $(NAME)
	make fclean -C ft_printf

re : fclean all
