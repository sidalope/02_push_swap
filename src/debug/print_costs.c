/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_costs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 22:04:57 by abisani           #+#    #+#             */
/*   Updated: 2025/12/13 12:51:23 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_costs(t_stacks *stacks)
{
	t_list_node	*start;
	t_list_node	*c;

	start = stacks->b->prev;
	c = stacks->b;
	ft_printf("COSTS:\n");
	while (c != start)
	{
		ft_printf("rot: %i, rrot: %i, rot b: %i \n", c->costs->rot,
			c->costs->rrot, c->costs->rot_b);
		c = c->next;
	}
	ft_printf("rot: %i, rrot: %i, rot b: %i \n", c->costs->rot,
		c->costs->rrot, c->costs->rot_b);
}
