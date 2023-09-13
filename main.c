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
	ft_dimension(&data);
	data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return (1);
    data.win_ptr = mlx_new_window(data.mlx_ptr, data.win_width, data.win_height,
            "So_long window!");
    if (data.win_ptr == NULL)
    {
        free(data.win_ptr);
        return (1);
    }
	
	if (ft_errmsg(data.map)!= 0 )
	{
		ft_ciao(&data);
		return (0);
	}
	data.player = ft_searstruct(data.map, 'P');
	data.exit = ft_searstruct(data.map, 'E');
	ft_init_img(&data);
	if (ft_pathfinder(&data))
	{
		ft_printf("Error : Tous les items ne sont pas collectibles\n");
		ft_ciao(&data);
		return(0);
	}
	
	//data.plane.mlx_img = mlx_new_image(data.mlx_ptr, data.win_width, data.win_height);
	//put_image(&data);
	mlx_key_hook(data.win_ptr, &handle_input, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

