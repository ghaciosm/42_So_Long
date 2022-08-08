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
