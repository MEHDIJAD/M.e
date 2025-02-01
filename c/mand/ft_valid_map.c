/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:41:13 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/24 19:41:16 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_valid_map(t_data *data)
{
	if (data->height > 25 || data->width > 61)
		return (ft_puterror(1), 0);

	 if (!ft_check_components(data))
        return (ft_puterror(2), 0);

    if (!ft_min_components(data))
        return (ft_puterror(3), 0);

    if (!small_check(data))
        return (ft_puterror(4), 0);

    if (!ft_rectangular_check(data))
        return (ft_puterror(5), 0);

    if (!ft_surrounded_by_walls_check(data))
        return (ft_puterror(6), 0);

    if (!ft_playable_map(data))
        return (ft_puterror(7), 0);
		
    return (1);    
}