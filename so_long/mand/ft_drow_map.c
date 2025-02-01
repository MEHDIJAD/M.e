/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drow_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:18:49 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/16 11:18:50 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void ft_put_image(t_data *data, int i, int j, char c)
{
    void *img;

    if (c == '1')
        img = data->img_wall;
    else if(c == 'P')
        img = data->img_hero;
    else if (c == '0')
        img = data->img_floor;
    else if(c == 'C')
        img = data->img_collact;
    else if (c == 'E')
        img = data->img_exit;
    else 
        return ;
    mlx_put_image_to_window(data->mlx, data->win, img, (j * data->img_widht), (i * data->img_height));
}
void ft_drow_map(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->ptr[i])
    {
        j = 0;
        while (data->ptr[i][j])
        {
            ft_put_image(data, i, j, data->ptr[i][j]); 
            j++;
        }
        i++;
    }
}

