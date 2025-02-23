/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:00:41 by mteffahi          #+#    #+#             */
/*   Updated: 2025/02/23 15:51:15 by mteffahi         ###   ########.fr       */
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
	if (!map)
		return (close(fd), ft_putstr("Error\nEmpty file\n"), NULL);
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

void	ft_find_player(t_game *p)
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
	r->coins = 0;
	r->exit = 0;
	r->x = 0;
	r->y = 0;
	r->player = 0;
	r->map = ft_get_map(fd);
	if (!r->map)
		return (free(r), NULL);
	r->map_cpy = ft_map_cpy(r->map);
	if (!r->map_cpy)
		return (free(r), NULL);
	r->ft_mlx = ft_mlx_struct(r);
	return (r);
}

void	ft_printf_ptr_adresses(t_mlx *game)
{
	printf("mlx adress : %p\n", game);
	printf("coins adress : %p\n", game->coin);
	printf("wall adress : %p\n", game->wall);
	printf("ground adress : %p\n", game->ground);
	printf("exit adress : %p\n", game->exit);
	printf("player adress : %p\n", game->player);
	printf("map adress : %p\n", game->ft_game->map);
	printf("map_cpy adress : %p\n", game->ft_game->map_cpy);
	printf("game adress : %p\n", game->ft_game);
	printf("mlx_ptr adress : %p\n", game->mlx_ptr);
	printf("mlx_win_ptr adress : %p\n", game->win_ptr);
}

int main(int argc, char **argv)
{
	int			fd;
	t_game 	*p;
	(void)argc;
	
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_putstr("Error\nUnable to open file"), 1);
	p = ft_struct(fd);
	if (!p)
		return (1);
	ft_find_player(p);
	if (collectibles_check(p))
		return (ft_putstr("Not a valid map\n"), ft_finish_free(p->ft_mlx), close(fd), 0);
	ft_flood_fill(p->map_cpy, p->y, p->x);
	if (ft_map_check(p->map_cpy))
		return (ft_putstr("Not a valid map\n"), ft_finish_free(p->ft_mlx), close(fd), 0);
	ft_find_player(p);
	ft_open_window(p);
	return (close(fd), ft_finish_free(p->ft_mlx), 0);
}
