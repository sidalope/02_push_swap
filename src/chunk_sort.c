/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:43:15 by abisani           #+#    #+#             */
/*   Updated: 2025/11/17 20:36:09 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	merge_b(t_stacks *stacks)
{
	if (!stacks)
		return (ps_error(), 0);
	return (1);
}

// Rotate a into position once sorted
// static void	position_a(t_stacks *stacks)
// {
// 	int		size_a;
// 	int		rank;

// 	size_a = ft_lstsize(stacks->a, 0, stacks->a);
// 	rank = stacks->a->rank;
// 	if (rank == 0)
// 		return ;
// 	if (rank < size_a / 2)
// 	{
// 		while (stacks->a->rank != 0)
// 			rrotate(&(stacks->a), stacks);
// 	}
// 	else
// 		while (stacks->a->rank != 0)
// 			rotate(&(stacks->a), stacks);
// }

int	chunk_sort(t_stacks *stacks)
{
	if (!split_pairs(stacks))
		return (0);
	if (!merge_b(stacks))
		return (0);
	// position_a(stacks);  // TODO: Call after Phase 2 merges B back to A
	return (1);
}
