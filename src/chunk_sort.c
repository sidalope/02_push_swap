/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:43:15 by abisani           #+#    #+#             */
/*   Updated: 2025/12/18 11:57:59 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push all but the largest rank from the last chunk in A */
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

/* Main chunk sort entry point */
void	chunk_sort(t_stacks *stacks)
{
	split_pairs(stacks);
	push_last_chunk(stacks);
	merge_b(stacks);
	position_a(stacks);
}
