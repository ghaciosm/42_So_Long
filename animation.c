/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaciosm <ghaciosm@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:05:27 by ghaciosm          #+#    #+#             */
/*   Updated: 2022/08/16 14:56:59 by ghaciosm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

void	coin_animation(t_data *game)
{
	static int	i;

	if (i % 3 == 0)
		game->a_c = (game->a_c + 1) % 7;
	if (i == 21)
		i = 0;
	i++;
}

void	image_coin(t_data *game)
{
	game->images->coin = (void **)malloc(sizeof(void *) * 7);
	game->images->coin[0] = mlx_xpm_file_to_image(game->mlx,
			"0/elmas/0.xpm", &(game -> width), & (game -> height));
	game->images->coin[1] = mlx_xpm_file_to_image(game->mlx,
			"0/elmas/1.xpm", &(game -> width), & (game -> height));
	game->images->coin[2] = mlx_xpm_file_to_image(game->mlx,
			"0/elmas/2.xpm", &(game -> width), & (game -> height));
	game->images->coin[3] = mlx_xpm_file_to_image(game->mlx,
			"0/elmas/3.xpm", &(game -> width), & (game -> height));
	game->images->coin[4] = mlx_xpm_file_to_image(game->mlx,
			"0/elmas/4.xpm", &(game -> width), & (game -> height));
	game->images->coin[5] = mlx_xpm_file_to_image(game->mlx,
			"0/elmas/5.xpm", &(game -> width), & (game -> height));
	game->images->coin[6] = mlx_xpm_file_to_image(game->mlx,
			"0/elmas/6.xpm", &(game -> width), & (game -> height));
}

void    enemy_animation(t_data *game)
{
    static int  i;

    if (i % 10 == 0)
        game->e_c = (game->e_c + 1) % 6;
    i++;
}

void	image_enemy(t_data *game)
{
	game->images->enemy = (void **)malloc(sizeof(void *) * 6);
	game->images->enemy[0] = mlx_xpm_file_to_image(game-> mlx, "0/enemy/1.xpm", &(game -> width), & (game -> height));
	game->images->enemy[1] = mlx_xpm_file_to_image(game-> mlx, "0/enemy/2.xpm", &(game -> width), & (game -> height));
	game->images->enemy[2] = mlx_xpm_file_to_image(game-> mlx, "0/enemy/3.xpm", &(game -> width), & (game -> height));
	game->images->enemy[3] = mlx_xpm_file_to_image(game-> mlx, "0/enemy/4.xpm", &(game -> width), & (game -> height));
	game->images->enemy[4] = mlx_xpm_file_to_image(game-> mlx, "0/enemy/5.xpm", &(game -> width), & (game -> height));
	game->images->enemy[5] = mlx_xpm_file_to_image(game-> mlx, "0/enemy/6.xpm", &(game -> width), & (game -> height));
}
