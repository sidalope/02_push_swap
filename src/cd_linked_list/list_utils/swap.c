/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:15:02 by abisiani          #+#    #+#             */
/*   Updated: 2025/12/18 12:46:10 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	log_swap(t_list_node **lst, t_stacks *stacks)
{
	if (*lst == stacks->a)
	{
		if (!log_op(&(stacks->log), "sa"))
			ps_error(stacks);
	}
	else
	{
		if (!log_op(&(stacks->log), "sb"))
			ps_error(stacks);
	}
}

void	swap(t_list_node **lst, t_stacks *stacks)
{
	t_list_node	*second;
	t_list_node	*third;
	t_list_node	*last;

	if (!lst || !*lst || (*lst)->next == *lst)
		return ;
	log_swap(lst, stacks);
	second = (*lst)->next;
	third = (*lst)->next->next;
	if (third == *lst)
	{
		*lst = second;
		return ;
	}
	last = (*lst)->prev;
	(*lst)->next = third;
	(*lst)->prev = second;
	second->next = *lst;
	second->prev = last;
	third->prev = *lst;
	last->next = second;
	*lst = second;
}
