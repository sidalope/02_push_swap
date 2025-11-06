/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:43:42 by abisiani          #+#    #+#             */
/*   Updated: 2025/11/06 12:18:13 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

void	print_lists(t_stacks *stacks)
{
	ft_printf("Values\n");
	ft_printf("a: ");
	print_lst_content(stacks->a, stacks->a);
	ft_printf("b: ");
	print_lst_content(stacks->b, stacks->b);
}

void	print_ranks(t_stacks *stacks)
{
	ft_printf("Ranks\n");
	ft_printf("a: ");
	print_lst_ranks(stacks->a, stacks->a);
	ft_printf("b: ");
	print_lst_ranks(stacks->b, stacks->b);
}


// void	print_ranks(t_list_node *lst)
// {
// 	t_list_node	*last;

// 	if (!lst)
// 		return ;
// 	last = lst->prev;
// 	ft_printf("\n");
// 	while (lst != last)
// 	{
// 		ft_printf("elem %i: %i\n", (int) lst->content, lst->rank);
// 		lst = lst->next;
// 	}
// 	ft_printf("elem %i: %i\n", (int) lst->content, lst->rank);
// }

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
