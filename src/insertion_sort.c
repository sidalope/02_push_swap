/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:26:56 by abisani           #+#    #+#             */
/*   Updated: 2025/11/15 10:15:18 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_next_rank(t_stacks *stacks, int next_rank)
{
	while (stacks->a->rank != next_rank)
		rotate(&(stacks->a), stacks->a);
}

int	sort(t_stacks *stacks, size_t len)
{
	size_t	next_rank;

	next_rank = 0;
	while (next_rank < len)
	{
		find_next_rank(stacks, next_rank++);
		push(&(stacks->a), &(stacks->b), stacks->a);
	}
	while (len--)
		push(&(stacks->b), &(stacks->a), stacks->a);
	if (stacks->a && is_sorted(stacks->a))
		return (1);
	return (0);
}
