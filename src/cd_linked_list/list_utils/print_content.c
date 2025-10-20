/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:43:42 by abisiani          #+#    #+#             */
/*   Updated: 2025/10/20 22:48:48 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	print_lst_content(t_list_node *current, t_list_node *head)
{
	if (!current || !head)
		return ;
	ft_printf("%i ", current->content);
	if (current->next == head)
		return ;
	print_lst_content(current->next, head);
}

void	print_lst_ranks(t_list_node *current, t_list_node *head)
{
	if (!current || !head)
		return ;
	ft_printf("%i ", current->rank);
	if (current->next == head)
		return ;
	print_lst_ranks(current->next, head);
}

void	print_lst_sizes(t_stacks *stacks)
{
	printf("\nmin: ");
	print_lst_content(stacks->list_sizes_min, stacks->list_sizes_min);
	printf("\nmid: ");
	print_lst_content(stacks->list_sizes_mid, stacks->list_sizes_mid);
	printf("\nmax: ");
	print_lst_content(stacks->list_sizes_max, stacks->list_sizes_max);
	printf("\n");
}
