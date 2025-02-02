/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:12:12 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/01 14:06:07 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_fill(char *str, t_list **list)
{
	int	i;
	int	number;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-')
		{
			number = ft_atoi(&str[i]);
			if (number > INT_MAX || number < INT_MIN)
			{
				ft_lstclear(list); 
				exit(0);
			}
			ft_lstadd_back(list, ft_lstnew(number));
		}
		while (ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-')
			i++;
	}
}
void ft_fill_stack_a(char **vic, t_list **list)
{
	int	i;

	i = 1;
	while (vic[i] != NULL)
		ft_fill(vic[i++], list);
	ft_check_double(*list);
}