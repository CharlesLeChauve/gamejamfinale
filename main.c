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

int main(int argc, char **argv)
{
	t_data data;

	if (argc != 2)
		return(0);
	get_map(argv[1], &data);
	if (ft_init_all(&data) == 1)
		return (1);
	if (ft_errmsg(data.map)!= 0 )
	{
		ft_ciao(&data);
		return (0);
	}
	if (ft_pathfinder(&data))
	{
		ft_printf("Error : Tous les items ne sont pas collectibles\n");
		ft_ciao(&data);
		return(0);
	}
	put_image(&data);
	mlx_key_hook(data.win_ptr, &handle_input, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}



