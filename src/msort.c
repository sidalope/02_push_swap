/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:10:08 by abisiani          #+#    #+#             */
/*   Updated: 2025/10/21 23:35:20 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// split() could also check whether the first part of the list is ordered

static void	print_lists(t_stacks *stacks)
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
		if (stacks->a->rank == starting_rank)
			return ;
		else
		{
			swap(&(stacks->a));
			return ;
		}
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

static void	init_split(t_stacks *stacks, size_t len, size_t starting_rank)
{
	if (len > 1)
	{
		split_a(stacks, len, starting_rank);
		starting_rank = starting_rank + (len / 3) * 2;
		len = ft_lstsize(stacks->a, 0, stacks->a);
		init_split(stacks, len, starting_rank);
	}
}

void	merge(t_stacks *stacks)
{
	if (stacks->list_sizes_mid->content == 1)
	{
		push (&(stacks->b), &(stacks->a));
		rrotate(&(stacks->b));
		push (&(stacks->b), &(stacks->a));
		ft_lstpop(&(stacks->list_sizes_min));
		ft_lstpop(&(stacks->list_sizes_mid));
		ft_lstpop(&(stacks->list_sizes_max));
	}
}

// if there is a mid list, push it
// if there isn't, if there is a min list, rrotate and push that
static int	push_sublist(t_stacks *stacks)
{
	int	size;

	size = 0;
	if (stacks->list_sizes_mid->content)
	{
		size = stacks->list_sizes_mid->content;
		while (stacks->list_sizes_mid->content)
		{
			push (&(stacks->b), &(stacks->a));
			stacks->list_sizes_mid->content--;
		}
	}
	else if (stacks->list_sizes_min->content)
	{
		size = stacks->list_sizes_min->content;
		while (stacks->list_sizes_min->content)
		{
			rrotate(&(stacks->b));
			push (&(stacks->b), &(stacks->a));
			stacks->list_sizes_min->content--;
		}
	}
	return (size);
}

// Check whether b is empty and a is sorted
	// if not, split a
	// then merge
	// 	Split a. If length of mid is 1 merge it, if
	//  length of min is 1 merge it. If either is not 1,
	//  split it then go back to merging until there is
	//  no length of mid or min.
	//  At every loop check whether b is empty and a is
	//  sorted.
void	msort(t_stacks *stacks, size_t len)
{
	int	sublist_size;

	sublist_size = 0;
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
		print_lst_sizes(stacks);
	}

	ft_printf("push sublist\n");
	sublist_size = push_sublist(stacks);
	print_lists(stacks);
	print_lst_sizes(stacks);

	ft_printf("\nSplit a\n");
	split_a(stacks, sublist_size, stacks->a->rank - 1);
	print_lists(stacks);
	print_lst_sizes(stacks);

	ft_printf("\nrrotate a\n");
	sublist_size = stacks->list_sizes_max->content;
	while (stacks->list_sizes_max->content--)
		rrotate(&(stacks->a));
	print_lists(stacks);
	print_lst_sizes(stacks);

	ft_printf("\nSplit a\n");
	split_a(stacks, sublist_size, stacks->a->rank - 1);
	print_lists(stacks);
	print_lst_sizes(stacks);
}
