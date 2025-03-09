/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:25:21 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/09 01:26:21 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
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

typedef struct s_enemy
{
	int				y;
	int				x;
	struct s_enemy	*next;
}t_enemy;

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
	void			*enemy;
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
	int				fd;
	int				coins;
	int				exit;
	int				player;
	char			**map;
	char			**map_cpy;
	struct s_enemy	*enemies_location;
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
void		ft_enemy_movment(t_mlx *game, t_enemy *en);
void		ft_new_e_position_check(t_mlx *game, t_enemy *en,
				int new_x, int new_y);
void		ft_looser_function(t_mlx *game);
int			update_enemy(t_mlx *game);
void		ft_set_enemies_location(t_game *game);
t_enemy		*ft_add_location(int y, int x);
t_enemy		*ft_set_the_head(void);
void		ft_lstclear(t_enemy **lst);
void		ft_lstadd_back(t_enemy **lst, t_enemy *new);
char		*ft_itoa(int n);
int			movment_string(t_mlx *game);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
void		free_a_map(char **map, int size);
void		get_map_failure(int fd, char *map, char *buffer, int sign);
int			destroy_window(t_mlx *game);
void		ft_set_variables(t_game *game);
void		map_validation(t_game *game, char *file);
int			ft_extention_check(char *file, t_game *game);
void		ft_failing(t_game *game, int sign);
void		set_img_ptr(t_mlx *mlx, char c, void **img);
void		ft_set_images(t_game *game);
int			ft_strlen_edited(char *s);

#endif
