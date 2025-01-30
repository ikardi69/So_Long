/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:00:41 by mteffahi          #+#    #+#             */
/*   Updated: 2025/01/30 19:33:24 by mteffahi         ###   ########.fr       */
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

typedef struct s_palyer
{
	int x;
	int y;
	char **map;
}t_player;

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

void	ft_print_map(char **map);
char	**ft_map_cpy(char **map);
void	ft_find_player(t_player *p);
void	ft_flood_fill(char **map, int y, int x);

int main(int argc, char **argv)
{
	int		fd;
	char	**map;
	t_player p;
	
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (write(1, "Error\nUnable to open file", 26), 1);
	map = ft_get_map(fd);
	if (!map)
		return (1);
	// ft_map_check(map);
	char **map2 = ft_map_cpy(map);
	p.map = map2;
	ft_find_player(&p);
	// printf("Player x = %d y = %d\n", p.x, p.y);
	ft_flood_fill(map2, p.y, p.x);
	ft_print_map(map2);
	free(map);
	free(map2);
	return (close(fd), 0);
}
