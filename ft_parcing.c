/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:00:41 by mteffahi          #+#    #+#             */
/*   Updated: 2025/01/29 18:18:51 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	len_check(char *const *map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		if (map[y + 1] != NULL && ft_strlen(map[y]) != ft_strlen(map[y + 1]))
			return (write(1, "not valid\n", 10), 1);
		y++;
	}
	return (0);
}

int	ft_map_check(char *const *map)
{
	int	x;
	int	y;

	y = 0;
	if (len_check(map))
		return (write(1, "not valid\n", 10), 1);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P' && map[y - 1][x] == '1' && map[y][x - 1] == '1'
				&& map[y + 1][x] == '1' && map[y][x + 1] == '1')
				return (write(1, "not valid\n", 11), 1);
			if (y == 0 && map[y][x] != '1')
				return (write(1, "not valid\n", 11), 1);
			x++;
		}
		y++;
	}
	return (write(1, "valid :D\n", 10), 0);
}

char	**ft_get_map(int fd)
{
	char	*map;
	char	*buffer;
	char	**result;

	map = get_next_line(fd);
	if (!map)														// Handling empty file
		return (close(fd), write(1, "Error\nEmpty file\n", 18), NULL);
	while ((buffer = get_next_line(fd)) != NULL)
	{
		map = ft_strjoin(map, buffer);
		free(buffer);
	}
	result = ft_split(map, '\n');
	if (!result)
		return (NULL);
	return (free(map), result);
}

int main(int argc, char **argv)
{
	int		fd;
	char	**map;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (write(1, "Error\nUnable to open file", 26), 1);
	map = ft_get_map(fd);
	if (!map)
		return (1);
	ft_map_check(map);
	int i = 0;
	while (map[i] != NULL)
	{
		printf("%s\n", map[i]);
		free(map[i]);
		i++;
	}
	free(map);
	return (close(fd), 0);
}
