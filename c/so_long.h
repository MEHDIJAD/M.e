/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:32:43 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/24 17:32:44 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
#define SO_LONG

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 1
# endif

# define IMAGE_SIZE 32
# define SIZE_MAX 18446744073709551615ULL

#include "/home/eel-garo/include/mlx/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <X11/keysym.h>
#include <stdbool.h>
#include "ft_printf/ft_printf.h"

#include <stdio.h> //!

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img_protagonist;
	void	*img_block;
	void	*img_space;
	void	*img_collectible;
	void	*img_exit;
	int		img_height;
	int		img_width;
	char	**map;
	int		height;
	int		width;
	char	*relative_path_protagonist;
	char	*relative_path_block;
	char	*relative_path_space;
	char	*relative_path_collectible;
	char	*relative_path_exit;
	int		player_x;
	int		player_y;
	int		collectible;
	bool	player;
	bool	exit;
	bool	collect;
	bool	block;
	bool	space;
} t_data;

// get_next_line
char	*get_next_line(int fd);

// libft
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t n);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);



//mand
void	ft_initialize_data(t_data *data);
int		ft_check_file_map(char *map_ber);
int		ft_get_map(char *file, t_data *data);
int		ft_exit(t_data *data);
void	ft_cleanup_game(t_data *data);
void	ft_free_map(char **map);
void	ft_get_map_dimention(t_data *data);
void	ft_get_player_position(t_data *data);
int		ft_valid_map(t_data *data);
int		ft_playable_map(t_data *data);
int		ft_surrounded_by_walls_check(t_data *data);
int 	ft_check_components(t_data *data);
int		ft_min_components(t_data *data);
int 	small_check(t_data *data);
int		ft_rectangular_check(t_data *data);
int		ft_get_img_data(t_data *data);
void	ft_draw_map(t_data *data);
int		ft_moving(int keycode, t_data *data);
void	ft_puterror(int error_code);

#endif
