#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>

# define ESC 53
# define A 0
# define S 1
# define D 2
# define W 13

typedef	struct	s_data
{
	int		x;
	int		y;
	void	*mlx;
	void	*win;
	char	**a;	
	int		i;
	void	*image;
	void	*image2;
	int		width;
	int		height;
}	t_data;

typedef struct	s_image
{

}	t_image;	

int 	key_states(int keycode, t_data *game);
int 	checker(char **av, t_data *game);
int 	map_reader(int fd, t_data *game);
int 	ft_error(char *str);
int 	map_charcheck(t_data *game);
int 	map_checker(t_data *game, int i);
void	put_image(t_data *game);

#endif
