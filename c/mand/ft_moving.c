/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moving.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:46:46 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/24 20:46:47 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	put_move(t_data *data, int new_x, int new_y, int *movement_count)
{
    char next_pos = data->map[new_x][new_y];

    if (next_pos == 'C')
        data->collectible--;
    else if (next_pos == 'E')
    {
        if (data->collectible != 0)
            return;
        if (data->collectible == 0)
        {
           ft_printf(2, "Movements: %d\n", ++(*movement_count));
           ft_exit(data);
        }
    }
    if (next_pos != '1')
    {
        data->map[data->player_x][data->player_y] = '0';
        data->map[new_x][new_y] = 'P';
        data->player_x = new_y;
        data->player_y = new_y;
        ft_printf(2, "Movements: %d\n", ++(*movement_count));
    }
}
int	ft_moving(int keycode, t_data *data)
{
    static int	movement_count;

    ft_get_player_position(data);
    // ft_printf (1, "%d, %d", data->player_x, data->player_y);
    if (keycode == XK_Escape)
        ft_exit(data);
    if (keycode == XK_Right)
        put_move(data, data->player_x, data->player_y + 1, &movement_count);
    if (keycode == XK_Left)
        put_move(data, data->player_x, data->player_y - 1, &movement_count);
    if (keycode == XK_Down)
        put_move(data, data->player_x + 1, data->player_y, &movement_count);
    if (keycode == XK_Up)
        put_move(data, data->player_x - 1, data->player_y, &movement_count);
    ft_draw_map(data);
    return (0);
}