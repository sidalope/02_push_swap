/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_merge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:07:00 by abisani           #+#    #+#             */
/*   Updated: 2025/12/14 12:06:51 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Find position of the smallest rank in A (for the largest rank_b) */
static void	get_target_a_min(t_stacks *stacks, int size_a, t_costs_tuple *costs)
{
	int			rotations;
	t_list_node	*curr;
	int			min_rank;
	int			min_pos;

	rotations = 0;
	curr = stacks->a;
	min_rank = INT_MAX;
	min_pos = 0;
	while (rotations < size_a)
	{
		if (curr->rank < min_rank)
		{
			min_rank = curr->rank;
			min_pos = rotations;
		}
		curr = curr->next;
		rotations++;
	}
	costs->rot = min_pos;
	costs->rrot = min_pos - size_a;
}

/* Find target insertion position in A for a rank (rank_b) */
static t_costs_tuple	*get_target_a(t_stacks *stacks, int size_a, int rank_b)
{
	int				rotations;
	t_list_node		*curr;
	t_costs_tuple	*costs;

	rotations = 0;
	curr = stacks->a;
	costs = (t_costs_tuple *) malloc(sizeof(t_costs_tuple));
	if (!costs)
		ps_error(stacks);
	costs->rank = INT_MAX;
	costs->rot_b = 0;
	while (rotations < size_a)
	{
		if (curr->rank < costs->rank && curr->rank > rank_b)
		{
			costs->rank = curr->rank;
			costs->rot = rotations;
			costs->rrot = rotations - size_a;
		}
		curr = curr->next;
		rotations++;
	}
	if (costs->rank == INT_MAX)
		get_target_a_min(stacks, size_a, costs);
	return (costs);
}

/*
** For every element in b:
**   - Get and assign its target costs
**   - Get b rotation costs
**   - Calculate total cheapest rotations
*/
static void	calculate_costs_b(t_stacks *stacks)
{
	int				i;
	int				size_b;
	int				size_a;
	t_list_node		*curr;

	i = 0;
	curr = stacks->b;
	size_b = ft_lstsize(stacks->b, 0, stacks->b);
	size_a = ft_lstsize(stacks->a, 0, stacks->a);
	while (i < size_b)
	{
		if (curr->costs)
			free(curr->costs);
		curr->costs = get_target_a(stacks, size_a, curr->rank);
		if (i < size_b / 2)
			curr->costs->rot_b = i++;
		else
			curr->costs->rot_b = i++ - size_b;
		curr = curr->next;
	}
}

/* Merge all elements of B with A using the next cheapest operation */
void	merge_b(t_stacks *stacks)
{
	t_costs_tuple	*cheapest;

	cheapest = NULL;
	if (!stacks || !stacks->b)
		ps_error(stacks);
	while (stacks->b)
	{
		calculate_costs_b(stacks);
		cheapest = find_cheapest(stacks);
		execute_ops(stacks, cheapest);
	}
}
