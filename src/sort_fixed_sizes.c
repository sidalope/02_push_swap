/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fixed_sizes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:21:58 by abisiani          #+#    #+#             */
/*   Updated: 2025/12/14 13:15:13 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	insert_remainder(t_stacks *stacks)
{
	int		min_rank;
	int		min_b;

	if (!stacks->b)
		return (0);
	min_rank = stacks->a->rank;
	min_b = get_min_rank(stacks->b);
	if (min_b < min_rank)
		min_rank = min_b;
	if (stacks->b->rank > stacks->b->next->rank)
		swap(&(stacks->b), stacks);
	if (stacks->b->rank == min_rank)
		push(&(stacks->b), &(stacks->a), stacks);
	while (stacks->b)
	{
		if (stacks->b->rank == stacks->a->rank - 1
			|| stacks->b->rank == stacks->a->prev->rank + 1)
			push(&(stacks->b), &(stacks->a), stacks);
		rotate(&(stacks->a), stacks);
	}
	return (1);
}

static void	sort_three(t_stacks *stacks)
{
	if (is_sorted(stacks->a))
		return ;
	if (stacks->a->rank < stacks->a->next->rank)
	{
		if (stacks->a->next->next->rank < stacks->a->rank)
			rrotate(&(stacks->a), stacks);
		else
		{
			swap(&(stacks->a), stacks);
			rotate(&(stacks->a), stacks);
		}
	}
	else if (stacks->a->next->next->rank < stacks->a->rank)
	{
		if (stacks->a->next->rank < stacks->a->next->next->rank)
			rotate(&(stacks->a), stacks);
		else
		{
			swap(&(stacks->a), stacks);
			rrotate(&(stacks->a), stacks);
		}
	}
	else
		swap(&(stacks->a), stacks);
}

/* Sort stack a of sizes two to five */
void	sort_five(t_stacks *stacks)
{
	if (!stacks || !stacks->a || ft_lstsize(stacks->a, 0, stacks->a) == 1)
		ps_error(stacks);
	if (ft_lstsize(stacks->a, 0, stacks->a) == 2)
	{
		swap(&(stacks->a), stacks);
		return ;
	}
	while (ft_lstsize(stacks->a, 0, stacks->a) > 3)
		push(&(stacks->a), &(stacks->b), stacks);
	sort_three(stacks);
	insert_remainder(stacks);
	position_a(stacks);
}
