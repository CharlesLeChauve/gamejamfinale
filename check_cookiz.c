/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cookiz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:57:16 by iarrar            #+#    #+#             */
/*   Updated: 2023/08/28 17:57:20 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "solong.h"

int ft_cookiz(char **map)
{
    int i;
    int j;
    int c;

    i = 0;
    j = 0;
    c = 0;
    while (map[i])
    {
        while(map[i][j])
        {
            if (map[i][j] == 'C')
                c++;
            j++;
        }
        j = 0;
        i++;
    }
    return(c);
}

int    ft_endgame(t_data *data)
{
    if ((data->player.posy == data->exit.posy) && (data->player.posx == data->exit.posx) && (ft_cookiz(data->map) == 0))
        return (1);
    else
        return (0);
}

