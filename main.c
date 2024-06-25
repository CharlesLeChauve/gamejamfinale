/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:45:32 by iarrar            #+#    #+#             */
/*   Updated: 2024/06/24 11:31:26 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.direction = 0;
	if (argc != 2 || check_extension(argv[1]) == 0)
		return (0);
	if (get_map(argv[1], &data) == 0)
		return (0);
	if (ft_init_all(&data) == 1)
		return (0);
	if (ft_errmsg(data.map) != 0)
	{
		ft_ciao(&data);
		return (0);
	}
	if (ft_pathfinder(&data))
	{
		ft_putstr_fd("Error : Tous les items ne sont pas collectibles\n", 2);
		ft_ciao(&data);
		return (0);
	}
	ft_init_img(&data);
	put_image(&data, 0);
	mlx_do_key_autorepeatoff(data.mlx_ptr);
	mlx_key_hook(data.win_ptr, &handle_input, &data);
	mlx_hook(data.win_ptr, 17, KeyPressMask, &ft_ciao, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
