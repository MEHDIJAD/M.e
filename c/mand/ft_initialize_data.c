/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:09:38 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/24 18:09:40 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_initialize_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img_protagonist = NULL;
	data->img_block = NULL;
	data->img_space = NULL;
	data->img_collectible = NULL;
	data->img_exit = NULL;
	data->img_height = 0;
	data->img_width = 0;
	data->map = NULL;
	data->relative_path_protagonist = "/home/eel-garo/Desktop/M.2/so_long/textures/protagonist.xpm";
	data->relative_path_block = "/home/eel-garo/Desktop/M.2/so_long/textures/block.xpm";
	data->relative_path_collectible = "/home/eel-garo/Desktop/M.2/so_long/textures/collectible.xpm";
	data->relative_path_exit = "/home/eel-garo/Desktop/M.2/so_long/textures/exit.xpm";
	data->relative_path_space = "/home/eel-garo/Desktop/M.2/so_long/textures/space.xpm";
	data->player_x = 0;
	data->player_y = 0;
	data->collectible = 0;
}
