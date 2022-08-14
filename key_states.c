/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_states.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaciosm <ghaciosm@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:56:43 by ghaciosm          #+#    #+#             */
/*   Updated: 2022/08/11 16:57:09 by ghaciosm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

int	key_states2(int keycode, t_data *game)
{
	if (keycode == D)
	{
		if(game->a[game->p_y / 64][(game->p_x / 64) + 1] != '1')
		{
			game->p_x += 64;
			game -> g++;
		}		
	}
	if (keycode == S)
	{
		if(game->a[game->p_y / 64 + 1][game->p_x / 64] != '1')
		{
			game->p_y += 64;
			game -> g++;
		}
	}
	if (keycode == S || keycode == W || keycode == A || keycode == D)
		ft_printf("Move: %d\n", game->g);
	return (game->g);
}

int	key_states(int keycode, t_data *game)
{
	if (keycode == ESC)
	{
		exit(0);
	}
	if (keycode == W)
	{
		if(game->a[game->p_y / 64 + - 1][game->p_x / 64] != '1')
		{
			game->p_y -= 64;
			game -> g++;
		}
	}
	if (keycode == A)
	{
		if(game->a[game->p_y / 64][(game->p_x / 64) - 1] != '1')
		{
			game->p_x -= 64;
			game -> g++;
		}
	}
	key_states2(keycode, game);
	return (game->g);
}
