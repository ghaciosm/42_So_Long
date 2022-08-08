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

void    image_file(t_data *game)
{
    game -> image = mlx_xpm_file_to_image(game -> mlx, "4.xpm", &(game -> width), &(game -> height));
    put_image(game);
    game -> image2 = mlx_xpm_file_to_image(game -> mlx, "2.xpm", &(game -> width), &(game -> height));
    wall_create(game);
}
