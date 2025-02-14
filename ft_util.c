/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:28:12 by mteffahi          #+#    #+#             */
/*   Updated: 2025/02/14 12:55:13 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx	*ft_mlx_struct(t_game *r)
{
	// t_mlx	*m;

	// m = (t_mlx *)malloc(sizeof(t_mlx));
	// if (!m)
	// 	return (NULL);
	r->ft_mlx->map = r->map;
	ft_find_player(r);
	r->ft_mlx->coin_count = 0;
	r->ft_mlx->moves_count = 0;
	r->ft_mlx->player_x = 0;  // Initialize to 0 temporarily
	r->ft_mlx->player_y = 0;
	r->ft_mlx->map_height = ft_rows_len_check(r->ft_mlx->map);
	r->ft_mlx->map_width = ft_strlen(r->ft_mlx->map[0]);
	r->ft_mlx->win_ptr = NULL;
	r->ft_mlx->mlx_ptr = NULL; 		//mlx_init();
	r->ft_mlx->coin = NULL;			//mlx_xpm_file_to_image(m->mlx_ptr, "../images/coin.xpm", &m->map_width, &m->map_height);
	r->ft_mlx->wall = NULL;			//mlx_xpm_file_to_image(m->mlx_ptr, "../images/wall.xpm", &m->map_width, &m->map_height);
	r->ft_mlx->ground = NULL;		//mlx_xpm_file_to_image(m->mlx_ptr, "../images/ground.xpm", &m->map_width, &m->map_height);
	r->ft_mlx->exit = NULL;			//mlx_xpm_file_to_image(m->mlx_ptr, "../images/exit.xpm", &m->map_width, &m->map_height);
	r->ft_mlx->player = NULL;		//mlx_xpm_file_to_image(m->mlx_ptr, "../images/player.xpm", &m->map_width, &m->map_height);
	r->ft_mlx->ft_game = r;
	return (r->ft_mlx);
}
