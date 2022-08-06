/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaciosm <ghaciosm@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:56:43 by ghaciosm          #+#    #+#             */
/*   Updated: 2022/08/05 15:53:17 by ghaciosm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

int	ft_error(char *str)
{
	ft_printf("Error\n%s", str);
	return (0);
}

int	map_charcheck(t_data *game)
{
	int	m;
	int	g;

	g = 0;
	m = 1;
	while ((game -> y-1) >= m)
	{
		while (game -> a[m][g] != '\n' && game -> a[m][g] != '\0')
				g++;
		if ((game -> a[m][0] != '1') || (game -> a[m][game -> x-1] != '1'))
			return (ft_error("Duvarla çevrili değil!!!"));
		if (g != game -> x)
			return (ft_error("Dikdörtgen değil!!!"));
		m++;
	}
	return (1);
}

int	map_checker(t_data *game, int i)
{
	game -> x = 0;
	while ((game -> a[i-1][game -> x] != '\n') && (game -> a[i-1][game -> x] != '\0'))
	{
		if (game -> a[i-1][game -> x] != '1')
			return (ft_error("Duvarla çevrili değildir!!!"));
		game -> x++;
	}
	i = 0;
    while (game -> a[0][i] != '\n')
    {
        if(game ->a[0][i] != '1')
		 	return (ft_error("Duvarla çevrili değildir!!!"));
		i++;
    }
	if (game -> x != i)
		return (ft_error("Dikdörtgen değil!!!"));
	return (1);
}

int	map_reader(int fd, t_data *game)
{
	int	i;

	i = 0;
	game -> a = (char **)malloc(sizeof(char *) * 100);
	if (!(game -> a))
		return (0);
	while (i < 100)
	{
		game -> a[i] = get_next_line(fd);
		if (game -> a[i] == NULL)
			break;
		i++;
	}
	game -> y = i;
	if (!(map_checker(game, i)) || !(map_charcheck(game)))
		return (0);
	return (1);
}

int	checker(char **av, t_data *game)
{
	int	fd;
	
	if (ft_strncmp(ft_strchr(av[1], '.'), ".ber", 5)) 
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (1);
	if (!(map_reader(fd, game)))
		return (1);
	return (0);
}

int	key_states(int keycode, t_data *game)
{
	if (keycode == ESC)
	{
		exit(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*game;

	game = (t_data *)malloc(sizeof(t_data));
	if (ac == 2)
	{
		if (checker(av, game))
			exit (0);
		game -> mlx = mlx_init();
		game -> win = mlx_new_window(game -> mlx, 500, 500, "title");
		mlx_key_hook(game -> win, &key_states, game);
		mlx_loop(game -> mlx);
	}
	return (0);
}
