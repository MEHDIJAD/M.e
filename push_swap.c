/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:13:21 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/28 21:10:31 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void del(t_list *list)
{
	free(list->content);
}
void ft_fill(char *str, t_list * list)
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
			number = ft_atoi(str[i]);
			if (number > INT_MAX || number < INT_MIN)
			{
				ft_lstclear(list,del);
				exit(0);
			}
		}
		while (ft_isdigit || str[i] == '+' || str[i] == '-')
			i++;
	}
}
void ft_fill_list(char *av[], t_list *list)
{
	int	i;

	i = 1;
	while (av[i] != NULL)
	{
		ft_fill(av[i++], list);
	}
}
int main(int ac, char *av[])
{
	t_list *list;
	
	if (ac == 1)
		return(1);
	ft_check_input(av);	
	ft_fill_list(av, list);	
}