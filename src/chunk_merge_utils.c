/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_merge_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 23:45:31 by abisani           #+#    #+#             */
/*   Updated: 2025/12/14 12:02:19 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Calculate minimum operations considering rotation directions */
static void	calc_min_ops(t_costs_tuple *tup)
{
	if (!tup->rot_b)
	{
		if (tup->rot < -tup->rrot)
			tup->min = tup->rot;
		else
			tup->min = -tup->rrot;
	}
	else if (tup->rot_b > 0)
	{
		if (max(tup->rot, tup->rot_b) > tup->rot_b + -tup->rrot)
			tup->min = tup->rot_b + -tup->rrot;
		else
			tup->min = max(tup->rot, tup->rot_b);
	}
	else if (tup->rot_b < 0)
	{
		if (max(-tup->rot_b, -tup->rrot) > -tup->rot_b + tup->rot)
			tup->min = -tup->rot_b + tup->rot;
		else
			tup->min = max(tup->rot, tup->rot_b);
	}
}

/*
** Look through B and find the cheapest element to push
** Return the costs tuple of the element
** Use that tuple to execute the move
** Optimiser aware, e.g. (ra, rb) considered one move
*/
t_costs_tuple	*find_cheapest(t_stacks *stacks)
{
	t_list_node		*curr;
	t_costs_tuple	*cheapest;

	if (!stacks || !stacks->b)
		return (0);
	curr = stacks->b;
	cheapest = curr->costs;
	while (1)
	{
		calc_min_ops(curr->costs);
		if (curr->costs->min < cheapest->min)
			cheapest = curr->costs;
		curr = curr->next;
		if (curr == stacks->b)
			break ;
	}
	return (cheapest);
}
