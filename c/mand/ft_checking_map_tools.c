/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking_map_tools.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:24:44 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/24 20:24:45 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_surrounded_by_walls_check(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->height && data->map[x])
	{
		y = 0;
		while (y < data->width && data->map[x][y])
		{
			if ((x == 0 || x == data-> height - 1|| y == 0 || y == data->width - 1)
			&& (!data->map[x][y] || data->map[x][y] != '1'))
			{
				return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

int  ft_check_components(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'P')
                data->player = true;
            if (data->map[i][j] == 'C')
                data->collect = true;
            if (data->map[i][j] == 'E')
                data->exit = true;
            if (data->map[i][j] == '0')
                data->space = true;
            if (data->map[i][j] == '1')
                data->block = true;
            j++;
        }
        i++;
    }
    return (data->player && data->collect && data->exit && data->space && data->block);
}

int ft_min_components(t_data *data)
{
    int	i; 
    int	j;
    int	player;
    int	exit;

    i = 0;
    player = 0;
    exit = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'P')
                player++;
            if (data->map[i][j] == 'E')
                exit++;
            j++;
        }
        i++;
    }
    return (player < 2 && exit < 2);
}

int small_check(t_data *data)
{
    int x;
    int y;

    if (!data->map[0] || !data->map)
        return (0); //!
    x = 0;
    while (data->map[x])
    {
        y = 0;
        while(data->map[x][y])
        {
            if (data->map[x][y] != '1' && data->map[x][y] != '0' 
            && data->map[x][y] != 'P' && data->map[x][y] != 'C' 
            && data->map[x][y] != 'E' && data->map[x][y] != ' '
            && data->map[x][y] != '\n')
            {
                return (0);
            }
            y++;
        }
        x++;
    }
    return (1);
}

int ft_rectangular_check(t_data *data) //!
{
    size_t	len;
    int		x;

    if (!data->map || !data->map[0])
        return (0);
    len = ft_strlen(data->map[0]);
    x = 1;
    while(x < data->height && data->map[x])
    {

        if (ft_strlen(data->map[x]) != len)
        {

            return (0);
        }
        x++;
    }
    if (x != data->height)
        return (0);
    return (1);
}
