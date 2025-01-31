/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:14:25 by mteffahi          #+#    #+#             */
/*   Updated: 2025/01/30 23:31:44 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    **ft_fail_free(char **s)
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
		if (map[y][x] != '1')
			return (1);
		x++;
	}
	while (map[y])
		y++;
	y--;
	x = 0;
	while (map[y][x])
	{
		if (map[y][x] != '1')
			return (1);
		x++;
	}
	return (0);
}

static int	ft_rows_check(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (ft_first_last_check(map))
		return (1);
	while (map[y][x])
	{
		if (map[y][x] != '1')
			return (1);
		x++;
	}
	while (map[y])
	{
		if (map[y][0] != '1')
			return (1);
		else if (map[y][ft_strlen(map[y]) - 1] != '1')
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
	if (ft_rows_check(map) != 0 || ft_rows_len_check(map) != 0)
		return (ft_fail_free(map), 1);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'P' || map[y][x] == 'E')
				return (ft_fail_free(map), 1);
			x++;
		}
		y++;
	}
	return (ft_fail_free(map), 0);
}

int	ft_rows_len_check(char **map)
{
	int	y;
	int	x;
	int	len;

	x = 0;
	y = 0;
	len = ft_strlen(map[y]);
	while (map[y])
	{
		if (ft_strlen(map[y]) != len)
			return (1);
		y++;
	}
	return (0);
}
