/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikardi <ikardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:25:21 by mteffahi          #+#    #+#             */
/*   Updated: 2025/01/29 00:15:04 by ikardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# define LL_MAX 9223372036854775807LL

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t  ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_nl(char *buffer);
char	*ft_inc(char *bf, char *remainder, int nl, int i);
int     ft_atoi(const char *str);

#endif
