/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chunks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:37:26 by abisani           #+#    #+#             */
/*   Updated: 2025/11/17 21:51:47 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	print_chunks(t_list_node *curr, t_stacks *stacks)
{
	if (!curr)
		return (ps_error());
	ft_printf("%i\n", curr->chunk);
	if (curr->next == stacks->a)
		return ;
	return (print_chunks(curr->next, stacks));
}
