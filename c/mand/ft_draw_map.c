/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:43:02 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/24 20:43:04 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void ft_put_image(t_data *data, int i, int j, char c)
{
    void *img;

    if (c == '1')
        img = data->img_block;
    else if(c == 'P')
        img = data->img_protagonist;
    else if (c == '0')
        img = data->img_space;
    else if(c == 'C')
        img = data->img_collectible;
    else if (c == 'E')
        img = data->img_exit;
    else 
        return ;
    mlx_put_image_to_window(data->mlx, data->win, img, (j * data->img_width), (i * data->img_height));
}

void	ft_draw_map(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            ft_put_image(data, i, j, data->map[i][j]); 
            j++;
        }
        i++;
    }
}
