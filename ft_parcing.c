/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:00:41 by mteffahi          #+#    #+#             */
/*   Updated: 2025/02/01 15:55:02 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len_check(char *const *map)
{
	int	j;

	j = 0;
	while (map[j])
	{
		if (map[j + 1] != NULL && ft_strlen(map[j]) != ft_strlen(map[j + 1]))
			return (1);
		j++;
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

t_player	*ft_struct(int fd)
{
	t_player	*r;

	r = (t_player *)malloc(sizeof(t_player));
	if (!r)
		return (NULL);
	r->coins = 0;
	r->exit = 0;
	r->x = 0;
	r->y = 0;
	r->map = ft_get_map(fd);
	if (!r->map)
		return (free(r), NULL);
	r->map_cpy = ft_map_cpy(r->map);
	if (!r->map_cpy)
		return (free(r), NULL);
	return (r);
}

int main(int argc, char **argv)
{
	int			fd;
	t_player 	*p;
	
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (write(1, "Error\nUnable to open file", 26), 1);
	p = ft_struct(fd);
	if (!p)
		return (1);
	ft_find_player(p);
	ft_print_map(p->map);
	printf("\n");
	if (collectibles_check(p))
		return (write(1, "Not a valid map\n", 17), ft_finish_free(p), close(fd), 0);
	ft_flood_fill(p->map_cpy, p->y, p->x);
	ft_print_map(p->map_cpy);
	if (ft_map_check(p->map_cpy))
		return (write(1, "Not a valid map\n", 17), ft_finish_free(p), close(fd), 0);
	else
		printf("vaalid\n");
	return (close(fd), ft_finish_free(p), 0);
}
