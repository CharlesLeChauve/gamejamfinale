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

#ifndef	SOLONG_H
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

typedef struct s_player
{
	int posx;
	int	posy;
}	t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_player 	player;
	t_player	exit;
	char		*str;
	char		**map;
	int			h;
	int			w;
	int			e;
	int			p;
	int			r;
}	t_data;

typedef struct s_map
{
	char **map;
}	t_map;


char	*get_str(int total, int fd);
int		ft_maping(int fd, t_data *data);
int		move_left(t_data *data);
int		move_right(t_data *data);
int		move_up(t_data *data);
int		move_down(t_data *data);
int		ft_cookiz(char **map);
int		check_rectangle(char **map);
int		ft_errmsg(char **map);
int		ft_tabtabstrlen(char **tab);
int		check_walls(char **map);
int		ft_endgame(t_data *data);
int     check_elements(char **map);
int     count_elements(char **map);
void	ft_freetabtab(char **map);
t_data	ft_ignition(int fd);
int 	get_map(char *str, t_data *data);
int		handle_input(int keysym, t_data *data);
void 	ft_freetabtab(char **map);
t_player	ft_searstruct(char **map, char c);
int		ft_searchar(char *str, char c);
void    ft_ciao(t_data *data);
void    ft_check(char **map, int x, int y, t_data *data);
void    check_left(char **map, int x, int y, t_data *data);
void    check_up(char **map, int x, int y, t_data *data);
void    check_down(char **map, int x, int y, t_data *data);
char **ft_tabtabstrdup(char **tab);
int ft_pathfinder(t_data *data);



#endif