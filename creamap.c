/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creamap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:06:24 by iarrar            #+#    #+#             */
/*   Updated: 2023/08/31 19:06:27 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

#define BUFFER_SIZE 5000

int	ft_searchar(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

t_player	ft_searstruct(char **map, char c)
{
	t_player	cacahuete;

	cacahuete.posx = -1;
	cacahuete.posy = 0;
	while (cacahuete.posx == -1)
	{
		cacahuete.posx = ft_searchar(map[cacahuete.posy], c);
		cacahuete.posy++;
	}
	cacahuete.posy--;
	return (cacahuete);
}

void ft_freetabtab(char **map)
{
	int	i;

	i = 0;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	handle_input(int keysym, t_data *data)
{
    if (keysym == XK_a)
        move_left(data);
	else if (keysym == XK_s)
        move_down(data);
	else if (keysym == XK_w)
		move_up(data);
	else if (keysym == XK_d)
        move_right(data);  
	put_image(data);
	ft_printf("\033[H\033[J");
	data->count ++;
	ft_printf("total moves = %d\n", data->count);
	if (ft_endgame(data) == 1 || keysym == XK_Escape)
	{
		if (ft_endgame(data) == 1)
			ft_printf("!!! YOU WIN !!!\nCongatulations fdp !\nmap cleared in %d moves\n", data->count);
		ft_ciao(data);
	}
    return (0);
}

int get_map(char *str, t_data *data)
{
    int ret;
    int total_len;
    char *buf;

    buf = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
    ret = read(open(str, O_RDONLY), buf, BUFFER_SIZE);
    total_len = ret;
    data->str = ft_strdup(buf);
    free(buf);
	data->map = ft_split(data->str, '\n');
	return (total_len);
}

void    ft_ciao(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
    free(data->str);
    ft_freetabtab(data->map);
    exit(EXIT_SUCCESS);
}

int	ft_init_all(t_data *data)
{
	ft_dimension(data);
	data->count = 0;
	data->mlx_ptr = mlx_init();
    if (data->mlx_ptr == NULL)
        return (1);
    data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width, data->win_height,
            "So_long window!");
    if (data->win_ptr == NULL)
    {
        free(data->win_ptr);
        return (1);
    }
	if (ft_errmsg(data->map) == 0 )
	{
		data->player = ft_searstruct(data->map, 'P');
		data->exit = ft_searstruct(data->map, 'E');
	}
	return(0);
}

