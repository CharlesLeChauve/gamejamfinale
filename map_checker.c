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
    while (map[y])
    {
        i = ft_strlen(map[y]);
        if (i != x)
        {
            ft_printf("Erreur 500 : map non rectangulaire\n");
            return (500);
        }
        i = 0;
        y++;
    }
    if ((x <= 5 && y <= 3) || (x <= 3 && y <= 5))
    {
        ft_printf("Erreur 501 : map trop petite\n");
        return (501);
    }
    return (0);
}

int ft_errmsg(char **map)
{
    if (check_rectangle(map) == 500)
		return (1);
	else if (check_rectangle(map) == 501)
		return (1);
    else if (check_walls(map) == 502)
        return (1);
    else if (check_elements(map) == 504)
        return (1);
    else if (count_elements(map) == 505)
        return (1);
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
    int y;

    x = 0;
    y = 0;
    while(map[0][x] && map[ft_tabtabstrlen(map) - 1][x])
    {
        if ((map[0][x] != '1') || (map[ft_tabtabstrlen(map) - 1][x] != '1'))
        {
            ft_printf("Erreur 502 : la map doit etre entouree de murs\n");
            return (502);
        }
        x++;
    }
    while(map[y])
    {
        if ((map[y][0] != '1') || (map[y][ft_strlen(map[0]) - 1] != '1'))
        {
            ft_printf("Erreur 502 : la map doit etre entouree de murs\n");
            return (502);
        }
        y++;
    }
    return (0);
}

int     count_elements(char **map)
{
    int i;
    int j;
    int e;
    int p;

    i = 0;
    j = 0;
    p = 0;
    e = 0;

    while (map[j])
    {
        while(map[j][i])
        {
            if (map[j][i] == 'E')
                e++;
            else if (map[j][i] == 'P')
                p++;
            i++;
        }
        i = 0;
        j++;
    }
    if (e != 1 || p != 1)
    {
        ft_printf("Erreur 505 : nombre de player/sortie sur la carte invalide\n");
        return (505);
    }
    else
        return (0);
}

int     check_elements(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[j])
    {
        while (map[j][i])
        {

            if (map[j][i] != '1' && map[j][i] != '0' && map[j][i] != 'E' && map[j][i] != 'C' && map[j][i] != 'P')
            {
                ft_printf("Erreur 504 : Element non compatible sur la carte\n");
                return (504);
            }
            i++;
        }
        i = 0;
        j++;
    }
    return(0);
}

// void    ft_dimension(t_data *data)
// {
//     data->map_height = ft_tabtabstrlen(data->map);
//     data->map_width = ft_strlen(data->map[0]);
//     ft_printf("h = %d\ne = %d\n", data->map_height, data->map_width);
// }

