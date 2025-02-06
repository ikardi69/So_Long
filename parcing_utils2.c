/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:32:28 by mteffahi          #+#    #+#             */
/*   Updated: 2025/02/05 17:56:48 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	col_check_helper(t_game *p)
{
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
	int j;
	int i;

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

void	ft_finish_free(t_game *r)
{
	int	i;

	i = 0;
	while (r->map[i])
	{
		free(r->map[i]);
		i++;
	}
	free(r->map);
	i = 0;
	while (r->map_cpy[i])
	{
		free(r->map_cpy[i]);
		i++;
	}
	free(r->map_cpy);
	free(r);
}

void	ft_maplen(t_game *f_map)
{
	f_map->x = ft_strlen(f_map->map[0]);
	f_map->y = 0;
	while (f_map->map[f_map->y])
		f_map->y++;
}
