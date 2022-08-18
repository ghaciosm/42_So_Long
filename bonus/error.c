/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaciosm <ghaciosm@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:47:03 by ghaciosm          #+#    #+#             */
/*   Updated: 2022/08/17 17:48:03 by ghaciosm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

int	ft_error(char *str)
{
	ft_printf("Error\n%s", str);
	return (0);
}
