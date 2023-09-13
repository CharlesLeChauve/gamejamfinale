/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:24:31 by iarrar            #+#    #+#             */
/*   Updated: 2023/09/05 21:24:35 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int ft_coordonnees(int x, t_data *data)
{
    data->dimension = 128;
    return(x * data->dimension);
}

//data->player.sprite.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/cringe_1.xpm", &img_height, &img_width);
//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player.sprite.mlx_img, data->player.posmapx, data->player.posmapy);











void    ft_dimension(t_data *data)
{
    data->dimension = 128;
    data->win_height = ft_tabtabstrlen(data->map) * data->dimension;
    data->win_width = ft_strlen(data->map[0]) * data->dimension;
    data->map_height = ft_tabtabstrlen(data->map);
    data->map_width = ft_strlen(data->map[0]);
}

void    ft_init_img(t_data *data)
{
    int img_height;
    int img_width;

    data->player.sprite.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/cringe_1.xpm", &img_height, &img_width);
    data->wall.sprite.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/wall.xpm", &img_height, &img_width);
    data->font.sprite.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/font.xpm", &img_height, &img_width);
    data->cookie.sprite.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/cringe_1.xpm", &img_height, &img_width);
    // data->cookie.sprite.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/cringe_1.xpm", &img_height, &img_width);
    // data->player.posmapy = data->player.posy * data->dimension;
    // data->player.posmapx = data->player.posx * data->dimension;
}



void    put_image(t_data *data)
{
     //mlx_destroy_image(data->mlx_ptr, data->player.sprite.mlx_img);
    ft_init_img(data);
    int x;
    int y;

    x = 0;
    y = 0;
    while (data->map[y])
    {
        while (data->map[y][x])
        {
            if (data->map[y][x] == 'P')
                    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player.sprite.mlx_img, ft_coordonnees(x, data), ft_coordonnees(y, data));
            else if (data->map[y][x] == '1')
                    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall.sprite.mlx_img, ft_coordonnees(x, data), ft_coordonnees(y, data));
            else if (data->map[y][x] == '0')
                    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->font.sprite.mlx_img, ft_coordonnees(x, data), ft_coordonnees(y, data));
            else if (data->map[y][x] == 'E')
                    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->cookie.sprite.mlx_img, ft_coordonnees(x, data), ft_coordonnees(y, data));
            x++;
        }
        x = 0;
        y++;
    }
}



