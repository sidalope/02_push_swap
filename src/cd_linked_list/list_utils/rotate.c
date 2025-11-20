/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:14:56 by abisiani          #+#    #+#             */
/*   Updated: 2025/11/20 01:45:42 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	rotate(t_list_node **lst, t_stacks *stacks)
{
	if (!lst || !*lst)
		return (-1);
	if (*lst == stacks->a)
	{
		if (!log_op(&(stacks->log), "ra"))
			return (ps_error(), 0);
	}
	else
	{
		if (!log_op(&(stacks->log), "rb"))
			return (ps_error(), 0);
	}
	*lst = (*lst)->next;
	return (0);
}

int	rrotate(t_list_node **lst, t_stacks *stacks)
{
	if (!lst || !*lst)
		return (-1);
	if (*lst == stacks->a)
	{
		if (!log_op(&(stacks->log), "rra"))
			return (ps_error(), 0);
	}
	else
	{
		if (!log_op(&(stacks->log), "rrb"))
			return (ps_error(), 0);
	}
	*lst = (*lst)->prev;
	return (0);
}
