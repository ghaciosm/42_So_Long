#include "so_long.h"
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

void    put_image(t_data *game)
{
    int a;
    int b;

    a = 0;
    while(a < game -> y)
    {
        b = 0;
        while (b < game -> x)
        {
            mlx_put_image_to_window(game -> mlx, game -> win, game -> image, b*64, a*64);
            b++;
        }
        a++;
    }
}

void    wall_create(t_data *game)
{
    int i;
    int j;

    i = 0;
    while (i < game -> y)
    {
        j = 0;
        while (game -> a[i][j] != '\0')
        {
            if (game -> a[i][j] == '1')
            {
                mlx_put_image_to_window(game -> mlx, game -> win, game -> image2, j*64, i*64);
            }
            j++;
        }
        i++;
    }
}

void	chr_create(t_data *game)
{
	int i;
    int j;

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
	int i;
    int j;

    i = 0;
    while (i < game -> y)
    {
        j = 0;
        while (game -> a[i][j] != '\0')
        {
            if (game -> a[i][j] == 'C')
            {
                mlx_put_image_to_window(game -> mlx, game -> win, game -> image4, j*64 + 14, i*64 + 14);
            }
            j++;
        }
        i++;
    }
}

void    door(t_data  *game)
{
    int i;
    int j;

    i = 0;
    while (i < game -> y)
    {
        j = 0;
        while (game -> a[i][j] != '\0')
        {
            if (game -> a[i][j] == 'E')
            {
                mlx_put_image_to_window(game -> mlx, game -> win, game -> image5, j*64, i*64);
            }
            j++;
        }
        i++;
    }
}

void    image_file(t_data *game)
{
    game -> image = mlx_xpm_file_to_image(game -> mlx, "2.xpm", &(game -> width), &(game -> height));
    game -> image2 = mlx_xpm_file_to_image(game -> mlx, "1.xpm", &(game -> width), &(game -> height));
	game -> image5 = mlx_xpm_file_to_image(game -> mlx, "5.xpm", &(game -> width), & (game -> height));
	game -> image3 = mlx_xpm_file_to_image(game -> mlx, "3.xpm", &(game -> width), & (game -> height));
	game -> image4 = mlx_xpm_file_to_image(game -> mlx, "4.xpm", &(game -> width), & (game -> height));
	door -> door1 = mlx_xpm_file_to_image(game -> mlx, "5.xpm", &(game -> width), & (game -> height));
	door -> door2 = mlx_xpm_file_to_image(game -> mlx, "door2.xpm", &(game -> width), & (game -> height));
	door -> door3 = mlx_xpm_file_to_image(game -> mlx, "door3.xpm", &(game -> width), & (game -> height));
	door -> door4 = mlx_xpm_file_to_image(game -> mlx, "door4.xpm", &(game -> width), & (game -> height));
	chr_create(game);
	if(open_door(t_data *game))
	{
		mlx_put_image_to_window(game -> mlx, game -> win, game -> door1, door->j*64, door->i*64);
		mlx_put_image_to_window(game -> mlx, game -> win, game -> door2, door->j*64, door->i*64);
		mlx_put_image_to_window(game -> mlx, game -> win, game -> door3, door->j*64, door->i*64);
		mlx_put_image_to_window(game -> mlx, game -> win, game -> door4, door->j*64, door->i*64);		
	}
}
