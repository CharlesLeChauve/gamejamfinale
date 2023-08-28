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
	char		**map;
}	t_data;

typedef struct s_map
{
	char **map;
}	t_map;


char	*get_str(int fd);
char	**ft_maping(int fd);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
int		ft_cookiz(t_data *data);



#endif