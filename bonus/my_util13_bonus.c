/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_util13_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:31:22 by mteffahi          #+#    #+#             */
/*   Updated: 2025/02/28 12:33:42 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    set_img_ptr(t_mlx *mlx, char c, void *img)
{
    if (c == '1')
        img = mlx->wall;
    else if (c == '0')
		img = mlx->ground;
    else if (c == 'C')
		img = mlx->coin;
    else if (mlx->map[y][x] == 'E')
		img = mlx->exit;
	else if (mlx->map[y][x] == 'P')
		img = mlx->player;
	else if (mlx->map[y][x] == 'N')
		img = mlx->enemy;
}
