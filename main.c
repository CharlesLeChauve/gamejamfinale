/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:45:32 by iarrar            #+#    #+#             */
/*   Updated: 2023/08/28 15:13:50 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

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

char	*get_str(int fd)
{
	int		a;
	char	*buff;
	char	*str;
	
	buff = "";
	a = 10000;
	while (a >= 10000)
	{
		str = malloc(sizeof(char) * 10000);
		a = read(fd, str, 10000);
		str[a] = '\0';
		buff = ft_strjoin(buff, str);
		free(str);
	}
	return (buff);
}

char	**ft_maping(int fd)
{
	char 	*str;
	char 	**map;
	
	str = get_str(fd);
	map = ft_split(str, '\n');
	free (str);
	return (map);
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

//int	handle_no_event(void *data)
//{
    /* This function needs to exist, but it is useless for the moment */
//	return(0);
//}

int	handle_input(int keysym, t_data *data)
{
	int i;

	i = 0;
    if (keysym == XK_a)
        move_left(data);
	if (keysym == XK_s)
        move_down(data);
	if (keysym == XK_w)
        move_up(data);
	if (keysym == XK_d)
        move_right(data);    
	while (data->map[i])
	{
		ft_printf("%s\n", data->map[i]);
		i++;
	}
	if (ft_endgame(data) == 1 || keysym == XK_Escape)
	{
		if (ft_endgame(data) == 1)
			ft_printf("!!! YOU WIN !!!\nCongatulations fdp !\n");
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		ft_freetabtab(data->map);
		exit(EXIT_SUCCESS);
	}
    return (0);
}

int main()
{
	//int i = 0;
	int fd;
	t_data data;

	data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return (1);
    data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500,
            "My first window!");
    if (data.win_ptr == NULL)
    {
        free(data.win_ptr);
        return (1);
    }
	fd = open("test.ber", O_RDONLY);
	data.map = ft_maping(fd);
	if (ft_errmsg(data.map))
	{
		ft_freetabtab(data.map);
		return (0);
	}
	/*
	while (data.map[i])
	{
		ft_printf("%s\n", data.map[i]);
		i++;
	}
	*/
	data.player = ft_searstruct(data.map, 'P');
	data.exit = ft_searstruct(data.map, 'E');
	mlx_key_hook(data.win_ptr, &handle_input, &data);
	//free(data.map);
	mlx_loop(data.mlx_ptr);
	return (0);
}

