/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:33:51 by abisiani          #+#    #+#             */
/*   Updated: 2025/12/14 13:21:05 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Totate the least number of times for A to have its min rank on top */
void	position_a(t_stacks *stacks)
{
	int		size_a;
	int		min_rank;

	size_a = ft_lstsize(stacks->a, 0, stacks->a);
	min_rank = get_min_rank(stacks->a);
	if (stacks->a->rank == 0)
		return ;
	if (stacks->a->rank < size_a / 2)
	{
		while (stacks->a->rank != min_rank)
			rrotate(&(stacks->a), stacks);
	}
	else
		while (stacks->a->rank != min_rank)
			rotate(&(stacks->a), stacks);
}
