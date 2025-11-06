/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:15:02 by abisiani          #+#    #+#             */
/*   Updated: 2025/11/06 22:16:02 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	log_action(t_list_node **lst, t_stacks *stacks)
{
	if (*lst == stacks->a)
		log_op(&(stacks->log), "sa");
	else
		log_op(&(stacks->log), "sb");
}

int	swap(t_list_node **lst, t_stacks *stacks)
{
	t_list_node	*second;
	t_list_node	*third;
	t_list_node	*last;

	if (!lst || !*lst || (*lst)->next == *lst)
		return (-1);
	log_action(lst, stacks);
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
