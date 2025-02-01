/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:04:54 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/24 19:04:55 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_fill_map(t_data *data, int map_height, char *file)
{
	int		i;
	char	*line;
	int		fd;

	data->map = malloc(sizeof(char *) * (map_height + 1)); //!
	if (!data->map)
		return (ft_printf(2, "💀Error\nMemory allocation failed"), free(data->map), exit(0), 1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_printf(2, "💀Error reopening file"), free(data->map), 1); //! free ?
	i = 0;
	while ((line = get_next_line(fd)))
	{
		data->map[i] = line;
		if (!data->map[i])
		{
			ft_printf(2, "Memory allocation failed during reading");
			close (fd);
			ft_exit(data);
		}
		i++;
	}
	data->map[i] = NULL;
	return (close(fd), 0); //!
}
int	ft_get_map(char *file, t_data *data)
{
	int		fd;
	int		map_height;
	char	*line;

	map_height = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_printf(2, "💀Error\ncan't opening file\n"), 0);
	while ((line = get_next_line(fd)))
	{
		map_height++;
		free(line);
	}
	close(fd);
	if (map_height == 0)
		return (ft_printf(2, "💀Error\nEmpty map file\n"), 0);
	if (!ft_fill_map(data, map_height, file))
		return (1); //!
	return (0);
}