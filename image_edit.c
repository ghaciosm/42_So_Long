/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_edit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaciosm <ghaciosm@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:59:43 by ghaciosm          #+#    #+#             */
/*   Updated: 2022/08/16 15:04:04 by ghaciosm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

void	put_image(t_data *game)
{
	int	a;
	int	b;

	a = 0;
	while (a < game -> y)
	{
		b = 0;
		while (b < game -> x)
		{
			mlx_put_image_to_window(game -> mlx,
						game -> win, game -> image, b * 64, a * 64);
			b++;
		}
		a++;
	}
}

void	wall_create(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game -> y)
	{
		j = 0;
		while (game -> a[i][j] != '\0')
		{
			if (game -> a[i][j] == '1')
			{
				mlx_put_image_to_window(game -> mlx,
							game -> win, game -> image2, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}

void	chr_create(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game -> y)
	{
		j = 0;
		while (game -> a[i][j] != '\0')
		{
			if (game -> a[i][j] == 'P')
			{
				game->p_x = j * 64 + 3;
				game->p_y = i * 64 + 5;
			}
			j++;
		}
		i++;
	}
}

void	collectible(t_data	*game)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < game -> y)
	{
		j = 0;
		while (game -> a[i][j] != '\0')
		{
			if (game -> a[i][j] == 'C')
			{		
				mlx_put_image_to_window(game -> mlx, game -> win,
						game -> images->coin[game->a_c],
						j * 64 + 17, i * 64 + 17);
			}
			j++;
		}
		i++;
	}
}

void    enemy(t_data  *game)
{
    game->player = (t_player *)malloc(sizeof(t_player) * 10);
	int i;
    int j;

    i = 0;
	game->e_co = 0;
    while (i < game -> y)
    {
        j = 0;
        while (game -> a[i][j] != '\0')
        {
            if (game -> a[i][j] == 'N')
            {
				game->player[game->e_co].x = j;
				game->player[game->e_co].y = i;
				game->e_co++;
            }
            j++;
        }
        i++;
    }
}
/*void	enemy_move(t_data *game)
{
	int	a;

	a = 1;
	while (game->player[game->e_co].x + 1 != '1')
		{
			game->player[game->e_co].x = game->player[game->e_co].x + a;
		}	//game->player[e_c].y

}*/

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
						game -> image5, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}

void	image_file(t_data *game)
{
	game -> image = mlx_xpm_file_to_image(game -> mlx,
			"2.xpm", &(game -> width), &(game -> height));
	game -> image2 = mlx_xpm_file_to_image(game -> mlx,
			"1.xpm", &(game -> width), &(game -> height));
	//game -> image5 = mlx_xpm_file_to_image(game -> mlx,
	//		"5.xpm", &(game -> width), & (game -> height));
	game -> image3 = mlx_xpm_file_to_image(game -> mlx,
			"3.xpm", &(game -> width), & (game -> height));
	game -> image5 = mlx_xpm_file_to_image(game -> mlx,
			"5.xpm", &(game -> width), & (game -> height));
	chr_create(game);
	game->door -> door2 = mlx_xpm_file_to_image(game -> mlx,
			"door2.xpm", &(game -> width), & (game -> height));
	game->door -> door3 = mlx_xpm_file_to_image(game -> mlx,
			"door3.xpm", &(game -> width), & (game -> height));
	game->door -> door4 = mlx_xpm_file_to_image(game -> mlx,
			"door4.xpm", &(game -> width), & (game -> height));
	image_coin(game);
	image_enemy(game);
	enemy(game);
}
