/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:10:08 by abisiani          #+#    #+#             */
/*   Updated: 2025/10/20 22:49:41 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// split() could also check whether the first part of the list is ordered

static void	init_split(t_stacks *stacks, size_t len, size_t starting_rank)
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
	ft_printf("\nlen: %i, min: %i, mid: %i", len, min, mid);
	ft_printf("\nsplit() a:\n");
	print_lst_content(stacks->a, stacks->a);
	ft_printf("\n");
	ft_printf("\na: ");
	print_lst_content(stacks->a, stacks->a);
	ft_printf("\nb: ");
	print_lst_content(stacks->b,  stacks->b);
	ft_lstadd_front(&(stacks->list_sizes_min), ft_lstnew(0));
	ft_lstadd_front(&(stacks->list_sizes_mid), ft_lstnew(0));
	ft_lstadd_front(&(stacks->list_sizes_max), ft_lstnew(0));
	while (len)
	{
		if (stacks->a->rank < min)
		{
			stacks->list_sizes_min->content++;
			ft_printf("\n\n(%i)rank %i to min", stacks->a->content, stacks->a->rank);
			push(&(stacks->a), &(stacks->b));
			rotate(&(stacks->b));
		}
		else if (stacks->a->rank < mid)
		{
			stacks->list_sizes_mid->content++;
			ft_printf("\n\n(%i)rank %i to mid", stacks->a->content, stacks->a->rank);
			push(&(stacks->a), &(stacks->b));
		}
		else
		{
			stacks->list_sizes_max->content++;
			ft_printf("\n\n(%i)rank %i to max", stacks->a->content, stacks->a->rank);
			rotate(&(stacks->a));
		}
		len--;
		ft_printf("\na: ");
		print_lst_content(stacks->a, stacks->a);
		ft_printf("\nb: ");
		print_lst_content(stacks->b, stacks->b);
	}
	init_split(stacks, ft_lstsize(stacks->a, 0, stacks->a), mid);
}

void	msort(t_stacks *stacks, size_t len)
{
	ft_printf("\nsize a: %i\n", ft_lstsize(stacks->a, 0, stacks->a));
	init_split(stacks, len, 0);
	ft_printf("\nsize a after init split: %i\n", ft_lstsize(stacks->a, 0, stacks->a));
	ft_printf("\na: ");
		print_lst_content(stacks->a, stacks->a);
	// // print_ranks(stacks->a);
	ft_printf("\nb: ");
		print_lst_content(stacks->b, stacks->b);
	// // print_ranks(stacks->b);
	// ft_printf("\nsize a: %i\n", ft_lstsize(stacks->a, 0, stacks->a));
	// ft_printf("size b: %i\n", ft_lstsize(stacks->b, 0, stacks->b));
	ft_printf("\n");
	print_lst_sizes(stacks);
}


