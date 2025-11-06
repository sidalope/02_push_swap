/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   halfway_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:37:26 by abisani           #+#    #+#             */
/*   Updated: 2025/11/06 20:52:53 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Halfway algo (Split only half way before making it recursive)
// 	(This actually seems to allow ignoring list lengths)
// 1. find median of a
// 2. send everything below it to b
// 3. find the smallest and largest elements of b
// 	- This can be expanded to include the next smallest and largest
// 4. calculate which is more efficient to send to a
// 5. perform the rotations and the push for the cheapest
// 6. Repeat from step 3 until b is empty
// 7. Repeat from step 2 for everything below the median
// 8. Rotate a into final position

#include "push_swap.h"

static void	position_push_b(t_stacks *stacks, int moves, int min_flag)
{
	if (moves > 0)
		while (moves--)
			rotate(&(stacks->b), stacks);
	else if (moves < 0)
		while (moves++)
			rrotate(&(stacks->b), stacks);
	push(&(stacks->b), &(stacks->a), stacks);
	if (min_flag)
		rotate(&(stacks->a), stacks);
}

static void	position_a_final(t_stacks *stacks)
{
	int	moves;

	moves = get_node_dist(stacks->a, 0);
	if (moves == 0)
		return ;
	else if (moves > 0)
	{
		while (stacks->a->rank != 0)
			rotate(&(stacks->a), stacks);
	}
	else
	{
		while (stacks->a->rank != 0)
			rrotate(&(stacks->a), stacks);
	}

}

static void	subsort_b(t_stacks *stacks, int min, int max)
{
	while (stacks->b)
	{
		if (get_node_dist(stacks->b, min) < get_node_dist(stacks->b, max))
			position_push_b(stacks, get_node_dist(stacks->b, min++), 1);
		else
			position_push_b(stacks, get_node_dist(stacks->b, max--), 0);
	}
}

void	halfway_sort(t_stacks *stacks)
{
	int		min;
	int		max;
	int		set_length;

	set_length = ft_lstsize(stacks->a, 0, stacks->a);
	min = set_length / 2;
	max = set_length - 1;
	send_bottom_ranks(stacks);
	subsort_b(stacks, min, max);
	send_top_ranks(stacks);
	max = set_length / 2 - 1;
	min = 0;
	subsort_b(stacks, min, max);
	position_a_final(stacks);
}
