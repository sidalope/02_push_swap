/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:16:29 by abisani           #+#    #+#             */
/*   Updated: 2025/11/17 20:39:53 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_cheapest(t_stacks *stacks, int high_chunk, int low_chunk)
{
	int			rotations;
	t_list_node	*curr;
	t_list_node	*prev;

	rotations = 0;
	curr = stacks->a;
	prev = stacks->a;
	if (curr->chunk == high_chunk || curr->chunk == low_chunk)
		return (rotations);
	while (curr->next != stacks->a)
	{
		// ft_printf("CHUNKS (calc): %i, %i\n", high_chunk, low_chunk);
		if (curr->chunk == high_chunk || curr->chunk == low_chunk)
			return (rotations);
		else if (prev->chunk == low_chunk || prev->chunk == high_chunk)
			return (-rotations);
		rotations++;
		curr = curr->next;
		prev = prev->prev;
	}
	return (ps_error(), 0);
}

// Add look-ahead to two or three ops?
static void	send_cheapest(t_stacks *stacks, int rotations)
{
	while (rotations)
	{
		// ft_printf("ROTATE\n");
		if (rotations > 0)
		{
			rotate(&(stacks->a), stacks);
			rotations--;
		}
		else
		{
			rrotate(&(stacks->a), stacks);
			rotations++;
		}
	}
	push(&(stacks->a), &(stacks->b), stacks);
}

static void	send_chunks(t_stacks *stacks, int high_chunk, int low_chunk,
						int size_a)
{
	int		chunk_size;
	int		rotations;
	int		n_pushes;

	chunk_size = size_a / stacks->n_chunks;
	rotations = 0;
	n_pushes = 0;
	while (n_pushes < chunk_size * 2)
	{
		// ft_printf("CHUNKS (send): %i, %i\n", high_chunk, low_chunk);
		rotations = calculate_cheapest(stacks, high_chunk, low_chunk);
		send_cheapest(stacks, rotations);
		n_pushes++;
	}
	print_chunks(stacks->a, stacks);
}

// Send all chunk pairs to b, leaving the last one in a
int	split_pairs(t_stacks *stacks)
{
	int		low_chunk;
	int		high_chunk;
	int		size_a;

	high_chunk = stacks->n_chunks / 2;
	low_chunk = high_chunk - 1;
	size_a = ft_lstsize(stacks->a, 0, stacks->a);
	if (!stacks || !stacks->n_chunks)
		return (ps_error(), 0);
	while (low_chunk >= 0)
	{
		ft_printf("CHUNKS: %i, %i\n", high_chunk, low_chunk);
		print_chunks(stacks->a, stacks);
		ft_printf("-\n");
		send_chunks(stacks, high_chunk, low_chunk, size_a);
		high_chunk++;
		low_chunk--;
	}
	return (1);
}
