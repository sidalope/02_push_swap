/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_merge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:07:00 by abisani           #+#    #+#             */
/*   Updated: 2025/11/19 22:47:04 by abisani          ###   ########.fr       */
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

static void	calc_min_ops(t_costs_tuple *tup)
{
	if (!tup->rot_b)
	{
		if (tup->rot < -tup->rrot)
			tup->min = tup->rot;
		else
			tup->min = -tup->rrot;
	}
	else if (tup->rot_b > 0)
	{
		if (max(tup->rot, tup->rot_b) > tup->rot_b + -tup->rrot)
			tup->min = tup->rot_b + -tup->rrot;
		else
			tup->min = max(tup->rot, tup->rot_b);
	}
	else if (tup->rot_b < 0)
	{
		if (max(-tup->rot_b, -tup->rrot) > -tup->rot_b + tup->rot)
			tup->min = -tup->rot_b + tup->rot;
		else
			tup->min = max(tup->rot, tup->rot_b);
	}
}

// Looks through b and finds the cheapest element to push
// return the costs tuple of the element
// use that tuple to execute the move
static t_costs_tuple	*find_cheapest(t_stacks *stacks)
{
	t_list_node		*curr;
	t_costs_tuple	*cheapest;

	if (!stacks || !stacks->b)
		return (0);
	curr = stacks->b;
	cheapest = curr->costs;
	while (1)
	{
		calc_min_ops(curr->costs);
		if (curr->costs->min < cheapest->min)
			cheapest = curr->costs;
		curr = curr->next;
		if (curr == stacks->b)
			break ;
	}
	return (cheapest);
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
	costs->rot = 0;
	costs->rrot = 0;
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
			curr->costs->rot_b = i;
		else
			curr->costs->rot_b = i - size_b;
		curr = curr->next;
		i++;
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
		// ft_printf("MARK");
		if (!calculate_costs_b(stacks))
			return (0);
		// ft_printf("MARK");
		// print_costs(stacks);
		cheapest = find_cheapest(stacks);
		// check there is a tup
		execute_ops(stacks, cheapest);
		// ft_printf("MARK");
	}
	return (1);
}

