/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_util9.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:32:28 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/06 11:30:41 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	col_check_helper(t_game *p)
{
	int	j;
	int	i;

	j = -1;
	while (p->map_cpy[++j])
	{
		i = -1;
		while (p->map_cpy[j][++i])
		{
			if (p->map_cpy[j][i] != '1' && p->map_cpy[j][i] != '0'
				&& p->map_cpy[j][i] != 'P' && p->map_cpy[j][i] != 'E'
				&& p->map_cpy[j][i] != 'C' && p->map_cpy[j][i] != '\n'
				&& p->map_cpy[j][i] != '\r')
				return (1);
		}
	}
	if (p->coins <= 0)
		return (1);
	else if (p->exit != 1)
		return (1);
	else if (p->player != 1)
		return (1);
	return (0);
}

int	collectibles_check(t_game *rs)
{
	int	j;
	int	i;

	j = -1;
	rs->coins = 0;
	rs->exit = 0;
	rs->player = 0;
	while (rs->map_cpy[++j])
	{
		i = 0;
		while (rs->map_cpy[j][i])
		{
			if (rs->map_cpy[j][i] == 'C')
				rs->coins++;
			else if (rs->map_cpy[j][i] == 'E')
				rs->exit++;
			else if (rs->map_cpy[j][i] == 'P')
				rs->player++;
			i++;
		}
	}
	if (col_check_helper(rs))
		return (1);
	else
		return (0);
}

static void	ft_mlx_free(t_mlx *game)
{
	if (game->wall)
		mlx_destroy_image(game->mlx_ptr, game->wall);
	if (game->coin)
		mlx_destroy_image(game->mlx_ptr, game->coin);
	if (game->ground)
		mlx_destroy_image(game->mlx_ptr, game->ground);
	if (game->exit)
		mlx_destroy_image(game->mlx_ptr, game->exit);
	if (game->player)
		mlx_destroy_image(game->mlx_ptr, game->player);
	if (game->win_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
	}
	if (game->mlx_ptr)
		free(game->mlx_ptr);
}

void	ft_finish_free(t_mlx *r)
{
	int	i;

	i = 0;
	close(r->ft_game->fd);
	while (r->ft_game->map[i])
	{
		free(r->ft_game->map[i]);
		i++;
	}
	free(r->ft_game->map);
	i = 0;
	while (r->ft_game->map_cpy[i])
	{
		free(r->ft_game->map_cpy[i]);
		i++;
	}
	free(r->ft_game->map_cpy);
	ft_mlx_free(r->ft_game->ft_mlx);
	free(r->ft_game);
	free(r);
}

void	ft_maplen(t_mlx *f_map)
{
	f_map->x = ft_strlen(f_map->map[0]);
	f_map->y = 0;
	while (f_map->map[f_map->y])
		f_map->y++;
}
