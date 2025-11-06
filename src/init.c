/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:52:41 by abisani           #+#    #+#             */
/*   Updated: 2025/11/06 22:03:32 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	verify_node(t_list_node *node, t_list_node *head)
{
	long	head_val;
	long	node_val;

	head_val = ft_atoi(head->content);
	node_val = ft_atoi(node->content);
	if (!node || !head)
		return (ps_error(), 0);
	if (node != head && head_val == node_val)
		return (ps_error(), 0);
	if (head_val < node_val)
		node->rank++;
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

int	init(int argc, char *argv[], t_stacks *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->log = NULL;
	while (argc > 0)
	{
		if (!ft_isnumber(argv[argc]))
			return (ps_error(), 0);
		ft_lstadd_front(&stacks->a, ft_lstnew(argv[argc]));
		argc--;
	}
	if (!check_and_rank(stacks->a, stacks->a))
		return (0);
	return (1);
}

	// stacks->sort_sizes_a = NULL;
	// stacks->sort_sizes_b = NULL;
	// ft_lstadd_front(&(stacks->sort_sizes_a), ft_lstnew(0));
	// ft_lstadd_front(&(stacks->sort_sizes_b), ft_lstnew(0));

	// stacks->list_sizes_min = NULL;
	// stacks->list_sizes_mid = NULL;
	// stacks->list_sizes_max = NULL;
	// ft_lstadd_front(&(stacks->list_sizes_min), ft_lstnew(0));
	// ft_lstadd_front(&(stacks->list_sizes_mid), ft_lstnew(0));
	// ft_lstadd_front(&(stacks->list_sizes_max), ft_lstnew(0));