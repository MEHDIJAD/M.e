SRCS =  mand/so_long.c \
		get_next_line/get_next_line.c \
	  	mand/ft_check_file_map.c \
		mand/ft_valid_map.c \
	  	mand/ft_checking_map_tools.c \
	  	mand/ft_cleanup_game.c \
	  	mand/ft_draw_map.c \
	  	mand/ft_exit.c \
	  	mand/ft_free_map.c \
	  	mand/ft_get_img_data.c \
	  	mand/ft_get_map.c \
	  	mand/ft_get_map_dimention.c \
	  	mand/ft_get_player_position.c \
	  	mand/ft_initialize_data.c \
	  	mand/ft_moving.c \
	  	mand/ft_playable_map.c \
	  	mand/ft_puterror.c \
	  	libft/ft_bzero.c \
		libft/ft_calloc.c \
		libft/ft_memcpy.c \
		libft/ft_memset.c \
		libft/ft_strdup.c \
		libft/ft_strlen.c \
		libft/ft_strnstr.c \
		libft/ft_strchr.c \

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX   = -L/home/eel-garo/include/mlx/ -lmlx -lX11 -lXext

OBJS  = $(SRCS:.c=.o)

INCLUDES = -I includes -I ft_printf -I /home/eel-garo/include/mlx/ 

FT_PRINTF_DIR = ft_printf
# FT_GET_NEXT_LINE_DIR = get_next_line
# LIBFT_DIR = libft
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

NAME 	= so_long

all : $(FT_PRINTF_LIB) $(NAME)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(FT_PRINTF_LIB) -o $(NAME)  

%.o: %.c so_long.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) clean -C $(FT_PRINTF_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(FT_PRINTF_DIR)
	rm -f $(NAME)

re: fclean all