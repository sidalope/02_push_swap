/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:10:08 by abisiani          #+#    #+#             */
/*   Updated: 2025/11/01 16:26:30 by abisiani         ###   ########.fr       */
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

static void	split_max(t_stacks *stacks, size_t len, size_t starting_rank)
{
	size_t			min;
	size_t			mid;

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
		}
		len--;
		// print_lists(stacks);
	}
	// ft_printf("\n");
	// print_lst_sizes(stacks);
	// ft_printf("\n");
}

static void	split_mid(t_stacks *stacks, size_t len, size_t starting_rank)
{
	size_t			i;

	i = 0;
	if (len == 0 || len == 1)
		return ;
	else if (len == 2)
	{
		if (stacks->b->rank == starting_rank)
			swap(&(stacks->b));
		push(&(stacks->b), &(stacks->a));
		push(&(stacks->b), &(stacks->a));
		// update the size of max so that you know how many nodes are already sorted
		stacks->list_sizes_mid->content = 0;
		stacks->list_sizes_max->content += 2;
		return ;
	}
	// push to a and split_a()
	while (i++ < len)
		push(&(stacks->b), &(stacks->a));
	split_a(stacks, len, starting_rank);
}

static void	split_min(t_stacks *stacks, size_t len, size_t starting_rank)
{
	size_t			i;

	i = 0;
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
		// update the size of max so that you know how many nodes are already sorted
		stacks->list_sizes_min->content = 0;
		stacks->list_sizes_max->content += 2;
		return ;
	}
	while (i++ < len)
		push(&(stacks->b), &(stacks->a));
	split_a(stacks, len, starting_rank);
}

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

void	merge(t_stacks *stacks)
{
	if (stacks->list_sizes_mid && stacks->list_sizes_mid->content == 1)
	{
		push (&(stacks->b), &(stacks->a));
		rrotate(&(stacks->b));
		push (&(stacks->b), &(stacks->a));
		ft_lstpop(&(stacks->list_sizes_min));
		ft_lstpop(&(stacks->list_sizes_mid));
		ft_lstpop(&(stacks->list_sizes_max));
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



void	split(t_stacks *stacks, size_t len)
{
	size_t	starting_rank;

	starting_rank = stacks->a->rank + 1;
	//		split_mid (creating new lengths for min, mid, max)
	//			send mid to a and split_a() (creating new min, mid, max) 
	//		while (max is > 2)
	//			recursively split the new top of a (creating new lengths for min, mid, max)
	//			rrotate it back up 
	//			leaving sorted singleton or pair at the top
	if (stacks->list_sizes_mid > 1)
	{
		stacks->list_sizes_mid = 0;
		split_mid(stacks, len, starting_rank);
		while (stacks->list_sizes_max > 2)
			split_max(stacks, stacks->list_sizes_max, starting_rank);
		// this cannot be the next operation
		while (stacks->list_sizes_mid->content > 0)
			split(stacks, stacks->list_sizes_mid->content);
		
	}
	// ft_printf("\nSplit a\n");
	// split_a(stacks, sublist_size, stacks->a->rank - 1);
	// print_lists(stacks);
	// print_lst_sizes(stacks);

	// ft_printf("\nrrotate a\n");
	// sublist_size = stacks->list_sizes_max->content;
	// while (stacks->list_sizes_max->content--)
	// 	rrotate(&(stacks->a));
	// print_lists(stacks);
	// print_lst_sizes(stacks);

	// ft_printf("\nSplit a\n");
	// split_a(stacks, sublist_size, stacks->a->rank - 1);
	// print_lists(stacks);
	// print_lst_sizes(stacks);
}

void	msort(t_stacks *stacks, size_t len)
{
	ft_printf("\nsize a: %i\n", ft_lstsize(stacks->a, 0, stacks->a));
	ft_printf("\nInit split\n");
	init_split(stacks, len, 0);
	print_lists(stacks);
	print_lst_sizes(stacks);

	while (stacks->list_sizes_mid->content == 1)
	{
		ft_printf("\nMerge\n");
		merge(stacks);
		print_lists(stacks);
		ft_printf("\nreached\n");
		print_lst_sizes(stacks);
	}
	while (!is_sorted(stacks->a) && stacks->b->next)
		split(stacks, len);
}



	// ft_printf("push sublist\n");
	// sublist_size = push_sublist(stacks);
	// print_lists(stacks);
	// print_lst_sizes(stacks);


// if there is a mid list, push it
// if there isn't, if there is a min list, rrotate and push that
// static int	push_sublist(t_stacks *stacks)
// {
// 	int	size;

// 	size = 0;
// 	if (stacks->list_sizes_mid->content)
// 	{
// 		size = stacks->list_sizes_mid->content;
// 		while (stacks->list_sizes_mid->content)
// 		{
// 			push (&(stacks->b), &(stacks->a));
// 			stacks->list_sizes_mid->content--;
// 		}
// 	}
// 	else if (stacks->list_sizes_min->content)
// 	{
// 		size = stacks->list_sizes_min->content;
// 		while (stacks->list_sizes_min->content)
// 		{
// 			rrotate(&(stacks->b));
// 			push (&(stacks->b), &(stacks->a));
// 			stacks->list_sizes_min->content--;
// 		}
// 	}
// 	return (size);
// }