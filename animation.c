#include "so_long.h"
#include <unistd.h>

void	coin_animation(t_data *game)
{
	static int	i;
	
	if (i % 3 == 0)
		game->a_c = (game->a_c + 1) % 7;
	if (i == 200)
		i = 1;
	i++;
}

void	image_coin(t_data *game)
{
	game->images->coin = (void **)malloc(sizeof(void *) * 7);
	game->images->coin[0] = mlx_xpm_file_to_image(game->mlx, "0/0.xpm", &(game -> width), & (game -> height));
	game->images->coin[1] = mlx_xpm_file_to_image(game->mlx, "0/1.xpm", &(game -> width), & (game -> height));
	game->images->coin[2] = mlx_xpm_file_to_image(game->mlx, "0/2.xpm", &(game -> width), & (game -> height));
	game->images->coin[3] = mlx_xpm_file_to_image(game->mlx, "0/3.xpm", &(game -> width), & (game -> height));
	game->images->coin[4] = mlx_xpm_file_to_image(game->mlx, "0/4.xpm", &(game -> width), & (game -> height));
	game->images->coin[5] = mlx_xpm_file_to_image(game->mlx, "0/5.xpm", &(game -> width), & (game -> height));
	game->images->coin[6] = mlx_xpm_file_to_image(game->mlx, "0/6.xpm", &(game -> width), & (game -> height));
}
