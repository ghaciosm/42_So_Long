#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
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
}	t_data;


#endif
