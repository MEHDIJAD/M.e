/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:32:37 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/24 17:32:38 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int main(int ac, char *av[])
{
    t_data  data;

    if (ac != 2)
        return (ft_printf(2, "Error\nWrong number of arguments!?"), EXIT_FAILURE);
    ft_initialize_data(&data);
    if (!ft_check_file_map(av[1]))
        return (ft_printf(2, "Error\nfile name do not end with .ber!"), EXIT_FAILURE);
    if (!ft_get_map(av[1], &data))
        return (EXIT_FAILURE);
    ft_get_map_dimention(&data);
    if (!ft_valid_map(&data))
        return (ft_free_map(data.map),EXIT_FAILURE);
    data.mlx = mlx_init(); 
    if (!data.mlx)
        return (ft_free_map(data.map), EXIT_FAILURE);
    data.win = mlx_new_window(data.mlx, (data.width * IMAGE_SIZE), (data.height * IMAGE_SIZE), "so_long");
    if (!data.win)
        return (ft_cleanup_game(&data), EXIT_FAILURE);
    ft_get_img_data(&data);
    ft_draw_map(&data);
    mlx_hook(data.win, 2, 1 << 0, ft_moving, &data);
    mlx_hook(data.win, 17, 0, ft_exit, &data);
    mlx_loop(data.mlx);
    return (0);
}
