/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_util14_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:11:27 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/10 15:47:27 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	walls_check(char **map)
{
	int	y;
	int	len;

	y = -1;
	while (map[++y])
	{
		len = -1;
		while (map[y][++len])
		{
			if (map[y][len] == '\n' || map[y][len] == '\r')
			{
				len--;
				break ;
			}
			else if (map[y][len + 1] == '\0')
				break ;
		}
		if (map[y][len] != '1')
			return (1);
	}
	return (0);
}
