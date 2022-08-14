/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaciosm <ghaciosm@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:13:12 by ghaciosm          #+#    #+#             */
/*   Updated: 2022/08/11 17:10:06 by ghaciosm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

void	char_put(t_data *game)
{
	mlx_put_image_to_window(game -> mlx, game -> win, game -> image3, game->p_x, game->p_y);
}

int	loop(t_data *game)
{
	put_image(game);
	wall_create(game);
	door(game);
	collectible(game);
	char_put(game);
	eating_diamonds(game);
	return (0);
}
