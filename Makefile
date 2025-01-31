SRCS   = push_swap.c \
	     ft_check_input.c \
		 ft_fill_list.c \
		 ft_check_double.c \
		 ft_sort_list.c \
		 ft_index_list.c \
		 ft_print_list.c \
		 libft/ft_atoi.c \
		 libft/ft_isdigit.c \
		 libft/ft_lstnew.c \
		 libft/ft_lstlast.c \
		 libft/ft_lstadd_back.c \
		 libft/ft_lstdelone.c \
		 libft/ft_lstclear.c \
		 libft/ft_lstsize.c \


OBJS   = $(SRCS:.c=.o)

NAME   = push_swap

INCLUDES = -I includes -I ft_printf

FT_PRINTF_DIR = ft_printf

FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

CC     = cc 
CFLAGS = -Wall -Wextra -Werror
LIBC   = ar rc
RM	   = rm -rf

all: $(FT_PRINTF_LIB) $(NAME)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF_LIB) -o $(NAME)

%.o:%.c push_swap.h
	$(CC) $(CFLAGS) -c  $< -o $@

clean:
	$(MAKE) clean -C $(FT_PRINTF_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(FT_PRINTF_DIR)
	$(RM) $(NAME)

re: fclean all




