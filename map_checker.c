/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:12:10 by iarrar            #+#    #+#             */
/*   Updated: 2023/08/23 16:31:19 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/*codes d'erreurs
Erreur 500 : map non rectangulaire fdp
Erreur 501 : map trop petite fdp

*/



int check_rectangle(char **map)
{
    int i;
    int y;
    int x;

    y = 0;
    i = 0;
    x = ft_strlen(map[0]);
    while (map[y + 1])
    {
        i = ft_strlen(map[y]);
        if (i != x)
        {
            ft_printf("x = %d, y = %d, i = %d\n", x, y, i);
            return (500);
        }
        i = 0;
        y++;
    }
    
    if (x < 5 || y < 3)
        return (501);
    return (0);
}

int ft_errmsg(char **map)
{
    if (check_rectangle(map) == 500)
	{
		ft_printf("Erreur 500 : map non rectangulaire\n");
		return (1);
	}
	else if (check_rectangle(map) == 501)
	{
		ft_printf("Erreur 501 : map trop petite\n");
		return (1);
	}
    else if (check_walls(map) == 502)
    {
        ft_printf("Erreur 502 : la map doit etre entouree de murs\n");
        return (1);
    }
    else if (ft_cookiz(map) == 0)
    {
        ft_printf("Erreur 503 : Votre jeu ne contient pas de collectibles\n");
        return (1);
    }
        return (0);
}

int	ft_tabtabstrlen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

int check_walls(char **map)
{
    int x;
    int h;
    int w;
    int y;

    x = 0;
    h = ft_tabtabstrlen(map);
    w = ft_strlen(map[0]);
    y = 0;
    while(map[0][x] && map[h - 1][x])
    {
        if ((map[0][x] != '1') || (map[h - 1][x] != '1'))
            return (502);
        x++;
    }
    while(map[y])
    {
        if ((map[y][0] != '1') || (map[y][w - 1] != '1'))
            return (502);
        y++;
    }
    return (0);
}