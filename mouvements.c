/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:48:23 by iarrar            #+#    #+#             */
/*   Updated: 2023/08/28 17:48:27 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	move_left(t_data *data)
{
	if (data->map[data->player.posy][data->player.posx - 1] != '1')
	{
		data->map[data->player.posy][data->player.posx] = '0';
		data->map[data->exit.posy][data->exit.posx] = 'E';
		data->map[data->player.posy][data->player.posx - 1] = 'P';
		data->player.posx--;
		data->count ++;
		return (1);
	}
	else
		return (0);
}

int	move_right(t_data *data)
{
	if (data->map[data->player.posy][data->player.posx + 1] != '1')
	{
		data->map[data->player.posy][data->player.posx] = '0';
		data->map[data->exit.posy][data->exit.posx] = 'E';
		data->map[data->player.posy][data->player.posx + 1] = 'P';
		data->player.posx++;
		data->count ++;
		return (1);
	}
	else
		return (0);
}

int	move_up(t_data *data)
{
	if (data->map[data->player.posy - 1][data->player.posx] != '1')
	{
		data->map[data->player.posy][data->player.posx] = '0';
		data->map[data->exit.posy][data->exit.posx] = 'E';
		data->map[data->player.posy - 1][data->player.posx] = 'P';
		data->player.posy--;
		data->count ++;
		return (1);
	}
	else
		return (0);
}

int	move_down(t_data *data)
{
	if (data->map[data->player.posy + 1][data->player.posx] != '1')
	{
		data->map[data->player.posy][data->player.posx] = '0';
		data->map[data->exit.posy][data->exit.posx] = 'E';
		data->map[data->player.posy + 1][data->player.posx] = 'P';
		data->player.posy++;
		data->count ++;
		return (1);
	}
	else
		return (0);
}
