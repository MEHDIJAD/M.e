/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_dimention.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:33:32 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/24 19:33:33 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_get_map_dimention(t_data *data)
{
	int	x;
	int	y;
	int	collectible;

	x = 0;
	collectible = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'C')
				collectible++;
			y++;
		}
		x++;
	}
	data->height = x;
	data->width = y;
	data->collectible = collectible;
}
