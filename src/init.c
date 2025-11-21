/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:52:41 by abisani           #+#    #+#             */
/*   Updated: 2025/11/21 22:12:17 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_num_chunks(t_stacks *stacks)
{
	int	n_chunks;
	int	size_a;

	n_chunks = 0;
	if (!stacks)
		return (0);
	size_a = ft_lstsize(stacks->a, 0, stacks->a);
	if (size_a <= 4)
		n_chunks = 1;
	else if (size_a <= 20)
		n_chunks = 2;
	else if (size_a <= 50)
		n_chunks = 3;
	else if (size_a <= 100)
		n_chunks = 7;
	else if (size_a <= 300)
		n_chunks = 9;
	else
		n_chunks = 11;
	if (n_chunks % 2 == 0)
		n_chunks++;
	return (stacks->n_chunks = n_chunks);
}

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

// traverse a and assign chunk
static int	assign_chunk(t_list_node *curr, t_list_node *head, int n_chunks,
							int size_a)
{
	int		i;

	i = n_chunks;
	if (!head || !n_chunks)
		return (ps_error(), 0);
	while (i > 0)
	{
		if (curr->rank >= (size_a / n_chunks) * (i - 1))
		{
			curr->chunk = i - 1;
			break ;
		}
		i--;
	}
	if (curr->next == head)
		return (1);
	return (assign_chunk(curr->next, head, n_chunks, size_a));
}

int	init(int argc, char *argv[], t_stacks *stacks)
{
	int			i;
	t_list_node	*new_node;

	i = argc;
	new_node = NULL;
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->log = NULL;
	stacks->n_chunks = 0;
	while (argc > 0)
	{
		new_node = ft_lstnew(argv[argc]);
		if (!ft_isnumber(argv[argc]) || !new_node)
			return (ps_error(), 0);
		ft_lstadd_front(&stacks->a, new_node);
		argc--;
	}
	if (!init_num_chunks(stacks)
		|| !check_and_rank(stacks->a, stacks->a)
		|| !assign_chunk(stacks->a, stacks->a, stacks->n_chunks, i))
		return (0);
	return (1);
}
