/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaciosm <ghaciosm@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:55:12 by ghaciosm          #+#    #+#             */
/*   Updated: 2022/08/16 15:01:51 by ghaciosm         ###   ########.fr       */
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

typedef struct	s_player
{
	int	x;
	int y;
	int	a;
}	t_player;

typedef struct	s_images
{
	void	**coin;
	void	**door;
	void	**enemy;
}	t_images;

typedef struct	s_data
{
	int			x;
	int			y;
	int			p_x;
	int			p_y;	
	int			i;
	int			width;
	int			height;
	int			g;
	int			a_c;
	int			x_c;
	int			e_c;
	int			e_co;
	char		**a;
	void		*mlx;
	void		*win;
	void		*image;
	void		*image2;
	void		*image3;
	void		*image4;
	t_images	*images;
	t_player	*player;
}	t_data;

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
int		open_door(t_data *game);
void    open_door2(t_data *game);
void    image_coin(t_data *game);
void    coin_put(t_data *game);
void    coin_animation(t_data *game);
int		start_check(t_data *game);
int		exit_check(t_data *game);
int		collectible_check(t_data *game);
void	enemy_check(t_data *game);
void	put_enemy(t_data *game);
void	image_enemy(t_data *game);
void	image_coin(t_data *game);
void	enemy(t_data  *game);
void    enemy_animation(t_data *game);
void	enemy_move(t_data *game);
void	enemy_exit(t_data *game);
void	pixel_put(t_data *game);

#endif
