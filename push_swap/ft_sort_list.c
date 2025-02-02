/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:29:14 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/01 19:24:20 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_list(t_list **stack_a, t_list **stack_b)
{
	int	size;

	(void)stack_b;
	size = ft_lstsize(*stack_a);
	if (size <= 3)
		ft_sort_three(stack_a);	
	//else if (size <= 5)
	//	ft_sort_five(stack_a, stack_b);
}
