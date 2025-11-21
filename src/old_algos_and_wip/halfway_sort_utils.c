/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   halfway_sort_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:44:31 by abisiani          #+#    #+#             */
/*   Updated: 2025/11/06 20:58:13 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_bottom_ranks(t_stacks *stacks)
{
	int	length_a;
	int	length_b;
	int	median;

	length_a = ft_lstsize(stacks->a, 0, stacks->a);
	length_b = 0;
	median = length_a / 2;
	while (length_a-- && length_b < median + 1)
	{
		if (stacks->a->rank >= median)
		{
			push(&(stacks->a), &(stacks->b), stacks);
			length_b++;
		}
		else
			rotate(&(stacks->a), stacks);
	}
}

void	send_top_ranks(t_stacks *stacks)
{
	int	length_a;
	int	length_b;
	int	median;

	length_a = ft_lstsize(stacks->a, 0, stacks->a);
	length_b = 0;
	median = length_a / 2;
	while (length_a-- && length_b < median)
	{
		if (stacks->a->rank < median)
		{
			push(&(stacks->a), &(stacks->b), stacks);
			length_b++;
		}
		else
			rotate(&(stacks->a), stacks);
	}
}

int	get_node_dist(t_list_node *current, int rank)
{
	int				rotations;
	int				rev_rotations;
	t_list_node		*head;

	rotations = 0;
	rev_rotations = 0;
	head = current;
	if (!current)
		return (ps_error(), 0);
	if (current->rank == rank)
		return (0);
	while (current->rank != rank)
	{
		current = current->next;
		rotations++;
	}
	current = head;
	while (current->rank != rank)
	{
		current = current->prev;
		rev_rotations++;
	}
	if (rotations < rev_rotations)
		return (rotations);
	return (-rev_rotations);
}
