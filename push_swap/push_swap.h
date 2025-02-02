/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:11:11 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/01 18:02:51 by eel-garo         ###   ########.fr       */
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
void	ft_fill_stack_a(char **vic, t_list **list);
void	ft_check_double(t_list *list);
void	ft_index_stack_a(t_list **lst);
void	ft_sort_list(t_list **stack_a, t_list **stack_b);
void	ft_print_list(t_list *stack_a, t_list *stack_b, char a, char b); //* temp function 

//* operations
void	ft_op_swap(t_list **stack);
void	ft_op_rotate(t_list **stack);
void	ft_op_rrotate(t_list **stack);
void	ft_op_push(t_list **stack_dst, t_list **stack_src);

//* algor

void	ft_sort_three(t_list **stack_a);

void	ft_sort_five(t_list **stack_a, t_list **stack_b);

//TODO: thies are the list function from libft

int		ft_atoi(const char *str);
int		ft_isdigit(int c);

t_list	*ft_lstnew(int number);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **stack, t_list *new);

#endif