/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:21:54 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/01 14:37:20 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_op_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	
	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack; //* point to first number 
	*stack = (*stack)->next; //* move to second number
	first->next = NULL; //* detach the first node
	last = *stack; //* point last to the head
	while (last->next) //* move intel find the last node
		last = last->next;
	last->next = first; //* add first to the end of list
	
}