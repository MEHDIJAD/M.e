/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:40:01 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/31 20:42:55 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_list *lst)
{
	t_list	*current;
	
	current = lst;
	while (current != NULL)
	{
		ft_printf(1, "%d ", current->number);
		ft_printf(1, "%d\n", current->index);
		
		current = current->next;
	}
}