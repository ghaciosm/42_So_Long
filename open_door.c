#include "so_long.h"
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
void	exit_door(t_data *game);
int open_door(t_data *game)
{
    game->door->i = 0;
    game->door->j = 0;
    while (game->door->i < game->y)
    {
        game->door->j = 0;
        while (game->a[game->door->i][game->door->j] != '\n' && game->a[game->door->i][game->door->j] != '\0')
        {
            if(game->a[game->door->i][game->door->j] == 'C')
            {
                return (0);
            }
            game->door->j++;
        }
        game->door->i++;
    }
    return (1);
}

void    open_door2(t_data *game)
{
    static int  i;
    if(open_door(game))
    {
        if(i > 0 && i < 5)
            mlx_put_image_to_window(game -> mlx, game -> win, game -> image5, (game-> door->j - 2) * 64, (game->door->i- 2) * 64);
        if(i >= 5 && i < 10)
            mlx_put_image_to_window(game -> mlx, game -> win, game -> door -> door2,(game-> door->j - 2) * 64, (game->door->i- 2) * 64);
        if(i >= 10 && i < 20)
            mlx_put_image_to_window(game -> mlx, game -> win, game ->door -> door3, (game-> door->j - 2) * 64, (game->door->i- 2) * 64);
        if (i >= 20)
            mlx_put_image_to_window(game -> mlx, game -> win, game -> door -> door4, (game-> door->j - 2) * 64, (game->door->i- 2) * 64);
        i++;
		exit_door(game);
    }
}

void	exit_door(t_data *game)
{
	if (game->p_x / 64 == 15 && game->p_y / 64 == 6)
		exit(0);
}
