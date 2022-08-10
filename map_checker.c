#include "so_long.h"
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

int map_charcheck(t_data *game)
{
    int m;
    int g;

    g = 0;
    m = 1;
    while ((game -> y-1) >= m)
    {
        while (game -> a[m][g] != '\n' && game -> a[m][g] != '\0')
                g++; 
		g--;
		if (g != game -> x - 1)
            return (ft_error("Dikdörtgen değil!!!"));
		if ((game -> a[m][0] != '1') || (game -> a[m][game -> x-1] != '1'))
		 	return (ft_error("Duvarla çevrili değil!!!"));
        m++;
    }
    return (1);
}

int map_checker(t_data *game, int i)
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
