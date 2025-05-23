/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_util10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:55:19 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/06 13:32:31 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_failing(t_game *game, int sign)
{
	if (sign == 1)
	{
		perror("Error initializing MLX\n");
		ft_finish_free(game->ft_mlx);
		exit(1);
	}
	if (sign == 2)
	{
		perror("Error loading textures\n");
		ft_finish_free(game->ft_mlx);
		exit(1);
	}
	if (sign == 3)
	{
		perror("Error openning the window\n");
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
	return ;
}

int	ft_strlen_edited(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '\n' || s[i] == '\r')
			i++;
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

int	destroy_window(t_mlx *game)
{
	ft_putstr("You exited the game before finishing it\n");
	ft_finish_free(game);
	exit (1);
	return (0);
}
