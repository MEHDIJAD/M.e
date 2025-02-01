/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:55:31 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/01 14:18:08 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_op_swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next) //? if no double pointer || !no stack: list empty || now next to swap: only one node 
		return ;
	first = *stack; //* so first points to the first node
	second = first->next; //* so second points to second
	first->next = second->next; //* next for first become next for second so it will take it place
	second->next = first; //* second next become first , swap
	*stack = second; //* second becomes new head
}