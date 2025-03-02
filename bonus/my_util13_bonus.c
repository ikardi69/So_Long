/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_util13_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:31:22 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/02 11:19:46 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_img_ptr(t_mlx *mlx, char c, void **img)
{
	if (c == '1')
		*img = mlx->wall;
	else if (c == '0')
		*img = mlx->ground;
	else if (c == 'C')
		*img = mlx->coin;
	else if (c == 'E' && mlx->ft_game->coins != 0)
		*img = mlx->ground;
	else if (c == 'E' && mlx->ft_game->coins == 0)
		*img = mlx->exit;
	else if (c == 'P')
		*img = mlx->player;
	else if (c == 'N')
		*img = mlx->enemy;
	else
		return ;
}

int	destroy_window(t_mlx *game)
{
	ft_putstr("You exited the game before finishing it (weak.)\n");
	ft_finish_free(game);
	exit (1);
	return (0);
}

void	ft_lstclear(t_enemy **lst)
{
	t_enemy	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srcsize;

	if (!size)
		return (ft_strlen(src));
	srcsize = ft_strlen(src);
	i = 0;
	while (i < (size -1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srcsize);
}

void	free_a_map(char **map, int size)
{
	int	i;

	i = 0;
	if (size == 0)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
		return ;
	}
	while (i < size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
