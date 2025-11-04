/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:15:02 by abisiani          #+#    #+#             */
/*   Updated: 2025/11/04 11:16:26 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	swap(t_list_node **lst, t_list_node *list_a)
{
	t_list_node	*second;
	t_list_node	*third;
	t_list_node	*last;

	if (!lst || !*lst || (*lst)->next == *lst)
		return (-1);
	if (*lst == list_a)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
	second = (*lst)->next;
	third = (*lst)->next->next;
	if (third == *lst)
	{
		*lst = second;
		return (0);
	}
	last = (*lst)->prev;
	(*lst)->next = third;
	(*lst)->prev = second;
	second->next = *lst;
	second->prev = last;
	third->prev = *lst;
	last->next = second;
	*lst = second;
	return (0);
}
