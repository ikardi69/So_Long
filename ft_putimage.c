/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putimage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:45:01 by mteffahi          #+#    #+#             */
/*   Updated: 2025/02/10 17:49:23 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_open_window(t_mlx *game)
{
	game->mlx_ptr = mlx_init();
	printf("y = %d, x = %d\n", game->player_y, game->player_x);
	if (!game->mlx_ptr)
	{
		write(1, "Error initializing MLX\n", 23);
		return;
	}
	game->coin = mlx_xpm_file_to_image(game->mlx_ptr, "./images/coin.xpm", &game->map_width, &game->map_height);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "./images/wall.xpm", &game->map_width, &game->map_height);
	game->ground = mlx_xpm_file_to_image(game->mlx_ptr, "./images/ground.xpm", &game->map_width, &game->map_height);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr, "./images/exit.xpm", &game->map_width, &game->map_height);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, "./images/player.xpm", &game->map_width, &game->map_height);
	if (!game->coin || !game->wall || !game->ground || !game->exit || !game->player)
	{
		write(1, "Error loading images\n", 21);
		return;
	}
	ft_maplen(game);
	game->x *= TILE_SIZE;
	game->y *= TILE_SIZE;
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->x, game->y, "So_long");
	mlx_key_hook(game->win_ptr , handle_keypress, game);
	ft_render_map(game);
	mlx_loop(game->mlx_ptr);
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
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
	}
	
}

static void	ft_new_position(t_game *game, int new_y, int new_x)
{
	game->ft_mlx->map[game->ft_mlx->player_y][game->ft_mlx->player_x] = '0';
	game->ft_mlx->map[new_y][new_x] = 'P';
	game->y = new_y;
	game->x = new_x;
	game->ft_mlx->moves_count++;
	write(1, "Moves: ", 7);
	ft_putnbr(game->ft_mlx->moves_count);
	ft_render_map(game->ft_mlx);
	return ;
}

int handle_keypress(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->x;
	new_y = game->y;
	//printf("new_x = %d new_y = %d\n", new_x, new_y);
    if (keycode == 65307)  // ESC key
	{
        mlx_destroy_window(game->ft_mlx->mlx_ptr, game->ft_mlx->win_ptr);
		return (1);
		exit(0);
	}
	else if (keycode == 119)
		new_y--;
	else if (keycode == 115)
		new_y++;
	else if (keycode == 97)
		new_x--;
	else if (keycode == 100)
		new_x++;
	if (game->ft_mlx->map[new_y][new_x] != '1')
		ft_new_position(game, new_y, new_x);
    return (0);
}

// void	ft_mlx_find_player(t_mlx *p)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (p->map[y])
// 	{
// 		x = 0;
// 		while (p->map[y][x])
// 		{
// 			if (p->map[y][x] == 'P')
// 			{
// 				p->player_x = x;
// 				p->player_y = y;
// 				return ;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	p->player_x = 0;
// 	p->player_y = 0;
// 	return ;
// }
