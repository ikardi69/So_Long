/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikardi <ikardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:25:05 by ikardi            #+#    #+#             */
/*   Updated: 2025/01/29 20:34:51 by ikardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_rows_check(char *const *map)
{
    int y;
    int x;

    y = 0;
    x = 0;
    while (map[y][x])
    {
		if (y == 0 && map[y][x] != '1')
            return (1);
        x++;
    }
    while (map[y])
        y++;
    x = 0;
    y--;
    while (map[y][x])
    {
		if (y == 0 && map[y][x] != '1')
            return (1);
    }
    return (0);
}

int ft_coins_check(char *const *map, int x, int y)
{
	if (map[y][x] == 'C' && map[y - 1][x] == '1' && map[y][x - 1] == '1'
		&& map[y + 1][x] == '1' && map[y][x + 1] == '1')
		return (1);
	else
		return (0);
}
