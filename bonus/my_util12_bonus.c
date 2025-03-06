/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_util12_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:13:21 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/06 13:23:02 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_map_failure(int fd, char *map, char *buffer, int sign)
{
	perror("Error\nEmpty file\nOr Empty line\n");
	if (buffer)
	{
		if (buffer[0] == '\n')
			free(buffer);
	}
	else if (!sign)
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
}

void	map_validation(t_game *game, char *file)
{
	if (ft_extention_check(file))
	{
		perror("Error\nInvalid file extension. File must end with '.ber'\n");
		ft_finish_free(game->ft_mlx);
		exit(1);
	}
	if (collectibles_check(game))
	{
		perror("Error\nNot a valid map\n");
		ft_finish_free(game->ft_mlx);
		exit(1);
	}
	ft_find_player(game);
	ft_flood_fill(game->map_cpy, game->y, game->x);
	if (ft_map_check(game->map_cpy))
	{
		perror("Error\nNot a valid map\n");
		ft_finish_free(game->ft_mlx);
		exit(1);
	}
	ft_find_player(game);
}

void	ft_failing(t_game *game, int sign)
{
	if (sign == 1)
	{
		perror("Error\ninitializing MLX\n");
		ft_finish_free(game->ft_mlx);
		exit(1);
	}
	if (sign == 2)
	{
		perror("Error\nloading images\n");
		ft_finish_free(game->ft_mlx);
		exit(1);
	}
	if (sign == 3)
	{
		ft_putstr("Error openning the window\n");
		ft_finish_free(game->ft_mlx);
		exit(1);
	}
}

void	ft_set_images(t_game *game)
{
	game->ft_mlx->coin = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr,
			"./textures/coin.xpm",
			&game->ft_mlx->map_width, &game->ft_mlx->map_height);
	game->ft_mlx->wall = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr,
			"./textures/wall.xpm",
			&game->ft_mlx->map_width, &game->ft_mlx->map_height);
	game->ft_mlx->ground = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr,
			"./textures/ground.xpm",
			&game->ft_mlx->map_width, &game->ft_mlx->map_height);
	game->ft_mlx->exit = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr,
			"./textures/exit.xpm",
			&game->ft_mlx->map_width, &game->ft_mlx->map_height);
	game->ft_mlx->player = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr,
			"./textures/player.xpm",
			&game->ft_mlx->map_width, &game->ft_mlx->map_height);
	game->ft_mlx->enemy = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr,
			"./textures/enemy.xpm",
			&game->ft_mlx->map_width, &game->ft_mlx->map_height);
}
