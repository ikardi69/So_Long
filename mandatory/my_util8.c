/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_util8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:14:25 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/10 15:31:57 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_fail_free(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static int	ft_first_last_check(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y][x])
	{
		if (map[y][x] != '1' && map[y][x] != '\n' && map[y][x] != '\r')
			return (1);
		x++;
	}
	while (map[y])
		y++;
	y--;
	x = 0;
	while (map[y][x])
	{
		if (map[y][x] != '1' && map[y][x] != '\n' && map[y][x] != '\r')
			return (1);
		x++;
	}
	return (0);
}

static int	ft_rows_check(char **map)
{
	int	y;

	y = 0;
	if (ft_first_last_check(map))
		return (1);
	while (map[y])
	{
		if (map[y][0] != '1')
			return (1);
		else if (map[y][ft_strlen_edited(map[y]) - 1] != '1'
			&& map[y][ft_strlen(map[y]) - 1] != '\n'
			&& map[y][ft_strlen(map[y]) - 1] != '\r')
			return (1);
		y++;
	}
	return (0);
}

int	ft_map_check(char **map)
{
	int	x;
	int	y;

	y = 0;
	if (ft_rows_check(map) || ft_rows_len_check(map) || walls_check(map))
		return (1);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'P' || map[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_rows_len_check(char **map)
{
	int	y;
	int	len;

	y = 0;
	len = ft_strlen_edited(map[y]);
	while (map[y])
	{
		if (ft_strlen_edited(map[y]) != len)
			return (1);
		y++;
	}
	return (0);
}
