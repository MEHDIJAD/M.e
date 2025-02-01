/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:00:07 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/24 18:00:08 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*ft_filljoin(char *tofill, const char *str_buf, const char *buf)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str_buf[i])
	{
		tofill[i] = str_buf[i];
		i++;
	}
	j = 0;
	while (buf[j])
	{
		tofill[i] = buf[j];
		i++;
		j++;
	}
	tofill[i] = '\0';
	return (tofill);
}

static char *ft_add(char  *map, char  *buffer)
{
    char *new_buff;
    size_t len;

    if (!map && !buffer)
        return (NULL);
    if (!map)
        return (ft_strdup(buffer));
    if (!buffer)
        return (ft_strdup(map));
    len = ft_strlen(map) + ft_strlen(buffer);
    new_buff = malloc((len + 1) * sizeof(char));
    if (!new_buff)
        return (NULL);
    new_buff = ft_filljoin(new_buff, map, buffer);
    free(map);
    return (new_buff);
}

char *get_next_line(int fd)
{
    static char *map_line = NULL;
    char *buffer;
    ssize_t bytes_read;
    char *newline_pos;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    while (1)
    {
        if (map_line)
            newline_pos = ft_strchr(map_line, '\n');
        else
            newline_pos = NULL;
        if (newline_pos)
            break;
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            break;
        buffer[bytes_read] = '\0';
        map_line = ft_add(map_line, buffer);
    }
    free(buffer);
    if (!map_line || bytes_read < 0)
        return (free(map_line), map_line = NULL, NULL);
    if (newline_pos)
    {
        *newline_pos = '\0';
        char *line = ft_strdup(map_line);
        char *remaining = ft_strdup(newline_pos + 1);
        free(map_line);
        map_line = remaining;
        return (line);
    }
    if (map_line && *map_line)
    {
        char *line = ft_strdup(map_line);
        free(map_line);
        map_line = NULL;
        return (line);
    }
    return (free(map_line), map_line = NULL, NULL);
}