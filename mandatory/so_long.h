/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:25:21 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/08 16:57:14 by mteffahi         ###   ########.fr       */
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
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# define LL_MAX 9223372036854775807LL

# define TILE_SIZE 50

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;

	int				map_width;
	int				map_height;
	int				x;
	int				y;

	char			**map;
	void			*wall;
	void			*ground;
	void			*coin;
	void			*exit;
	void			*player;
	int				player_x;
	int				player_y;
	int				coin_count;
	int				moves_count;
	struct s_game	*ft_game;
}t_mlx;

typedef struct s_game
{
	int				x;
	int				y;
	int				coins;
	int				exit;
	int				player;
	int				fd;
	char			**map;
	char			**map_cpy;
	struct s_mlx	*ft_mlx;
}t_game;

char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(const char *s);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_nl(char *buffer);
char		*ft_inc(char *bf, char *remainder, int nl, int i);
int			ft_atoi(const char *str);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			len_check(char *const *map);
char		**ft_fail_free(char **s);
char		**ft_map_cpy(char **map);
void		ft_find_player(t_game *p);
void		ft_flood_fill(char **map, int y, int x);
int			ft_map_check(char **map);
int			ft_rows_len_check(char **map);
int			collectibles_check(t_game *rs);
t_game		*ft_struct(int fd);
t_mlx		*ft_mlx_struct(t_game *r);
void		ft_finish_free(t_mlx *r);
void		ft_maplen(t_mlx *f_map);
void		ft_open_window(t_game *game);
int			handle_keypress(int keycode, t_mlx *game);
void		ft_render_map(t_mlx	*mlx);
void		ft_putnbr(int n);
void		ft_putstr(char *s);
void		ft_putchar(char c);
int			ft_coins_e_check(t_mlx *game);
void		map_validation(t_game *game, char *file);
void		get_map_failure(int fd, char *map, char *buffer, int sign);
int			ft_extention_check(char *file, t_game *game);
void		ft_failing(t_game *game, int sign);
void		ft_set_images(t_game *game);
int			ft_strlen_edited(char *s);
int			destroy_window(t_mlx *game);

#endif
