/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:43:15 by abisani           #+#    #+#             */
/*   Updated: 2025/12/14 12:07:11 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_last_chunk(t_stacks *stacks)
{
	int		size_a;
	int		min_rank;

	size_a = ft_lstsize(stacks->a, 0, stacks->a);
	min_rank = get_min_rank(stacks->a);
	while (size_a-- > 0)
	{
		if (stacks->a->rank == min_rank)
		{
			rotate(&(stacks->a), stacks);
			min_rank++;
		}
		else
			push(&(stacks->a), &(stacks->b), stacks);
	}
}

int	chunk_sort(t_stacks *stacks)
{
	split_pairs(stacks);
	push_last_chunk(stacks);
	merge_b(stacks);
	position_a(stacks);
	return (1);
}
