/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_util10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:55:19 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/03 13:20:11 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			"./images/coin.xpm",
			&game->ft_mlx->map_width, &game->ft_mlx->map_height);
	game->ft_mlx->wall = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr,
			"./images/wall.xpm",
			&game->ft_mlx->map_width, &game->ft_mlx->map_height);
	game->ft_mlx->ground = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr,
			"./images/ground.xpm",
			&game->ft_mlx->map_width, &game->ft_mlx->map_height);
	game->ft_mlx->exit = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr,
			"./images/exit.xpm",
			&game->ft_mlx->map_width, &game->ft_mlx->map_height);
	game->ft_mlx->player = mlx_xpm_file_to_image(game->ft_mlx->mlx_ptr,
			"./images/player.xpm",
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
