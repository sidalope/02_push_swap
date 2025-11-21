/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:43:42 by abisiani          #+#    #+#             */
/*   Updated: 2025/11/21 22:06:00 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_lst_content(t_list_node *current, t_list_node *head)
{
	if (!current || !head)
		return ;
	ft_printf("%s ", (char *)current->content);
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

void	print_lists(t_stacks *stacks)
{
	ft_printf("\nValues\n");
	ft_printf("a: ");
	print_lst_content(stacks->a, stacks->a);
	ft_printf("b: ");
	print_lst_content(stacks->b, stacks->b);
}

void	print_ranks(t_stacks *stacks)
{
	ft_printf("\nRanks\n");
	ft_printf("a: ");
	print_lst_ranks(stacks->a, stacks->a);
	ft_printf("b: ");
	print_lst_ranks(stacks->b, stacks->b);
}
