/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:43:15 by abisani           #+#    #+#             */
/*   Updated: 2025/11/21 22:02:14 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!split_pairs(stacks))
		return (0);
	push_last_chunk(stacks);
	if (!merge_b(stacks))
		return (0);
	position_a(stacks);
	return (1);
}
