/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikardi <ikardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:19:56 by mteffahi          #+#    #+#             */
/*   Updated: 2025/01/29 00:27:27 by ikardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		size;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (free(s1), s1 = NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(size + 1);
	if (!result)
		return (free(s1), s1 = NULL);
	ft_memcpy(result, s1, ft_strlen(s1));
	ft_memcpy(result + ft_strlen(s1), s2, ft_strlen(s2));
	result[size] = '\0';
	return (free(s1), s1 = NULL, result);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dptr;
	const unsigned char	*sptr;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dptr = (unsigned char *)dest;
	sptr = (const unsigned char *)src;
	if (dptr == sptr)
		return (dptr);
	while (i < n)
	{
		dptr[i] = sptr[i];
		i++;
	}
	return (dest);
}

char	*ft_nl(char *buffer)
{
	int		i;
	char	*bf;
	int		j;
	int		nl;

	i = 0;
	j = 1;
	nl = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		nl = 1;
		j = 2;
	}
	bf = (char *)malloc(i + j);
	if (!bf)
		return (NULL);
	return (ft_inc(bf, buffer, nl, i));
}
