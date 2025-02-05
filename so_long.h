/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:25:21 by mteffahi          #+#    #+#             */
/*   Updated: 2025/02/05 14:11:12 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../mlx/mlx.h"
#include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# define LL_MAX 9223372036854775807LL

typedef struct s_palyer
{
	int		x;
	int		y;
	int		coins;
	int		exit;
	int		player;
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	char	**map_cpy;
}t_player;

char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
int 		ft_strlen(const char *s);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_nl(char *buffer);
char		*ft_inc(char *bf, char *remainder, int nl, int i);
int     	ft_atoi(const char *str);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
int     	ft_strncmp(const char *s1, const char *s2, size_t n);
int     	len_check(char *const *map);
char    	**ft_fail_free(char **s);
void		ft_print_map(char **map);
char		**ft_map_cpy(char **map);
void		ft_find_player(t_player *p);
void		ft_flood_fill(char **map, int y, int x);
int     	ft_map_check(char **map);
int     	ft_rows_len_check(char **map);
int			collectibles_check(t_player *rs);
t_player	*ft_struct(int fd);
void		ft_finish_free(t_player *r);
void		ft_maplen(t_player *f_map);
void		ft_open_window(t_player *game);
int			handle_keypress(int keycode, t_player *game);

#endif
