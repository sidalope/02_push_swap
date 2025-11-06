/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   halfway_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:37:26 by abisani           #+#    #+#             */
/*   Updated: 2025/11/06 10:45:44 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Halfway algo (Split only half way before making it recursive)
// 	(This actually seems to allow ignoring list lengths)
// 1. find median of a
// 2. send everything above it to b
// 3. find the smallest and largest elements of b
// 	- This can be exanded to include the next smallest and largest
// 4. calculate which is more efficient to send to a
// 5. perform the rotations and the push for the cheapest
// 6. Repeat from step 3 until b is empty
// 7. Repeat from step 2 for everything below the median
// 8. Rotate a into final position

#include "push_swap.h"

void	halfway_algo(t_stacks *stacks)
{
	int	median;

	median = ft_lstsize(stacks->a, 0, stacks->a) / 2;
	
}
