/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_util7_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:25:05 by ikardi            #+#    #+#             */
/*   Updated: 2025/02/23 16:45:00 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


int ft_extention_check(char *file)
{
	int i;

	i = 0;
	while (file[i] && file[i] != '.')
		i++;
	if (!file[i])
		return (1);
	if (ft_strncmp(file + i, ".ber", ft_strlen(file + i) != 0))
		return (1);
	return (0);
}

int	ft_rowslen(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}
void	ft_print_map(char **map2)
{

	int i = -1;
	while (map2[++i] != NULL)
		printf("%s\n", map2[i]);
}

void	ft_flood_fill(char **map, int y, int x)
{
	if (y < 0 || x < 0 || !map[y] || !map[y][x])
		return ;
	if (map[y][x] == '0' || map[y][x] == 'P' || map[y][x] == 'E' || map[y][x] == 'C' || map[y][x] == 'N')
	{
		if (map[y][x] == 'E')
		{
			map[y][x] = 'X';
			return ;
		}
		map[y][x] = 'X';
	}
	else
		return ;
	ft_flood_fill(map, y, x + 1);
	ft_flood_fill(map, y, x - 1);
	ft_flood_fill(map, y + 1, x);
	ft_flood_fill(map, y - 1, x);
}

char **ft_map_alloc(char **map)
{
	int		i;
	char	**map_cp;

	map_cp = (char **)malloc(sizeof(char *) * (ft_rowslen(map) + 1));
	if (!map_cp)
		return (NULL);
	i = 0;
	while (map[i])
		i++;
	map_cp[i] = NULL;
	return (map_cp);
}

char	**ft_map_cpy(char **map)
{
	int		y;
	char	**map_cp;

	map_cp = ft_map_alloc(map);
	if (!map_cp)
		return (NULL);
	y = -1;
	while (map[++y])
	{
		map_cp[y] = ft_strdup(map[y]);
		if (!map_cp[y])
			return (free_a_map(map_cp, y), NULL);
	}
	return (map_cp);
}
