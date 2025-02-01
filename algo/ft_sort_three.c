/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:59:14 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/01 19:29:27 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//* for 3 number 

void	ft_sort_three(t_list **stack_a)
{
	int	t;
	int	m;
	
	t = (*stack_a)->index;
	m = (*stack_a)->next->index;
	if (t == 0 && m == 2)
	{
		ft_op_rrotate(stack_a);
		ft_op_swap(stack_a);
	}
	else if (t == 1 && m == 0)
		ft_op_swap(stack_a);
	else if (t == 1 && m == 2)
		ft_op_rrotate(stack_a);
	else if (t == 2 && m == 0)
		ft_op_rrotate(stack_a);
	else if (t == 2 && m == 1)
	{
		ft_op_swap(stack_a);
		ft_op_rrotate(stack_a);
	}
}


