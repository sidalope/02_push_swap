/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:37:56 by abisani           #+#    #+#             */
/*   Updated: 2025/11/05 12:24:50 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// chunk sort
// - Divide the ranks into subsets
// - Pick out the subsets one at a time
//         - b will be largest first, so start with smallest ranks
//         - Find the first elem of the current subset from the top of a
//         - Find the first elem of the current subset from the bottom of a
//         - Find which is fastest to move to b
//         - ? Find the spot in b in which it goes
//         - Rotate or rrotate a (and b ? ) in position and push it to b; pb
//         - Rotate b so largest rank is at the top 
// - repeat for all other subsets 
// - rotate b to have largest first
// - push b to a

// merge sort
// initalise
//		split_a recursively until a is a sorted pair
//		set sort_sizes_a to 0
//		every call adds a node to sort_sizes_b
// while (!is_sorted(a) && there is something in b)
//		if (sort_sizes_a > 0)
//			split_a (change sort_sizes_a and add node to sort_sizes_b)
//				rotates down the largest and pushes the smallest halves
//			rrotate the larger half back up
//		else if (sort_sizes_b > 0)
//			send b back to a and (remove sort_sizes_b and add node to sort_sizes_a)

// radix sort
// find largest number of bits
//		use largest number and shift it right by varying amounts until it's 0
// (largest num_of_bits++ times)
// 		go through the whole of a and push what isn't 0 at >> num_of_bits
// return everything to a

// Optimisations?
// Unfortunately you have to rotate a fully to keep the list sorted
// Identify radixes that don't require sorting to eliminate a whole step?
// Do a bloody handstand.
