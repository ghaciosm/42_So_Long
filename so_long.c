/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaciosm <ghaciosm@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:56:43 by ghaciosm          #+#    #+#             */
/*   Updated: 2022/08/08 17:35:23 by ghaciosm         ###   ########.fr       */
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
	(void)game;
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*game;

	game = (t_data *)malloc(sizeof(t_data));
	game -> width = 250;
    game -> height = 250;
	if (ac == 2)
	{
		if (checker(av, game))
			exit (0);
		game -> mlx = mlx_init();
		game -> win = mlx_new_window(game -> mlx, 64*game->x, 64*game->y, "title");
		mlx_key_hook(game -> win, &key_states, game);
		image_file(game);
		//game -> image = mlx_xpm_file_to_image(game -> mlx, "1.xpm", &(game -> width), &(game -> height));
		//put_image(game);
		mlx_loop(game -> mlx);
	}
	return (0);
}
