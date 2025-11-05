/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:43:42 by abisiani          #+#    #+#             */
/*   Updated: 2025/11/05 20:57:51 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	print_lst_content(t_list_node *current, t_list_node *head)
{
	if (!current || !head)
		return ;
	ft_printf("%i ", current->content);
	if (current->next == head)
	{
		ft_printf("\n");
		return ;
	}
	print_lst_content(current->next, head);
}

void	print_lst_ranks(t_list_node *current, t_list_node *head)
{
	if (!current || !head)
		return ;
	ft_printf("%i ", current->rank);
	if (current->next == head)
	{
		ft_printf("\n");
		return ;
	}
	print_lst_ranks(current->next, head);
}

// void	print_lst_sizes(t_stacks *stacks)
// {
// 	if (!stacks->list_sizes_min || !stacks->list_sizes_mid || !stacks->list_sizes_max)
// 		return ;
// 	ft_printf("min: ");
// 	print_lst_content(stacks->list_sizes_min, stacks->list_sizes_min);
// 	ft_printf("mid: ");
// 	print_lst_content(stacks->list_sizes_mid, stacks->list_sizes_mid);
// 	ft_printf("max: ");
// 	print_lst_content(stacks->list_sizes_max, stacks->list_sizes_max);
// 	ft_printf("\n");
// }
