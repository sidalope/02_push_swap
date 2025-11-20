/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:15:02 by abisiani          #+#    #+#             */
/*   Updated: 2025/11/20 01:47:13 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	log_action(t_list_node **lst, t_stacks *stacks)
{
	if (*lst == stacks->a)
	{
		if (!log_op(&(stacks->log), "sa"))
			return (ps_error(), 0);
	}
	else
	{
		if (!log_op(&(stacks->log), "sb"))
			return (ps_error(), 0);
	}
	return (1);
}

int	swap(t_list_node **lst, t_stacks *stacks)
{
	t_list_node	*second;
	t_list_node	*third;
	t_list_node	*last;

	if (!lst || !*lst || (*lst)->next == *lst)
		return (-1);
	if (!log_action(lst, stacks))
		return (0);
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
