/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:52:41 by abisani           #+#    #+#             */
/*   Updated: 2025/10/17 12:50:56 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ranks(t_list_node *lst)
{
	t_list_node	*last;

	last = lst->prev;
	ft_printf("\n");
	while (lst != last)
	{
		ft_printf("elem %i: %i\n", lst->content, lst->rank);
		lst = lst->next;
	}
	ft_printf("elem %i: %i\n", lst->content, lst->rank);
}

static int	verify_node(t_list_node *node, t_list_node *head)
{
	if (!node || !head)
		return (ps_error(), 0);
	if (head->content < node->content)
		node->rank++;
	if (node != head && head->content == node->content)
		return (ps_error(), 0);
	if (node->next == head)
		return (1);
	verify_node(node->next, head);
	return (1);
}

int	check_and_rank(t_list_node *lst, t_list_node *head)
{
	if (!lst || !head)
		return (0);
	if (!verify_node(lst, lst))
		return (0);
	if (lst->next == head)
		return (1);
	check_and_rank(lst->next, head);
	return (1);
}
