/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:10:08 by abisiani          #+#    #+#             */
/*   Updated: 2025/11/03 17:16:21 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

// split() could also check whether the first part of the list is ordered

void	print_lists(t_stacks *stacks)
{
	ft_printf("a: ");
	print_lst_content(stacks->a, stacks->a);
	ft_printf("b: ");
	print_lst_content(stacks->b, stacks->b);
}

static void	split_a(t_stacks *stacks, size_t len, size_t starting_rank)
{
	size_t			min;
	size_t			mid;

	ft_printf("\nsplit_a\n");
	ft_printf("len: %i\n", len);
	ft_printf("starting rank: %i\n", starting_rank);
	min = starting_rank + (len / 3);
	mid = min + (len / 3);
	if (len == 0 || len == 1)
		return ;
	else if (len == 2)
	{
		if (stacks->a->rank != starting_rank)
			swap(&(stacks->a));
		return ;
	}
	ft_lstadd_front(&(stacks->list_sizes_min), ft_lstnew(0));
	ft_lstadd_front(&(stacks->list_sizes_mid), ft_lstnew(0));
	ft_lstadd_front(&(stacks->list_sizes_max), ft_lstnew(0));
	while (len)
	{
		if (stacks->a->rank < min)
		{
			stacks->list_sizes_min->content++;
			// ft_printf("\n(%i)rank %i to min\n", stacks->a->content, stacks->a->rank);
			push(&(stacks->a), &(stacks->b));
			rotate(&(stacks->b));
		}
		else if (stacks->a->rank < mid)
		{
			stacks->list_sizes_mid->content++;
			// ft_printf("\n(%i)rank %i to mid\n", stacks->a->content, stacks->a->rank);
			push(&(stacks->a), &(stacks->b));
		}
		else
		{
			stacks->list_sizes_max->content++;
			// ft_printf("\n(%i)rank %i to max\n", stacks->a->content, stacks->a->rank);
			rotate(&(stacks->a));
		}
		len--;
		// print_lists(stacks);
	}
	// ft_printf("\n");
	// print_lst_sizes(stacks);
	// ft_printf("\n");
}

// rrotate max numbers up and split again
static void	split_max(t_stacks *stacks, size_t len, size_t starting_rank)
{
	int			i;

	i = 0;
	ft_printf("\nsplit_max\n");
	ft_printf("\nlen: %i\n", len);
	if (len == 0)
		return ;
	stacks->list_sizes_max->next->content += len;
	if (len == 1 || len == 2)
	{
		stacks->list_sizes_max->content = 0;
		rrotate(&(stacks->a));
	}
	if (len == 2)
	{
		rrotate(&(stacks->a));
		if (stacks->a->rank != starting_rank)
			swap(&(stacks->a));
	}
	else
	{
		// while max_len is > 2 and a is not sorted, call split_a and split_max
		// Then call split_max once more
		while (stacks->list_sizes_max->content > 2 && !is_sorted(stacks->a))
		{
			while (i++ < stacks->list_sizes_max->content)
				rrotate(&(stacks->a));
			split_a(stacks, stacks->list_sizes_max->content, starting_rank);
		}
	}
}

// Push to a and split the top of a
static void	split_mid(t_stacks *stacks, size_t len, size_t starting_rank)
{
	size_t			i;

	i = 0;
	ft_printf("\nsplit_mid\n");
	ft_printf("len: %i\n", len);
	print_lists(stacks);
	print_lst_sizes(stacks);
	ft_printf("\n");
	stacks->list_sizes_mid->content = 0;
	if (len == 0 || len == 1)
		return ;
	else if (len == 2)
	{
		if (stacks->b->rank == starting_rank)
			swap(&(stacks->b));
		push(&(stacks->b), &(stacks->a));
		push(&(stacks->b), &(stacks->a));
		// update the size of max so that you know how many nodes are already sorted
		// But this actualy shouldn't matter. a will be sorted, and the next node of max 
		//		len, which will be the one in use later, already includes the size of mid.
		// stacks->list_sizes_mid->content = 0;
		// stacks->list_sizes_max->content += 2;
		return ;
	}
	// push to a and split_a()
	while (i++ < len)
		push(&(stacks->b), &(stacks->a));
	split_a(stacks, len, starting_rank);
}

// Push to a and split the top of a
static void	split_min(t_stacks *stacks, size_t len, size_t starting_rank)
{
	size_t			i;

	i = 0;
	ft_printf("\nsplit_min\n");
	stacks->list_sizes_min = 0;
	if (len == 0 || len == 1)
		return ;
	else if (len == 2)
	{
		rrotate(&(stacks->b));
		rrotate(&(stacks->b));
		if (stacks->b->rank == starting_rank)
			swap(&(stacks->b));
		push(&(stacks->b), &(stacks->a));
		push(&(stacks->b), &(stacks->a));
		return ;
	}
	while (i++ < len)
		push(&(stacks->b), &(stacks->a));
	split_a(stacks, len, starting_rank);
}

// Recursively call split_a until a is a sorted ingleton or pair
static void	init_split(t_stacks *stacks, size_t len, size_t starting_rank)
{
	if (len > 2)
	{
		// ft_printf("\nLENGTH: %i\n", len);
		split_a(stacks, len, starting_rank);
		starting_rank = starting_rank + (len / 3) * 2;
		len = ft_lstsize(stacks->a, 0, stacks->a);
		init_split(stacks, len, starting_rank);
	}
}

// Merge mid and min wth max
// Max must be previously merged by ..?
// while mid == 1, push mid then min to a, in order
void	merge(t_stacks *stacks)
{	
	if (stacks->list_sizes_mid && stacks->list_sizes_mid->content == 1)
	{
		ft_printf("\nMerge\n");	
		push (&(stacks->b), &(stacks->a));
		rrotate(&(stacks->b));
		push (&(stacks->b), &(stacks->a));
		ft_lstpop(&(stacks->list_sizes_min));
		ft_lstpop(&(stacks->list_sizes_mid));
		ft_lstpop(&(stacks->list_sizes_max));
		stacks->list_sizes_max->content += 2;
	}
}

	// init_split
	// merge b to a
	// while (there is something in b and a is not sorted)
	//		split:
	//			If the next mid > 1
	//				set the mid_length to 0
	//				split_mid (creating new lengths for min, mid, max)
	//					send mid to a and split_a() (creating new min, mid, max) 
	//				while (max is > 2)
	//					recursively split the new top of a (creating new lengths for min, mid, max)
	//					rrotate it back up 
	//					leaving sorted singleton or pair at the top
	//				while (mid > 0)
	//					msort
	//			else if mid == 1
	//				merge
	//			else if mid == 0
	//				continue ;
	//			If the next min > 1
	//				set the min_length to 0
	//				split_min (creating new lengths for min, mid, max)
	//					send min to a and split_a() (creating new min, mid, max) 
	//				while (max is > 2)
	//					recursively split the new top of a (creating new lengths for min, mid, max)
	//					rrotate it back up
	//					leaving sorted singleton or pair at the top
	//				while (min > 0)
	//					msort
	//			else if min == 1
	//				merge
	//			else if min == 0
	//				pop the list lengths
	//				return ;


void	split(t_stacks *stacks)
{
	size_t	starting_rank;

	starting_rank = stacks->a->rank - stacks->list_sizes_mid->content;
	//		while len_mid is > 1
	//			split_mid
	//			split_max, which leaves new lists for mid and min
	//		if len_mid == 1
	//			merge
	//		split_min
	//		split_max, which leaves new lists for mid and min
	//		call this again

	while (stacks->list_sizes_mid->content > 1)
	{
		print_lists(stacks);
		print_lst_sizes(stacks);
		if (0)
			split_min(stacks, stacks->list_sizes_min->content, starting_rank);

		split_mid(stacks, stacks->list_sizes_mid->content, starting_rank);
		print_lists(stacks);
		print_lst_sizes(stacks);
		
		split_max(stacks, stacks->list_sizes_max->content, starting_rank);
		print_lists(stacks);
		print_lst_sizes(stacks);
		
		merge(stacks);
		print_lists(stacks);
		print_lst_sizes(stacks);

		starting_rank = stacks->a->rank - stacks->list_sizes_min->content;
		split_min(stacks, stacks->list_sizes_mid->content, starting_rank);
		// split_max(stacks, stacks->list_sizes_max->content, starting_rank);
		// while (stacks->list_sizes_max->content > 2)
		// 	split_max(stacks, stacks->list_sizes_max->content, starting_rank);
		// // this cannot be the next operation
		// while (stacks->list_sizes_mid->content > 0)
		// 	split(stacks);
	}
	merge(stacks);
}

// Perform initial split and merge
// Push unsorted sublists to a
// Split and sort them
// Merge them 
void	msort(t_stacks *stacks, size_t len)
{
	//inititalise
	ft_printf("\nsize a: %i\n", ft_lstsize(stacks->a, 0, stacks->a));
	ft_printf("\nInit split\n");
	// Initial recursive split of a
	init_split(stacks, len, 0);
	print_lists(stacks);
	print_lst_sizes(stacks);
	ft_printf("\n*** Finished init split ***\n");
	// Call split_a again to make sure a is sorted (1 or 2 elem)
	split_a(stacks, stacks->list_sizes_max->content, len - 2);
	print_lists(stacks);
	print_lst_sizes(stacks);

	while (stacks->list_sizes_mid->content == 1)
	{
		push (&(stacks->b), &(stacks->a));
		rrotate(&(stacks->b));
		push (&(stacks->b), &(stacks->a));
		ft_lstpop(&(stacks->list_sizes_min));
		ft_lstpop(&(stacks->list_sizes_mid));
		ft_lstpop(&(stacks->list_sizes_max));
		print_lists(stacks);
		print_lst_sizes(stacks);
	}
	// After initialisation, recursively send whatever needs sorting to a, then split again
	// while (!is_sorted(stacks->a) && stacks->b->next)
	ft_printf("\n*** Split ***\n\n");
	split(stacks);
}
