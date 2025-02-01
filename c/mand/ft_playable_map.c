/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playable_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:49:37 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/24 19:49:38 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_free_copy(char **copy, int i)
{
	if (!copy)
		return ;
	while (i >= 0)
	{
		if (copy[i])
		{
			free(copy[i]);
			copy = NULL;
		}
		i--;
	}
	free(copy);
	copy = NULL;
}

static int	ft_flood_fill(char **map, int x, int y)
{
	int	i;

	i = 0;
	if (map[x][y] == '1')
		return (0);
	if (map[x][y] == 'E')
		return (map[x][y] = '1', 1);
	if (map[x][y] == 'C')
		i++;
	map[x][y] = '1';
	i += ft_flood_fill(map, x + 1, y);
    i += ft_flood_fill(map, x - 1, y);
    i += ft_flood_fill(map, x, y + 1);
    i += ft_flood_fill(map, x, y - 1);
	return (i);
}
int	ft_playable_map(t_data *data)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = ft_calloc(sizeof(char *), data->height + 1);
	if (!map_copy)
		return (0);
	while (i < data->height && data->map[i])
	{
		map_copy[i] = ft_strdup(data->map[i]);
		if (!map_copy[i])
			return (ft_free_copy(map_copy, i), 0);
		i++;
	}
	map_copy[data->height] = NULL;
	ft_get_player_position(data);
	if (ft_flood_fill(map_copy, data->player_x, data->player_y) != data->collectible + 1)
	{
		return (ft_free_map(map_copy), 0);
	}
	i = 0;
	while (i < data->height)
		free(map_copy[i++]);
	free(map_copy);
	return (1);
}
