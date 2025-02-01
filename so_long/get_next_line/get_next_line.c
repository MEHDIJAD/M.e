/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <eel-garo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:21:14 by eel-garo          #+#    #+#             */
/*   Updated: 2024/12/05 11:19:10 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen(const char *buf)
{
	size_t	len;

	len = 0;
	while (buf[len] && buf[len] != '\n')
	{
		len++;
	}
	return (len);
}
char	*ft_filljoin(char *tofill, const char *str_buf, const char *buf)
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
        return (strdup(buffer));
    if (!buffer)
        return (strdup(map));
    len = strlen(map) + strlen(buffer);
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
            newline_pos = strchr(map_line, '\n');
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
        char *line = strdup(map_line);
        char *remaining = strdup(newline_pos + 1);
        free(map_line);
        map_line = remaining;
        return (line);
    }
    if (map_line && *map_line)
    {
        char *line = strdup(map_line);
        free(map_line);
        map_line = NULL;
        return (line);
    }
    return (free(map_line), map_line = NULL, NULL);
}
