/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:13:21 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/31 20:40:19 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char *av[])
{
	t_list *list;
	
	list = NULL;
	if (ac == 1)
		return(ft_printf(2,"NO LIST!"), 1);
	ft_check_input(av);	
	ft_fill_list(av, &list);
	ft_index_list(&list);
	//ft_sort_list(&list);
	//ft_print_list(list); 
	ft_lstclear(&list);
}

