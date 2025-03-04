/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_util4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:28:12 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/04 11:04:40 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx	*ft_mlx_struct(t_game *r)
{
	r->ft_mlx->map = r->map;
	ft_find_player(r);
	r->ft_mlx->coin_count = 0;
	r->ft_mlx->moves_count = 0;
	r->ft_mlx->player_x = 0;
	r->ft_mlx->player_y = 0;
	r->ft_mlx->map_height = ft_rows_len_check(r->ft_mlx->map);
	r->ft_mlx->map_width = ft_strlen(r->ft_mlx->map[0]);
	r->ft_mlx->win_ptr = NULL;
	r->ft_mlx->mlx_ptr = NULL;
	r->ft_mlx->coin = NULL;
	r->ft_mlx->wall = NULL;
	r->ft_mlx->ground = NULL;
	r->ft_mlx->exit = NULL;
	r->ft_mlx->player = NULL;
	r->ft_mlx->ft_game = r;
	return (r->ft_mlx);
}

int	ft_coins_e_check(t_mlx *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
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

void	get_map_failure(int fd, char *map, char *buffer, int sign)
{
	perror("Error\nEmpty file\nOr Empty line\n");
	if (buffer[0] == '\n')
		free(buffer);
	else if (!sign)
		free(buffer);
	close(fd);
	free(map);
	exit(1);
}
