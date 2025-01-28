/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:29:16 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/28 13:21:17 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		sizelst;
	t_list	*ptr;

	if (!lst)
		return (0);
	sizelst = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		sizelst++;
		ptr = ptr->next;
	}
	return (sizelst);
}
