/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:13:21 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/01 19:29:52 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char *av[])
{
	t_list *stack_a;
	t_list	*stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return(ft_printf(2,"Error\n"), 1);
	ft_check_input(av);	
	ft_fill_stack_a(av, &stack_a);
	ft_index_stack_a(&stack_a);
	ft_print_list(stack_a,stack_b, 'A', 'B');
	ft_sort_list(&stack_a, &stack_b);
	ft_print_list(stack_a,stack_b, 'A', 'B');

	ft_lstclear(&stack_a);
}

