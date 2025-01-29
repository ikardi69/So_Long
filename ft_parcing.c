/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:00:41 by mteffahi          #+#    #+#             */
/*   Updated: 2025/01/29 17:13:54 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_get_map(int fd)
{
	char	*map;
	char	*buffer;
	char	*tmp;
	char	**result;

	map = get_next_line(fd);
	if (!map)														// Handling empty file
		return (close(fd), perror("Error\nEmpty file\n"), NULL);
	while ((buffer = get_next_line(fd)) != NULL)
	{
		tmp = map;
		map = ft_strjoin(buffer, map);
		free(tmp);
	}
	int i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			printf("newl\n");
		i++;
	}
	printf("map %s\n", map);
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
		return (perror("Error\nUnable to open file"), 1);
	map = ft_get_map(fd);
	if (!map)
		return (1);
	int i = 0;
	while (map[i] != NULL)
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("i = %d\n", i);
	free(map);
	return 0;
}
