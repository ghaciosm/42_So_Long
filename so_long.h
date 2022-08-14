/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaciosm <ghaciosm@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:55:12 by ghaciosm          #+#    #+#             */
/*   Updated: 2022/08/12 15:41:09 by ghaciosm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct	s_data
{
	int		x;
	int		y;
	int		p_x;
	int		p_y;
	void	*mlx;
	void	*win;
	char	**a;	
	int		i;
	void	*image;
	void	*image2;
	void	*image3;
	void	*image4;
	void	*image5;
	int		width;
	int		height;
	int		g;
}	t_data;

typedef struct	s_door
{
	void	*door1;
	void	*door2;
	void	*door3;
	void	*door4;
	int		i;
	int		j;
}	t_door;

int		key_states(int keycode, t_data *game);
int		checker(char **av, t_data *game);
int		map_reader(int fd, t_data *game);
int		ft_error(char *str);
int		map_charcheck(t_data *game);
int		map_checker(t_data *game, int i);
void	put_image(t_data *game);
void	image_file(t_data *game);
void	wall_create(t_data *game);
int		loop(t_data *game);
void	collectible(t_data	*game);
void	chr_create(t_data *game);
int		key_states(int keycode, t_data *game);
int		key_states2(int keycode, t_data *game);
int		eating_diamonds(t_data *game);
void    door(t_data  *game);
void    open_door(t_data *game, t_door *door);

#endif
