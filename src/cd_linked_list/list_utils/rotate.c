/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:14:56 by abisiani          #+#    #+#             */
/*   Updated: 2025/12/14 12:29:21 by abisani          ###   ########.fr       */
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
			ps_error(stacks);
	}
	else
	{
		if (!log_op(&(stacks->log), "rb"))
			ps_error(stacks);
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
			ps_error(stacks);
	}
	else
	{
		if (!log_op(&(stacks->log), "rrb"))
			ps_error(stacks);
	}
	*lst = (*lst)->prev;
	return (0);
}
