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

void	radix_sort(t_stacks *stacks)
{
	int		i;
	int		max_num_bits;
	int		max_rank;
	int		size_a;

	i = 0;
	max_num_bits = 0;
	max_rank = ft_lstsize(stacks->a, 0, stacks->a) - 1;
	size_a = ft_lstsize(stacks->a, 0, stacks->a);
	while (max_rank >> max_num_bits != 0)
		max_num_bits++;
	while (i < max_num_bits)
	{
		size_a = ft_lstsize(stacks->a, 0, stacks->a);
		while (size_a--)
		{
			if ((stacks->a->rank >> i) & 1)
				rotate(&(stacks->a), stacks->a);
			else
				push(&(stacks->a), &(stacks->b), stacks->a);
		}
		while (stacks->b)
			push(&(stacks->b), &(stacks->a), stacks->a);
		i++;
	}
}
