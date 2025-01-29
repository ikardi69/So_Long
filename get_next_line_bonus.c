/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikardi <ikardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:20:00 by mteffahi          #+#    #+#             */
/*   Updated: 2025/01/28 23:16:04 by ikardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_next_line(char *buffer)
{
	char	*rem;
	int		i;
	int		j;

	if (!buffer)
		return (free(buffer), buffer = NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		return (free(buffer), buffer = NULL);
	j = ft_strlen(buffer) - i;
	rem = (char *)malloc(j + 1);
	if (!rem)
		return (free(buffer), buffer = NULL);
	j = 0;
	i++;
	while (buffer[i])
		rem[j++] = buffer[i++];
	rem[j] = '\0';
	return (free(buffer), rem);
}

char	*ft_inc(char *bf, char *buffer, int nl, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		bf[j] = buffer[j];
		j++;
	}
	if (nl)
	{
		bf[i] = '\n';
		i++;
	}
	bf[i] = '\0';
	return (bf);
}

static int	ft_nl_check(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_reading(char *buffer, char *remainder, int fd)
{
	int	rd;

	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd <= 0)
			break ;
		buffer[rd] = '\0';
		remainder = ft_strjoin(remainder, buffer);
		if (!remainder)
			return (free(buffer), buffer = NULL);
		if (ft_nl_check(remainder))
			break ;
	}
	if (rd < 0)
		return (free(remainder), NULL);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder[10240];
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(remainder[fd]), NULL);
	remainder[fd] = ft_reading(buffer, remainder[fd], fd);
	free(buffer);
	buffer = NULL;
	if (!remainder[fd])
		return (NULL);
	line = ft_nl(remainder[fd]);
	if (!line)
		return (free(remainder[fd]), remainder[fd] = NULL);
	remainder[fd] = ft_next_line(remainder[fd]);
	return (line);
}
