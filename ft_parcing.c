/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:00:41 by mteffahi          #+#    #+#             */
/*   Updated: 2025/01/31 18:23:56 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len_check(char *const *map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		if (map[y + 1] != NULL && ft_strlen(map[y]) != ft_strlen(map[y + 1]))
			return (1);
		y++;
	}
	return (0);
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

void	ft_find_player(t_player *p)
{
	int i;
	int j;

	i = 0;
	while (p->map[i])
	{
		j = 0;
		while (p->map[i][j])
		{
			if (p->map[i][j] == 'P')
			{
				p->x = j;
				p->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	int			fd;
	char		**map;
	char		**map2;
	t_player 	p;
	t_resources	rs;
	
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (write(1, "Error\nUnable to open file", 26), 1);
	map = ft_get_map(fd);
	if (!map)
		return (1);
	map2 = ft_map_cpy(map);
	if (!map2)
		return (ft_fail_free(map), 1);
	p.map = map2;
	ft_find_player(&p);
	ft_print_map(map2);
	printf("\n");
	if (collectibles_check(&rs, map2))
		return (write(1, "Not a valid map\n", 17), ft_fail_free(map), ft_fail_free(map2), close(fd), 0);
	ft_flood_fill(map2, p.y, p.x);
	ft_print_map(map2);
	if (ft_map_check(map2))
		return (write(1, "Not a valid map\n", 17), ft_fail_free(map), ft_fail_free(map2), close(fd), 0);
	else
		printf("vaalid\n");
	return (ft_fail_free(map), ft_fail_free(map2), close(fd), 0);
}
