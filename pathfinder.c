/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 21:01:07 by iarrar            #+#    #+#             */
/*   Updated: 2023/09/04 21:01:10 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_check(char **map, int x, int y, t_data *data)
{
	if (map[y][x] != '1')
	{
		if (map[y][x] == 'E')
			data->e = 0;
		if (map[y][x] == 'P')
			data->p = 0;
		map[y][x] = '1';
		if (data->e == 0 && data->p == 0 && ft_cookiz(map) == 0)
		{
			data->r = 0;
			return ;
		}
		ft_check(map, x - 1, y, data);
		ft_check(map, x + 1, y, data);
		ft_check(map, x, y - 1, data);
		ft_check(map, x, y + 1, data);
		return ;
	}
	else
		return ;
}

char	**ft_tabtabstrdup(char **tab)
{
	int		i;
	char	**dest;

	i = 0;
	dest = malloc(sizeof(char *) * (ft_tabtabstrlen(tab) + 1));
	while (tab[i])
	{
		dest[i] = ft_strdup(tab[i]);
		i++;
	}
	return (dest);
}

int	ft_pathfinder(t_data *data)
{
	int		x;
	int		y;
	char	**map;

	x = data->player.posx;
	y = data->player.posy;
	data->e = 1;
	data->p = 1;
	data->r = 1;
	map = ft_tabtabstrdup(data->map);
	ft_check(map, x, y, data);
	ft_freetabtab(map);
	if (data->r == 0)
		return (0);
	else
		return (1);
}
