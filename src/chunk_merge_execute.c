/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_merge_execute.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:06:45 by abisani           #+#    #+#             */
/*   Updated: 2025/11/19 23:16:38 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ops_a(t_costs_tuple *tup)
{
	if (!tup->rot_b)
	{
		if (tup->rot < -tup->rrot)
			return (tup->rot);
		return (tup->rrot);
	}
	else if (tup->rot_b > 0)
	{
		if (max(tup->rot, tup->rot_b) < tup->rot_b + -tup->rrot)
			return (tup->rot);
		return (tup->rrot);
	}
	else if (tup->rot_b < 0)
	{
		if (max(-tup->rot_b, -tup->rrot) < -tup->rot_b + tup->rot)
			return (tup->rrot);
		return (tup->rot);
	}
	return (0);
}

static void	rotate_list(t_stacks *stacks, t_list_node **lst, int ops)
{
	while (ops)
	{
		if (ops > 0)
		{
			rotate(lst, stacks);
			ops--;
		}
		else
		{
			rrotate(lst, stacks);
			ops++;
		}
	}
}

// Take a t_costs_tuple and execute the smallest number of 
//	operations on the list.
// Maybe should actually just go in merge_b
int	execute_ops(t_stacks *stacks, t_costs_tuple *ops_tup)
{
	if (!stacks || !stacks->a || !stacks->b || !ops_tup)
		return (ps_error(), 0);
	rotate_list(stacks, &(stacks->a), ops_a(ops_tup));
	rotate_list(stacks, &(stacks->b), ops_tup->rot_b);
	push(&(stacks->b), &(stacks->a), stacks);
	return (1);
}
