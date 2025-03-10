/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_util11.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:05:42 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/10 15:46:57 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	walls_check(char **map)
{
	int	y;
	int	len;

	y = -1;
	while (map[++y])
	{
		len = 0;
		while (map[y][len])
			len++;
		if (map[y][len] == '\0')
		{
			len--;
			if (map[y][len] == '\n' || map[y][len] == '\r')
				len--;
		}
		if (map[y][len] != '1')
			return (1);
	}
	return (0);
}
