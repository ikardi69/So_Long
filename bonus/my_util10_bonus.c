/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_util10_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:24:24 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/06 13:24:59 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	update_enemy(t_mlx *game)
{
	static int	frames = 0;
	t_enemy		*tmp;

	tmp = game->ft_game->enemies_location;
	tmp = tmp->next;
	frames++;
	if (movment_string(game))
	{
		perror("Error\nallocation failed");
		ft_finish_free(game);
		exit(1);
	}
	if (frames % 9009 == 0)
	{
		while (tmp)
		{
			ft_enemy_movment(game, tmp);
			tmp = tmp->next;
		}
		ft_render_map(game);
	}
	return (0);
}

t_enemy	*ft_add_location(int y, int x)
{
	t_enemy	*node;

	node = (t_enemy *)malloc(sizeof(t_enemy));
	if (!node)
		return (NULL);
	node->y = y;
	node->x = x;
	node->next = NULL;
	return (node);
}

void	ft_set_enemies_location(t_game *game)
{
	t_enemy	*n_e;
	int		y;
	int		x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'N')
			{
				n_e = ft_add_location(y, x);
				ft_lstadd_back(&(game->enemies_location), n_e);
			}
			x++;
		}
		y++;
	}
}

void	ft_lstadd_back(t_enemy **lst, t_enemy *new)
{
	t_enemy	*tmp;

	if (!new || !lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

t_enemy	*ft_set_the_head(void)
{
	t_enemy	*head;

	head = (t_enemy *)malloc(sizeof(t_enemy));
	if (!head)
		return (NULL);
	head->y = 0;
	head->x = 0;
	head->next = NULL;
	return (head);
}
