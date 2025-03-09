/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_util1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:45:01 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/09 01:18:48 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_open_window(t_game *game)
{
	game->ft_mlx->mlx_ptr = mlx_init();
	if (!game->ft_mlx->mlx_ptr)
		ft_failing(game, 1);
	ft_set_images(game);
	if (!game->ft_mlx->coin || !game->ft_mlx->wall || !game->ft_mlx->ground
		|| !game->ft_mlx->exit || !game->ft_mlx->player || !game->ft_mlx->enemy)
		ft_failing(game, 2);
	ft_maplen(game->ft_mlx);
	game->ft_mlx->x *= TILE_SIZE;
	game->ft_mlx->y *= TILE_SIZE;
	game->ft_mlx->win_ptr = mlx_new_window(game->ft_mlx->mlx_ptr,
			game->ft_mlx->x, game->ft_mlx->y, "So_long");
	if (!game->ft_mlx->win_ptr)
		ft_failing(game, 3);
	mlx_hook(game->ft_mlx->win_ptr, 2, 1,
		handle_keypress, (void *)game->ft_mlx);
	mlx_hook(game->ft_mlx->win_ptr, 17, 0,
		destroy_window, (void *)game->ft_mlx);
	mlx_loop_hook(game->ft_mlx->mlx_ptr, update_enemy, game->ft_mlx);
	ft_render_map(game->ft_mlx);
	mlx_loop(game->ft_mlx->mlx_ptr);
}

void	ft_render_map(t_mlx	*mlx)
{
	int		x;
	int		y;
	void	*img;

	y = -1;
	while (mlx->map[++y])
	{
		x = -1;
		while (mlx->map[y][++x])
		{
			set_img_ptr(mlx, mlx->map[y][x], &img);
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img,
				x * TILE_SIZE, y * TILE_SIZE);
		}
		img = NULL;
	}
}

static void	ft_exit_finish(t_mlx *game)
{
	if (ft_coins_e_check(game))
		return ;
	else
	{
		ft_putstr("Moves: ");
		ft_putnbr(game->moves_count);
		ft_putstr("\n");
		ft_putstr("Winner!!\n");
	}
	ft_finish_free(game);
	game = NULL;
	exit(0);
}

static void	ft_new_position(t_mlx *game, int new_y, int new_x)
{
	if (game->map[new_y][new_x] == 'E')
		ft_exit_finish(game);
	else if (game->map[new_y][new_x] == 'N')
		ft_looser_function(game);
	else
	{
		if (game->map[new_y][new_x] == 'C')
			game->ft_game->coins--;
		game->map[game->player_y][game->player_x] = '0';
		game->map[new_y][new_x] = 'P';
		ft_render_map(game);
		if (game->player_x != new_x || game->player_y != new_y)
		{
			game->moves_count++;
			ft_putstr("Moves: ");
			ft_putnbr(game->moves_count);
			ft_putstr("\n");
		}
		game->player_y = new_y;
		game->player_x = new_x;
	}
	return ;
}

int	handle_keypress(int keycode, t_mlx *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (new_x < 0 || new_y < 0
		|| new_y >= game->map_height
		|| new_x >= game->map_width)
		return (0);
	if (keycode == 65307)
	{
		ft_putstr("You exited the game before finishing it\n");
		return (ft_finish_free(game), exit(0), 1);
	}
	else if (keycode == 119)
		new_y--;
	else if (keycode == 115)
		new_y++;
	else if (keycode == 97)
		new_x--;
	else if (keycode == 100)
		new_x++;
	if (game->map[new_y][new_x] != '1')
		ft_new_position(game, new_y, new_x);
	return (0);
}
