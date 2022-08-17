/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaciosm <ghaciosm@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:02:56 by ghaciosm          #+#    #+#             */
/*   Updated: 2022/08/17 18:06:50 by ghaciosm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

void	exit_door(t_data *game);

int	open_door(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->y)
	{
		j = 0;
		while (game->a[i][j] != '\n' && game->a[i][j] != '\0')
		{
			if (game->a[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	open_door2(t_data *game)
{
	static int	i;

	if (open_door(game))
	{
		if (i >= 5 && i < 10)
			game->x_c = 1;
		if (i >= 10 && i < 20)
			game->x_c = 2;
		if (i >= 20)
			game->x_c = 3;
		i++;
		if (game->a[game->p_y / 64][game->p_x / 64] == 'E')
			exit (0);
	}
}

void	door(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game -> y)
	{
		j = 0;
		while (game -> a[i][j] != '\0')
		{
			if (game -> a[i][j] == 'E')
			{
				mlx_put_image_to_window(game -> mlx, game -> win,
					game->images->door[game->x_c], j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}
