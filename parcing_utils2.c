/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:32:28 by mteffahi          #+#    #+#             */
/*   Updated: 2025/01/31 18:00:45 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	col_check_helper(t_resources *p)
{
	if (p->coins <= 0)
		return (1);
	else if (p->exit != 1)
		return (1);
	else if (p->player != 1)
		return (1);
	return (0);
}

int	collectibles_check(t_resources *rs, char **map)
{
	int y;
	int x;

	y = -1;
	rs->coins = 0;
	rs->exit = 0;
	rs->player = 0;
	while (map[++y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				rs->coins++;
			else if (map[y][x] == 'E')
				rs->exit++;
			else if (map[y][x] == 'P')
				rs->player++;
			x++;
		}
	}
	if (col_check_helper(rs))
		return (1);
	else
		return (0);
}
