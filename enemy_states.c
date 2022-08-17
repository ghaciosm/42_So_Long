#include "so_long.h"
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

void    enemy_exit(t_data *game)
{
    int i;

    i = 0;
    while(i < game->e_co)
    {
        if (game->p_y / 64 == game->player[i].y && game->p_x / 64 == game->player[i].x)
            exit(0);
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
				game->player[game->e_co].a = 1;
				game->e_co++;
            }
            j++;
        }
        i++;
    }
}

void	ft_con(t_data *game, int i)
{
	game->player[i].a = -1;
	if (game->a[game->player[i].y][game->player[i].x - 1] != '1')
		game->player[i].x--;
}

void	enemy_move(t_data *game)
{
	static int	s;
	int	i;

	i = 0;
	if (s % 15 == 0)
	{
		while (i < game -> e_co)
		{
			if (game->a[game->player[i].y][game->player[i].x + 1] == '1')
				ft_con(game, i);
			else if (game->player[i].a == -1 && game->a[game->player[i].y][game->player[i].x - 1] == '1')
			{
				game->player[i].a = 1;
				if (game->a[game->player[i].y][game->player[i].x + 1] != '1')
					game->player[i].x++;
			}
			else if (game->a[game->player[i].y][game->player[i].x + 1] != '1')
				game->player[i].x = game->player[i].x + game->player[i].a;
			i++;
		}
	}
	s++;
}