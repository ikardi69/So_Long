/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:00:41 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/03 14:21:46 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

	buffer = NULL;
	map = get_next_line(fd);
	if (!map || map[0] == '\n')
		return (get_map_failure(fd, map, buffer = NULL, 1), NULL);
	buffer = get_next_line(fd);
	if (!buffer || buffer[0] == '\n')
		return (get_map_failure(fd, map, buffer = NULL, 1), NULL);
	while (buffer)
	{
		map = ft_strjoin(map, buffer);
		if (buffer[0] == '\n')
			return (get_map_failure(fd, map, buffer, 0), NULL);
		free(buffer);
		buffer = get_next_line(fd);
	}
	result = ft_split(map, '\n');
	if (!result)
		return (free(map), NULL);
	return (free(map), result);
}

void	ft_find_player(t_game *p)
{
	int	i;
	int	j;

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
				p->ft_mlx->player_y = i;
				p->ft_mlx->player_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

t_game	*ft_struct(int fd)
{
	t_game	*r;

	r = (t_game *)malloc(sizeof(t_game));
	if (!r)
		return (NULL);
	r->ft_mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!r->ft_mlx)
		return (free(r), NULL);
	r->fd = fd;
	ft_set_variables(r);
	r->map = ft_get_map(fd);
	if (!r->map)
		return (free(r->ft_mlx), free(r), NULL);
	r->map_cpy = ft_map_cpy(r->map);
	if (!r->map_cpy)
		return (free_a_map(r->map, 0), free(r->ft_mlx), free(r), NULL);
	r->enemies_location = ft_set_the_head();
	if (!r->enemies_location)
		return (free_a_map(r->map_cpy, 0), free_a_map(r->map, 0),
			free(r->ft_mlx), free(r), NULL);
	r->ft_mlx = ft_mlx_struct(r);
	return (r);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*p;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_putstr("Error\nUnable to open file"), 1);
	p = ft_struct(fd);
	if (!p)
		return (close(fd), 1);
	map_validation(p, argv[1]);
	ft_set_enemies_location(p);
	ft_open_window(p);
	return (ft_finish_free(p->ft_mlx), 0);
}
