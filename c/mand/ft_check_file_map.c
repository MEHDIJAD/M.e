/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:55:13 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/24 18:55:14 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_file_map(char *map_ber)
{
	if (!ft_strnstr(map_ber, ".ber", ft_strlen(map_ber)))
		return (0);
	return (1);
}