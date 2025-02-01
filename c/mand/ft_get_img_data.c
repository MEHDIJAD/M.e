/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_img_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:39:06 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/24 20:39:07 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_get_img_data(t_data *data)
{
    data->img_protagonist= mlx_xpm_file_to_image(data->mlx, data->relative_path_protagonist, &data->img_width, &data->img_height);
    if (!data->img_protagonist)
        return (ft_printf(2,"Failed to load hero image"), ft_exit(data), 0);
    data->img_block = mlx_xpm_file_to_image(data->mlx, data->relative_path_block, &data->img_width, &data->img_height);
    if (!data->img_block)
        return (ft_printf(2,"Failed to load wall image"), ft_exit(data), 0);
    data->img_space = mlx_xpm_file_to_image(data->mlx, data->relative_path_space, &data->img_width, &data->img_height);
    if (!data->img_space)
    	return (ft_printf(2,"Failed to load floor image"), ft_exit(data),0);
    data->img_collectible = mlx_xpm_file_to_image(data->mlx, data->relative_path_collectible, &data->img_width, &data->img_height);
    if (!data->img_collectible)
    	return (ft_printf(2,"Failed to load collectible image"), ft_exit(data), 0);
    data->img_exit = mlx_xpm_file_to_image(data->mlx, data->relative_path_exit, &data->img_width, &data->img_height);
    if (!data->img_exit)
    	return (ft_printf(2,"Failed to load exit image"), ft_exit(data), 0);
    return (1);
}