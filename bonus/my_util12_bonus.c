/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_util12_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:13:21 by mteffahi          #+#    #+#             */
/*   Updated: 2025/02/28 12:23:33 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_map_failure(int fd, char *map, char *buffer, int sign)
{
	ft_putstr("Error\nEmpty file\nOr Empty line\n");
	if (!sign)
		free(buffer);
	close(fd);
	free(map);
	exit(1);
}

void	ft_set_variables(t_game *game)
{
	game->coins = 0;
	game->exit = 0;
	game->x = 0;
	game->y = 0;
	game->player = 0;
	game->enemy = 0;
}

void	map_validation(t_game *game, char *file)
{
	if (ft_extention_check(file))
	{
		ft_putstr("Error: Invalid file extension. File must end with '.ber'\n");
		ft_finish_free(game->ft_mlx);
		exit(1);
	}
	if (collectibles_check(game))
	{
		ft_putstr("Not a valid map\n");
		ft_finish_free(game->ft_mlx);
		exit(1);
	}
		
	ft_find_player(game);
	ft_flood_fill(game->map_cpy, game->y, game->x);
	if (ft_map_check(game->map_cpy))
	{
		ft_putstr("Not a valid map\n");
		ft_finish_free(game->ft_mlx);
		exit(1);
	}
	ft_find_player(game);
}

void	ft_failing(t_game *game, int sign)
{
	if (sign == 1)
	{
		ft_putstr("Error initializing MLX\n");
		ft_finish_free(game->ft_mlx);
		exit(1);
	}
	if (sign == 2)
	{
		ft_putstr("Error loading images\n");
		ft_finish_free(game->ft_mlx);
		exit(1);
	}
}

void	ft_set_images(t_game *game)
{
	game->ft_mlx->coin = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr,
			"./bonus/images/coin.xpm",
			&game->ft_mlx->map_width, &game->ft_mlx->map_height);
	game->ft_mlx->wall = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr,
			"./bonus/images/wall.xpm",
			&game->ft_mlx->map_width, &game->ft_mlx->map_height);
	game->ft_mlx->ground = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr,
			"./bonus/images/ground.xpm",
			&game->ft_mlx->map_width, &game->ft_mlx->map_height);
	game->ft_mlx->exit = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr,
			"./bonus/images/exit.xpm",
			&game->ft_mlx->map_width, &game->ft_mlx->map_height);
	game->ft_mlx->player = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr,
			"./bonus/images/player.xpm",
			&game->ft_mlx->map_width, &game->ft_mlx->map_height);
	game->ft_mlx->enemy = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr,
			"./bonus/images/enemy.xpm",
			&game->ft_mlx->map_width, &game->ft_mlx->map_height);
}
