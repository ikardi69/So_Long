/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_util9_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:32:28 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/03 14:13:47 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	col_check_helper(t_game *p)
{
	if (p->coins <= 0)
		return (1);
	else if (p->exit != 1)
		return (1);
	else if (p->player != 1)
		return (1);
	else if (p->enemy <= 0)
		return (1);
	return (0);
}

int	collectibles_check(t_game *rs)
{
	int	j;
	int	i;

	j = -1;
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
			else if (rs->map_cpy[j][i] == 'N')
				rs->enemy++;
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
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
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
	if (game->enemy)
		mlx_destroy_image(game->mlx_ptr, game->enemy);
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
	ft_lstclear(&(r->ft_game->enemies_location));
	ft_mlx_free(r);
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
