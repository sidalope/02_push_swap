/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_merge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:07:00 by abisani           #+#    #+#             */
/*   Updated: 2025/11/20 00:30:42 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_costs(t_stacks *stacks)
// {
// 	t_list_node	*start;
// 	t_list_node	*c;

// 	start = stacks->b;
// 	c = stacks->b;
// 	ft_printf("COSTS:\n");
// 	do {
//     ft_printf("rot: %i, rrot: %i, rot b: %i \n", c->costs->rot, c->costs->rrot, c->costs->rot_b);
//     	c = c->next;
// 	} while (c != start);
// }

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

// takes a rank and finds the smallest rank in a that's bigger than its argument
// returns positive number for rotations from the top, or negative for rrotations
// can return tuple with pos and negative??
static t_costs_tuple	*get_target_a(t_stacks *stacks, int size_a, int rank_b)
{
	int				rotations;
	t_list_node		*curr;
	t_costs_tuple	*costs;

	rotations = 0;
	curr = stacks->a;
	costs = (t_costs_tuple *) malloc(sizeof(t_costs_tuple));
	if (!costs)
		return (ps_error(), NULL);
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

// for every element in b
//	get and assign its target costs
//	get b rotation costs
// calculate total cheapest rotations
//	ra rb, rra rrb, rra rb, ra rrb
static int	calculate_costs_b(t_stacks *stacks)
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
		if (!curr->costs)
			return (0);
		if (i < size_b / 2)
			curr->costs->rot_b = i++;
		else
			curr->costs->rot_b = i++ - size_b;
		curr = curr->next;
	}
	return (1);
}

int	merge_b(t_stacks *stacks)
{
	t_costs_tuple	*cheapest;

	cheapest = NULL;
	if (!stacks || !stacks->b)
		return (ps_error(), 0);
	while (stacks->b)
	{
		if (!calculate_costs_b(stacks))
			return (0);
		cheapest = find_cheapest(stacks);
		execute_ops(stacks, cheapest);
	}
	return (1);
}

