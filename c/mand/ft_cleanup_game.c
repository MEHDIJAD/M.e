/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:19:40 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/24 19:19:41 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_cleanup_game(t_data *data)
{
	if (data->img_protagonist)
		mlx_destroy_image(data->mlx, data->img_protagonist);
	if (data->img_block)
		mlx_destroy_image(data->mlx, data->img_block);
	if (data->img_space)
		mlx_destroy_image(data->mlx, data->img_space);
	if (data->img_collectible)
		mlx_destroy_image(data->mlx, data->img_collectible);
	if (data->img_exit)
		mlx_destroy_image(data->mlx, data->img_exit);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map)
		ft_free_map(data->map);
}