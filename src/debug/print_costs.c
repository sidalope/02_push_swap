/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_costs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 22:04:57 by abisani           #+#    #+#             */
/*   Updated: 2025/12/12 17:32:48 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../push_swap.h"

void	print_costs(t_stacks *stacks)
{
	t_list_node	*start;
	t_list_node	*c;

	start = stacks->b;
	c = stacks->b;
	ft_printf("COSTS:\n");
	do {
		ft_printf("rot: %i, rrot: %i, rot b: %i \n",
				c->costs->rot, c->costs->rrot, c->costs->rot_b);
		c = c->next;
	} while (c != start);
}

