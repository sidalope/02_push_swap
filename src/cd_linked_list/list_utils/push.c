/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 19:45:41 by abisiani          #+#    #+#             */
/*   Updated: 2025/12/18 13:18:33 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	log_push(t_stacks *stacks, t_list_node **src)
{
	if (*src == stacks->a)
	{
		if (!log_op(&(stacks->log), "pb"))
			ps_error(stacks);
	}
	else
	{
		if (!log_op(&(stacks->log), "pa"))
			ps_error(stacks);
	}
}

void	push(t_list_node **src, t_list_node **dest, t_stacks *stacks)
{
	t_list_node	*second;
	t_list_node	*last;

	if (!src || !*src)
		return ;
	log_push(stacks, src);
	if ((*src)->next == *src)
	{
		ft_lstadd_front(dest, *src);
		*src = NULL;
		return ;
	}
	second = (*src)->next;
	last = (*src)->prev;
	ft_lstadd_front(dest, *src);
	second->prev = last;
	last->next = second;
	*src = second;
}
