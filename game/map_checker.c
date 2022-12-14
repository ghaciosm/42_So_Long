/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaciosm <ghaciosm@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:13:01 by ghaciosm          #+#    #+#             */
/*   Updated: 2022/08/17 18:21:53 by ghaciosm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

int	map_charcheck(t_data *game)
{
	int	m;
	int	g;

	g = 0;
	m = 1;
	while ((game -> y - 1) >= m)
	{
		while (game -> a[m][g] != '\n' && game -> a[m][g] != '\0')
			g++;
		g--;
		if (g != game -> x - 1)
			return (ft_error("Dikdörtgen değil!!!"));
		if ((game -> a[m][0] != '1') || (game -> a[m][game -> x - 1] != '1'))
			return (ft_error("Duvarla çevrili değil!!!"));
		m++;
	}
	return (1);
}

int	map_checker(t_data *game, int i)
{
	game -> x = 0;
	while ((game -> a[i - 1][game -> x] != '\n') &&
		(game -> a[i - 1][game -> x] != '\0'))
	{
		if (game -> a[i - 1][game -> x] != '1')
			return (ft_error("Duvarla çevrili değildir!!!"));
		game -> x++;
	}
	i = 0;
	while (game -> a[0][i] != '\n')
	{
		if (game -> a[0][i] != '1')
			return (ft_error("Duvarla çevrili değildir!!!"));
		i++;
	}
	if (game -> x != i)
		return (ft_error("Dikdörtgen değil!!!"));
	return (1);
}

int	collectible_check(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->y - 1)
	{
		x = 0;
		while (game->a[y][x] != '\n')
		{
			if (game->a[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (ft_error("Koleksiyon yok!!"));
}

int	exit_check(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->y - 1)
	{
		x = 0;
		while (game->a[y][x] != '\n')
		{
			if (game->a[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (ft_error("Exit yok!!"));
}

int	start_check(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->y - 1)
	{
		x = 0;
		while (game->a[y][x] != '\n')
		{
			if (game->a[y][x] == 'P')
				return (1);
			x++;
		}
		y++;
	}
	return (ft_error("Başlangıç yok!!"));
}
