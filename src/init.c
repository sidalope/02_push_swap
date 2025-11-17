/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:52:41 by abisani           #+#    #+#             */
/*   Updated: 2025/11/17 18:51:47 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO: Bucket size should not be < 5 or 3 (base case)??
int	init_num_chunks(t_stacks *stacks, int op_bucket_size)
{
	int	n_chunks;
	int	size_a;

	n_chunks = 0;
	if (!stacks)
		return (0);
	else
		size_a = ft_lstsize(stacks->a, 0, stacks->a);
	if (op_bucket_size)
		return (stacks->n_chunks = size_a / op_bucket_size);
	else
		n_chunks = size_a / 10;
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
	int		i;

	i = argc;
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->log = NULL;
	stacks->n_chunks = 0;
	while (argc > 0)
	{
		if (!ft_isnumber(argv[argc]))
			return (ps_error(), 0);
		ft_lstadd_front(&stacks->a, ft_lstnew(argv[argc]));
		argc--;
	}
	if (!init_num_chunks(stacks, 0)
		|| !check_and_rank(stacks->a, stacks->a)
		|| !assign_chunk(stacks->a, stacks->a, stacks->n_chunks, i))
		return (0);
	return (1);
}
