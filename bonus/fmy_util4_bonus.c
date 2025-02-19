/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmy_util4_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:28:12 by mteffahi          #+#    #+#             */
/*   Updated: 2025/02/19 15:50:48 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_mlx	*ft_mlx_struct(t_game *r)
{
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
	r->ft_mlx->enemy = NULL;
	r->ft_mlx->ft_game = r;
	return (r->ft_mlx);
}

int	ft_coins_E_check(t_mlx *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_new_e_position_check(t_mlx *game, t_enemy *en, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'P')
		ft_looser_function(game);
	else if (game->map[new_y][new_x] != '1' && game->map[new_y][new_x] != 'E')
	{
		game->map[en->y][en->x] = '0';
		game->map[new_y][new_x] = 'N';
		en->x = new_x;
		en->y = new_y;
	}
	else if (game->map[new_y][new_x] == '1')
		ft_enemy_movment(game, en);
}

void	ft_enemy_movment(t_mlx *game, t_enemy *en)
{
	int			new_x;
	int			new_y;
	static int	step = 0;

	new_x = en->x;
	new_y = en->y;
	if (step == 0)
		new_x++;
	else if (step == 3)
		new_y--;
	else if (step == 1)
		new_y++;
	else if (step == 2)
		new_x--;
	// else if (step == 4)
	// 	new_y--;
	if (game->map[new_y][new_x] != '1')
	{
		ft_new_e_position_check(game, en, new_x, new_y);
		// step++;
		// return ;
	}
	// else
	// {
	// 	step = (step + 1) % 4;
	// }
	// step = (step + 1) % 4;
	step = (step + 1) % 3;
}
