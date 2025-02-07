/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putimage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:45:01 by mteffahi          #+#    #+#             */
/*   Updated: 2025/02/07 18:27:52 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_open_window(t_mlx *game)
{
	game->mlx_ptr = mlx_init();
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

int handle_keypress(int keycode, t_game *game)
{
    if (keycode == 53)  // ESC key
	{
        mlx_destroy_window(game->ft_mlx->mlx_ptr, game->ft_mlx->win_ptr);
		exit(0);
	}
    return (0);
}

t_mlx	*ft_mlx_struct(t_game *r)
{
	t_mlx	*m;

	m = (t_mlx *)malloc(sizeof(t_mlx));
	if (!m)
		return (NULL);
	m->map = r->map;
	m->player_y = 0;
	m->player_x = 0;
	m->coin_count = 0;
	m->moves_count = 0;
	m->map_height = ft_rows_len_check(m->map);
	m->map_width = ft_strlen(m->map[0]);
	m->mlx_ptr = NULL; 		//mlx_init();
	m->coin = NULL;			//mlx_xpm_file_to_image(m->mlx_ptr, "../images/coin.xpm", &m->map_width, &m->map_height);
	m->wall = NULL;			//mlx_xpm_file_to_image(m->mlx_ptr, "../images/wall.xpm", &m->map_width, &m->map_height);
	m->ground = NULL;		//mlx_xpm_file_to_image(m->mlx_ptr, "../images/ground.xpm", &m->map_width, &m->map_height);
	m->exit = NULL;			//mlx_xpm_file_to_image(m->mlx_ptr, "../images/exit.xpm", &m->map_width, &m->map_height);
	m->player = NULL;		//mlx_xpm_file_to_image(m->mlx_ptr, "../images/player.xpm", &m->map_width, &m->map_height);
	return (m);
}
