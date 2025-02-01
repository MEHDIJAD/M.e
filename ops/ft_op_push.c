/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:10:52 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/01 15:49:55 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_op_push(t_list **stack_dst, t_list **stack_src)
{
	t_list	*temp;
	
	if (!stack_src || !*stack_src)
		return ;
	temp = *stack_src; //* get the first node of src
	*stack_src = (*stack_src)->next; //* update the src
	temp->next = *stack_dst; //* add the front of dst
	*stack_dst = temp; //* make temp the new head
}