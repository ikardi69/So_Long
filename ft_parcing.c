/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikardi <ikardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:45:29 by ikardi            #+#    #+#             */
/*   Updated: 2025/01/29 01:00:48 by ikardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_mapcheck(char **map, int full_map_size)
{
	int	x;
	int	y;
	int	map_int[full_map_size];
	int	f_mp;

	x = 0;
	y = 0;
	f_mp = 0;
	while (map[y])
	{
		map_int[f_mp] = ft_atoi(map[y]);
		printf("%d\n", map_int[f_mp]);
		f_mp++;
		y++;
	}
	
}

int	main(int argc, char **argv)
{
	char	*map[10240];
	int		fd_map;
	int		map_i;
	int		full_map_size;
	if (argc != 2)
		return (perror("Error\nToo many arguments"), 1);
	fd_map = open(argv[1], O_RDONLY);
	if (fd_map < 0)
		return (perror("Error\nUnable to open file"), 1);
	map_i = 0;
	full_map_size = 0;
	while (map[map_i] = get_next_line(fd_map))
	{
		printf("%s", map[map_i]);
		map_i++;
		full_map_size++;
	}
	printf("\n");
	ft_mapcheck(map, full_map_size);
	map_i = 0;
	while (map[map_i])
	{
		free(map[map_i]);
		map_i++;
	}
	return 0;
}
