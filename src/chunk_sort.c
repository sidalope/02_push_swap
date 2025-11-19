/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:43:15 by abisani           #+#    #+#             */
/*   Updated: 2025/11/19 22:46:03 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// get the largest rank in the current list. Is this r. better than tracking
// //	the size of the set?
static int	get_min_rank(t_list_node *lst)
{
	int			lst_size;
	int			min;

	lst_size = ft_lstsize(lst, 0, lst);
	min = lst->rank;
	while (lst_size--)
	{
		if (lst->rank < min)
			min = lst->rank;
		lst = lst->next;
	}
	return (min);
}

// push the odd, odd sized chunk left in a, rotating elements that happen
//	in the right order. It will leave at least 
//	return the number of elements pushed to b (the size of chunk at the 
//		top of b)
static int	push_last_chunk(t_stacks *stacks)
{
	int		nodes_pushed;
	int		size_a;
	int		min_rank;

	nodes_pushed = -1;
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
		{
			push(&(stacks->a), &(stacks->b), stacks);
			if (nodes_pushed < 0)
				nodes_pushed = 0;
			nodes_pushed++;
		}
	}
	if (nodes_pushed < 0)
		return (ps_error(), nodes_pushed);
	return (nodes_pushed);
}

// Rotate a with it's smallest rank on top
static void	position_a(t_stacks *stacks)
{
	int		size_a;
	int		min_rank;

	size_a = ft_lstsize(stacks->a, 0, stacks->a);
	min_rank = get_min_rank(stacks->a);
	if (stacks->a->rank == 0)
		return ;
	if (stacks->a->rank < size_a / 2)
	{
		while (stacks->a->rank != min_rank)
			rrotate(&(stacks->a), stacks);
	}
	else
		while (stacks->a->rank != min_rank)
			rotate(&(stacks->a), stacks);
}

int	chunk_sort(t_stacks *stacks)
{
	ft_printf("\n\n-- BEFORE SPLIT --\n");
	print_ranks(stacks);
	if (!split_pairs(stacks))
		return (0);
	ft_printf("\n\n-- AFTER SPLIT --\n");
	print_ranks(stacks);
	if (push_last_chunk(stacks) < 0)
		return (0);
	ft_printf("\n\n-- AFTER LAST PUSH --\n");
	print_ranks(stacks);
	if (!merge_b(stacks))
		return (0);
	ft_printf("\n\n-- AFTER MERGE --\n");
	print_ranks(stacks);
	position_a(stacks);
	ft_printf("\n\n-- AFTER REPOSITION --\n");
	print_ranks(stacks);
	return (1);
}
