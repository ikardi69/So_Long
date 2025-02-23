/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_util11_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:19:18 by mteffahi          #+#    #+#             */
/*   Updated: 2025/02/23 16:46:21 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static size_t	nbr_size(long n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char	*ft_zero(char *r)
{
	r = (char *)malloc(2);
	if (!r)
		return (NULL);
	r[0] = '0';
	r[1] = '\0';
	return (r);
}

static	char	*conv_nb(long nbr, char *r, size_t size, int sign)
{
	r[size] = '\0';
	size--;
	while (nbr != 0)
	{
		r[size] = nbr % 10 + 48;
		nbr /= 10;
		size--;
	}
	if (sign == -1)
		r[size] = '-';
	return (r);
}

char	*ft_itoa(int n)
{
	size_t	size;
	long	nbr;
	char	*r;
	int		sign;

	nbr = n;
	size = 0;
    sign = 1;
	r = NULL;
	if (nbr == 0)
		return (r = ft_zero(r));
	if (n < 0)
	{
		sign = -1;
		nbr *= -1;
		size = nbr_size(nbr) + 1;
	}
	else
		size = nbr_size(nbr);
	r = (char *)malloc((size + 1));
	if (!r)
		return (NULL);
	return (conv_nb(nbr, r, size, sign));
}

int	movment_string(t_mlx *game)
{
	char	*str;
	char	*nb;
	char	*join;

	str = (char *)malloc((ft_strlen("Moves: ") + 1));
	if (!str)
		return (1);
	ft_strlcpy(str, "Moves: ", ft_strlen("Moves: ") + 1);
	nb = ft_itoa(game->moves_count);
	if (!nb)
		return (free(str), 1);
	join = ft_strjoin(str, nb);
	if (!join)
		return (free(nb), 1);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 47, 35, 0xFFFFFF, join);
	mlx_string_put(game->mlx_ptr, game->win_ptr, (47 + 1), 35, 0xFFFFFF, join);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 47, (35 + 1), 0xFFFFFF, join);
	mlx_string_put(game->mlx_ptr, game->win_ptr, (47 + 1), (35 + 1), 0xFFFFFF, join);
	return (free(nb), free(join), 0);
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
