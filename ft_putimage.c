/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putimage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:45:01 by mteffahi          #+#    #+#             */
/*   Updated: 2025/02/12 18:21:03 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_open_window(t_game *game)
{
	game->ft_mlx->mlx_ptr = mlx_init();
	// printf("y = %d, x = %d\n", game->player_y, game->player_x);
	if (!game->ft_mlx->mlx_ptr)
	{
		write(1, "Error initializing MLX\n", 23);
		return;
	}
	game->ft_mlx->coin = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr, "./images/coin.xpm", &game->ft_mlx->map_width, &game->ft_mlx->map_height);
	game->ft_mlx->wall = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr, "./images/wall.xpm", &game->ft_mlx->map_width, &game->ft_mlx->map_height);
	game->ft_mlx->ground = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr, "./images/ground.xpm", &game->ft_mlx->map_width, &game->ft_mlx->map_height);
	game->ft_mlx->exit = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr, "./images/exit.xpm", &game->ft_mlx->map_width, &game->ft_mlx->map_height);
	game->ft_mlx->player = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr, "./images/player.xpm", &game->ft_mlx->map_width, &game->ft_mlx->map_height);
	if (!game->ft_mlx->coin || !game->ft_mlx->wall || !game->ft_mlx->ground || !game->ft_mlx->exit || !game->ft_mlx->player)
	{
		write(1, "Error loading images\n", 21);
		return;
	}
	ft_maplen(game->ft_mlx);
	game->ft_mlx->x *= TILE_SIZE;
	game->ft_mlx->y *= TILE_SIZE;
	game->ft_mlx->win_ptr = mlx_new_window(game->ft_mlx->mlx_ptr, game->ft_mlx->x, game->ft_mlx->y, "So_long");
	printf("he x = %d, y = %d\n", game->ft_mlx->player_x, game->ft_mlx->player_y);
	mlx_key_hook(game->ft_mlx->win_ptr , handle_keypress, (void *)game->ft_mlx);
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
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
	}
	
}

static void	ft_new_position(t_mlx *game, int new_y, int new_x)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_y = new_y;
	game->player_x = new_x;
	game->moves_count++;
	write(1, "Moves: ", 7);
	ft_putnbr(game->moves_count);
	ft_putstr("\n");
	ft_render_map(game);
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
		return (mlx_destroy_window(game->mlx_ptr, game->win_ptr), exit(0), 1);
		// exit(0);
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
