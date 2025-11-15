/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:14:56 by abisiani          #+#    #+#             */
/*   Updated: 2025/11/15 10:14:08 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	rotate(t_list_node **lst, t_stacks *stacks)
{
	if (!lst || !*lst)
		return (-1);
	if (*lst == stacks->a)
		log_op(&(stacks->log), "ra");
	else
		log_op(&(stacks->log), "rb");
	*lst = (*lst)->next;
	return (0);
}

int	rrotate(t_list_node **lst, t_stacks *stacks)
{
	if (!lst || !*lst)
		return (-1);
	if (*lst == stacks->a)
		log_op(&(stacks->log), "rra");
	else
		log_op(&(stacks->log), "rrb");
	*lst = (*lst)->prev;
	return (0);
}
