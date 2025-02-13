/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:28:12 by mteffahi          #+#    #+#             */
/*   Updated: 2025/02/12 15:36:16 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx	*ft_mlx_struct(t_game *r)
{
	t_mlx	*m;

	m = (t_mlx *)malloc(sizeof(t_mlx));
	if (!m)
		return (NULL);
	m->map = r->map;
	ft_find_player(r);
	m->coin_count = 0;
	m->moves_count = 0;
	m->player_x = 0;  // Initialize to 0 temporarily
	m->player_y = 0;
	m->map_height = ft_rows_len_check(m->map);
	m->map_width = ft_strlen(m->map[0]);
	m->win_ptr = NULL;
	m->mlx_ptr = NULL; 		//mlx_init();
	m->coin = NULL;			//mlx_xpm_file_to_image(m->mlx_ptr, "../images/coin.xpm", &m->map_width, &m->map_height);
	m->wall = NULL;			//mlx_xpm_file_to_image(m->mlx_ptr, "../images/wall.xpm", &m->map_width, &m->map_height);
	m->ground = NULL;		//mlx_xpm_file_to_image(m->mlx_ptr, "../images/ground.xpm", &m->map_width, &m->map_height);
	m->exit = NULL;			//mlx_xpm_file_to_image(m->mlx_ptr, "../images/exit.xpm", &m->map_width, &m->map_height);
	m->player = NULL;		//mlx_xpm_file_to_image(m->mlx_ptr, "../images/player.xpm", &m->map_width, &m->map_height);
	return (m);
}
