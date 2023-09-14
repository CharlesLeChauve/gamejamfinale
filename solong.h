/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:49:30 by iarrar            #+#    #+#             */
/*   Updated: 2023/08/28 14:42:02 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

# define DIMENSION 50

typedef struct s_imge
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_imge;

typedef struct s_player
{
	int		posx;
	int		posy;
	int		posmapx;
	int		posmapy;
	t_imge	sprite;
}	t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_player	player;
	t_player	exit;
	t_player	exit_close;
	t_player	exit_open;
	t_player	wall;
	t_player	font;
	t_player	cookie;
	char		*str;
	char		**map;
	int			count;
	int			dimension;
	int			map_height;
	int			map_width;
	int			win_height;
	int			win_width;
	int			e;
	int			p;
	int			r;
}	t_data;

typedef struct s_map
{
	char	**map;
	int		map_height;
	int		map_width;
}	t_map;

char		*get_str(int total, int fd);
char		**ft_tabtabstrdup(char **tab);
int			ft_maping(int fd, t_data *data);
int			move_left(t_data *data);
int			move_right(t_data *data);
int			move_up(t_data *data);
int			move_down(t_data *data);
int			ft_cookiz(char **map);
int			check_rectangle(char **map);
int			ft_errmsg(char **map);
int			ft_tabtabstrlen(char **tab);
int			check_walls(char **map);
int			ft_pathfinder(t_data *data);
int			ft_endgame(t_data *data);
int			check_elements(char **map);
int			count_elements(char **map);
int			ft_searchar(char *str, char c);
int			get_map(char *str, t_data *data);
int			handle_input(int keysym, t_data *data);
void		ft_freetabtab(char **map);
void		ft_freetabtab(char **map);
int			ft_ciao(t_data *data);
void		ft_check(char **map, int x, int y, t_data *data);
void		check_left(char **map, int x, int y, t_data *data);
void		check_up(char **map, int x, int y, t_data *data);
void		check_down(char **map, int x, int y, t_data *data);
void		ft_dimension(t_data *data);
void		put_image(t_data *data);
t_data		ft_ignition(int fd);
t_player	ft_searstruct(char **map, char c);
void		ft_init_img(t_data *data);
int			ft_crdn(int x, t_data *data);
void		free_image(t_data *data);
int			ft_init_all(t_data *data);
void		ft_choose_img(char c, t_data *data, int x, int y);
int			check_extension(char *str);

#endif