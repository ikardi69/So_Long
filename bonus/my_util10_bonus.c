/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_util10_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:24:24 by mteffahi          #+#    #+#             */
/*   Updated: 2025/02/18 18:27:01 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int update_enemy(t_mlx *game)
{
	static int  frames = 0;
	int         y;
	int         x;

	y = 0;
	x = 0;
	frames++;
	// while (game->map[y])
	// {
	// 	x = 0;
	// 	while (game->map[y][x])
	// 	{
	// 		if (game->map[y][x] == 'N')
	// 		{
				if (frames % 9000 == 0)
				{
					// printf("x = %d, y = %d\n", y, x);
					ft_enemy_movment(game, y, x);
					ft_render_map(game);
					//return (0);
				}
	// 		}
	// 		x++;
	// 	}
	// 	y++;
	// }
	return (0);
}
