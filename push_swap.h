/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:11:11 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/31 20:40:49 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h> //!
# include "ft_printf/ft_printf.h"

typedef struct s_list
{	
	int				number;
	int				index;
	struct s_list	*next;
}		t_list;

//TODO: push_swap Functions
void 	ft_check_input(char *av[]);
void 	ft_fill_list(char **vic, t_list **list);
void	ft_check_double(t_list *list);
void	ft_index_list(t_list **lst);
void	ft_sort_list(t_list **lst);
void	ft_print_list(t_list *lst); //* temp function 

//TODO: thies are the list function from libft

int		ft_atoi(const char *str);
int		ft_isdigit(int c);

t_list	*ft_lstnew(int number);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);

#endif