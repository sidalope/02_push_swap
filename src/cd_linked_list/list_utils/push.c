/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:09:34 by abisiani          #+#    #+#             */
/*   Updated: 2025/12/14 12:33:48 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	log_push(t_stacks *stacks, t_list_node **src)
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
	return (1);
}

int	push(t_list_node **src, t_list_node **dest,\
			t_stacks *stacks)
{
	t_list_node	*second;
	t_list_node	*last;

	if (!src || !*src)
		return (-1);
	if (!log_push(stacks, src))
		return (0);
	if ((*src)->next == *src)
	{
		ft_lstadd_front(dest, *src);
		*src = NULL;
		return (0);
	}
	second = (*src)->next;
	last = (*src)->prev;
	ft_lstadd_front(dest, *src);
	second->prev = last;
	last->next = second;
	*src = second;
	return (0);
}
