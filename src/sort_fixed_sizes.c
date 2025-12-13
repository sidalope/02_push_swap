/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fixed_sizes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:21:58 by abisiani          #+#    #+#             */
/*   Updated: 2025/12/13 17:42:32 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

static int	insert_remainder(t_stacks *stacks)
{
	int	ins_rank;

	if (!stacks->b)
		return (0);
	if (stacks->b->rank > stacks->b->next->rank)
		swap(&(stacks->b), stacks);
	while (stacks->b)
	{
		ins_rank = stacks->b->rank;
		while (stacks->a->prev->rank != ins_rank - 1)
			rotate(&(stacks->a), stacks);
		push(&(stacks->b), &(stacks->a), stacks);
	}
	return (1);
}

static void	sort_three(t_stacks *stacks)
{
	int		a;
	int		b;
	int		c;

	a = stacks->a->rank;
	b = stacks->a->next->rank;
	c = stacks->a->next->next->rank;
	if (is_sorted(stacks->a))
		return ;
	if (a < b)
	{
		if (c < a)
			rrotate(&(stacks->a), stacks);
		else
		{
			swap(&(stacks->a), stacks);
			rotate(&(stacks->a), stacks);
		}
	}
	else if (c < a)
	{
		if (b < c)
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
int	sort_five(t_stacks *stacks)
{
	if (!stacks || !stacks->a || ft_lstsize(stacks->a, 0, stacks->a) == 1)
		return (ps_error(), 0);
	if (ft_lstsize(stacks->a, 0, stacks->a) == 2)
		swap(&(stacks->a), stacks);
	while (ft_lstsize(stacks->a, 0, stacks->a) > 3)
		push(&(stacks->a), &(stacks->b), stacks);
	sort_three(stacks);
	insert_remainder(stacks);
	position_a(stacks);
	print_lists(stacks);
	return (1);
}
