/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putimage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:45:01 by mteffahi          #+#    #+#             */
/*   Updated: 2025/02/06 15:45:36 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_open_window(t_game *game)
{
	game->ft_mlx->mlx_ptr = mlx_init();
	ft_maplen(game);
	game->x *= TILE_SIZE;
	game->y *= TILE_SIZE;
	game->ft_mlx->win_ptr = mlx_new_window(game->ft_mlx->mlx_ptr, game->x, game->y, "So_long");
	mlx_key_hook(game->ft_mlx->win_ptr , handle_keypress, game);
	mlx_loop(game->ft_mlx->mlx_ptr);
}

int handle_keypress(int keycode, t_game *game)
{
    if (keycode == 53)  // ESC key
        mlx_destroy_window(game->ft_mlx->mlx_ptr, game->ft_mlx->win_ptr);
    return (0);
}
