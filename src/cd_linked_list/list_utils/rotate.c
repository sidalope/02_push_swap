/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:14:56 by abisiani          #+#    #+#             */
/*   Updated: 2025/12/18 12:45:50 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate(t_list_node **lst, t_stacks *stacks)
{
	if (!lst || !*lst)
		return ;
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
}

void	rrotate(t_list_node **lst, t_stacks *stacks)
{
	if (!lst || !*lst)
		return ;
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
}
