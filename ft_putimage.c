/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putimage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:45:01 by mteffahi          #+#    #+#             */
/*   Updated: 2025/02/05 14:51:57 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_open_window(t_player *game)
{
	game->mlx_ptr = mlx_init();
	ft_maplen(game);
	game->x *= 50;
	game->y *= 50;
	// game->win_ptr = mlx_new_window(game->mlx_ptr, game->x, game->y, "So_long");
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->x, game->y, "So_long");
	mlx_key_hook(game->win_ptr, handle_keypress, game);
	mlx_loop(game->mlx_ptr);
}

int handle_keypress(int keycode, t_player *game)
{
    if (keycode == 53)  // ESC key
        mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    return (0);
}
