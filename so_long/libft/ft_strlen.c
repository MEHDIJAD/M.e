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