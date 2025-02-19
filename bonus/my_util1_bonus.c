/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_util1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:45:01 by mteffahi          #+#    #+#             */
/*   Updated: 2025/02/18 17:59:38 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_open_window(t_game *game)
{
	game->ft_mlx->mlx_ptr = mlx_init();
	if (!game->ft_mlx->mlx_ptr)
	{
		ft_putstr("Error initializing MLX\n");
		return;
	}
	game->ft_mlx->coin = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr, "./bonus/images/coin.xpm", &game->ft_mlx->map_width, &game->ft_mlx->map_height);
	game->ft_mlx->wall = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr, "./bonus/images/wall.xpm", &game->ft_mlx->map_width, &game->ft_mlx->map_height);
	game->ft_mlx->ground = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr, "./bonus/images/ground.xpm", &game->ft_mlx->map_width, &game->ft_mlx->map_height);
	game->ft_mlx->exit = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr, "./bonus/images/exit.xpm", &game->ft_mlx->map_width, &game->ft_mlx->map_height);
	game->ft_mlx->player = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr, "./bonus/images/player.xpm", &game->ft_mlx->map_width, &game->ft_mlx->map_height);
	game->ft_mlx->enemy = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr, "./bonus/images/enemy.xpm", &game->ft_mlx->map_width, &game->ft_mlx->map_height);
	if (!game->ft_mlx->coin || !game->ft_mlx->wall || !game->ft_mlx->ground || !game->ft_mlx->exit || !game->ft_mlx->player || !game->ft_mlx->enemy)
	{
		ft_finish_free(game->ft_mlx);
		ft_putstr("Error loading images\n");
		return;
	}
	ft_maplen(game->ft_mlx);
	game->ft_mlx->x *= TILE_SIZE;
	game->ft_mlx->y *= TILE_SIZE;
	game->ft_mlx->win_ptr = mlx_new_window(game->ft_mlx->mlx_ptr, game->ft_mlx->x, game->ft_mlx->y, "So_long");
	mlx_key_hook(game->ft_mlx->win_ptr , handle_keypress, (void *)game->ft_mlx);
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
		x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == '1')
				img = mlx->wall;
			else if (mlx->map[y][x] == '0')
				img = mlx->ground;
			else if (mlx->map[y][x] == 'C')
				img = mlx->coin;
			else if (mlx->map[y][x] == 'E')
				img = mlx->exit;
			else if (mlx->map[y][x] == 'P')
				img = mlx->player;
			else if (mlx->map[y][x] == 'N')
				img = mlx->enemy;
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
	}
	
}

static void ft_exit_finish(t_mlx *game, int new_y, int new_x)
{
	if (ft_coins_E_check(game))
		return ;
	if (game->map[new_y][new_x] != 'E')
		ft_putstr("You exited the game before finishing it (weak.)\n");
	ft_finish_free(game);
	exit(0);
}

static void	ft_new_position(t_mlx *game, int new_y, int new_x)
{
	if (game->map[new_y][new_x] == 'E')
		ft_exit_finish(game, new_y, new_x);
	else if (game->map[new_y][new_x] == 'N')
		ft_looser_function(game);
	else
	{
		// ft_enemy_movment(game);
		game->map[game->player_y][game->player_x] = '0';
		game->map[new_y][new_x] = 'P';
		game->player_y = new_y;
		game->player_x = new_x;
		//game->moves_count++;
		ft_putstr("Moves: ");
		ft_putnbr(game->moves_count);
		ft_putstr("\n");
		ft_render_map(game);
	}
	return ;
}

int handle_keypress(int keycode, t_mlx *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
    if (new_x < 0 || new_y < 0 || 
        new_y >= game->map_height || 
        new_x >= game->map_width)
        return (0);
    if (keycode == 65307)
	{
		ft_putstr("You exited the game before finishing it (weak.)\n");
		// ft_printf_ptr_adresses(game);
		ft_finish_free(game);
		return (exit(0), 1);
	}
	else if (keycode == 119 && ++game->moves_count)
		new_y--;
	else if (keycode == 115 && ++game->moves_count)
		new_y++;
	else if (keycode == 97 && ++game->moves_count)
		new_x--;
	else if (keycode == 100 && ++game->moves_count)
		new_x++;
	if (game->map[new_y][new_x] != '1')
		ft_new_position(game, new_y, new_x);
    return (0);
}
