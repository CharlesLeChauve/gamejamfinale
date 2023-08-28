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

void	move_left(t_data *data)
{
	data->map[data->player.posy][data->player.posx] = '0';
	data->map[data->player.posy][data->player.posx - 1] = 'P';
	return;
}

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
	str = malloc(sizeof(char) * 10);
	a = read(fd, str, 10);
	buff = ft_strjoin(buff, str);
	free(str);
	while (a >= 10)
	{
		str = malloc(sizeof(char) * 10);
		a = read(fd, str, 10);
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

int	handle_no_event(void *data)
{
    /* This function needs to exist, but it is useless for the moment */
	return(0);
}

int	handle_input(int keysym, t_data *data)
{
    if (keysym == XK_A)
        move_left(data);
    return (0);
}

int main()
{
	int i = 0;
	//char **map;
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
	while (data.map[i])
	{
		ft_printf("%s\n", data.map[i]);
		i++;
	}
	data.player = ft_searstruct(data.map, 'P');
	ft_printf("x = %d\ny = %d\n", data.player.posx, data.player.posy);
	mlx_loop_hook(data.win_ptr, &handle_no_event, &data);
	mlx_key_hook(data.win_ptr, &handle_input, &data);
	//free(map);
	mlx_loop(data.mlx_ptr);
	return (0);
}

