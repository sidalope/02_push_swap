/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   halfway_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:37:26 by abisani           #+#    #+#             */
/*   Updated: 2025/11/06 13:44:17 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
			rotate(&(stacks->b), stacks->a);
	else if (moves < 0)
		while (moves++)
			rrotate(&(stacks->b), stacks->a);
	push(&(stacks->b), &(stacks->a), stacks->a);
	if (min_flag)
		rotate(&(stacks->a), stacks->a);
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
	while (stacks->b)
	{
		if (get_node_distance(stacks, min) < get_node_distance(stacks, max))
			position_push_b(stacks, get_node_distance(stacks, min++), 1);
		else
			position_push_b(stacks, get_node_distance(stacks, max--), 0);
	}
	send_top_ranks(stacks);
	max = set_length / 2 - 1;
	min = 0;
	while (stacks->b)
	{
		if (get_node_distance(stacks, min) < get_node_distance(stacks, max))
			position_push_b(stacks, get_node_distance(stacks, min++), 1);
		else
			position_push_b(stacks, get_node_distance(stacks, max--), 0);
	}
	print_lists(stacks);
	print_ranks(stacks);
// 8. Rotate a into final position
	ft_printf("REACHED final\n");
}
