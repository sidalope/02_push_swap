/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naive_optimisation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:39:36 by abisani           #+#    #+#             */
/*   Updated: 2025/11/20 08:16:50 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	combine_node_pairs(t_stacks *stacks, char *ops)
{
	t_list_node	*new_node;

	new_node = NULL;
	if (!ft_strncmp(ops, "sasb", 4) || !ft_strncmp(ops, "sbsa", 4))
	{
		new_node = ft_lstnew((void *)"ss");
		if (!new_node)
			return (ps_error(), -1);
	}
	else if (!ft_strncmp(ops, "rarb", 4) || !ft_strncmp(ops, "rbra", 4))
	{
		new_node = ft_lstnew((void *)"rr");
		if (!new_node)
			return (ps_error(), -1);
	}
	else if (!ft_strncmp(ops, "rrarrb", 6) || !ft_strncmp(ops, "rrbrra", 6))
	{
		new_node = ft_lstnew((void *)"rrr");
		if (!new_node)
			return (ps_error(), -1);
	}
	if (new_node && !replace_nodes(&(stacks->log), new_node))
		return (0);
	rotate_log(&(stacks->log));
	return (new_node != NULL);
}

static int	combine_pass(t_stacks *stacks)
{
	char	*ops;
	int		i;
	int		len;
	int		combined;

	i = 1;
	len = ft_lstsize(stacks->log, 0, stacks->log);
	if (!stacks || !stacks->log || len == 0)
		return (ps_error(), 0);
	if (len == 1)
		return (1);
	while (i++ < len)
	{
		ops = ft_strjoin(stacks->log->content, stacks->log->next->content);
		if (!ops)
			return (ps_error(), 0);
		combined = combine_node_pairs(stacks, ops);
		free (ops);
		if (combined == -1)
			return (0);
		else if (combined)
			i++;
	}
	rotate_log(&(stacks->log));
	return (1);
}

static int	del_node_pairs(t_stacks *stacks, char *ops)
{
	if (!ft_strncmp(ops, "papb", 4) || !ft_strncmp(ops, "pbpa", 4)
		|| !ft_strncmp(ops, "sasa", 4) || !ft_strncmp(ops, "sbsb", 4)
		|| !ft_strncmp(ops, "rrara", 5) || !ft_strncmp(ops, "rarra", 5)
		|| !ft_strncmp(ops, "rrbrb", 5) || !ft_strncmp(ops, "rbrrb", 5))
	{
		delete_nodes(&(stacks->log));
		return (1);
	}
	else
	{
		rotate_log(&(stacks->log));
		return (0);
	}
}

static int	delete_pass(t_stacks *stacks)
{
	char	*ops;
	int		i;
	int		len;

	ops = NULL;
	i = 1;
	len = ft_lstsize(stacks->log, 0, stacks->log);
	if (!stacks || !stacks->log || len == 0)
		return (ps_error(), 0);
	if (len == 1)
		return (1);
	while (i++ < len)
	{
		ops = ft_strjoin(stacks->log->content, stacks->log->next->content);
		if (!ops)
			return (ps_error(), 0);
		if (del_node_pairs(stacks, ops))
			i++;
		free(ops);
	}
	rotate_log(&(stacks->log));
	return (1);
}

int	naive_pass(t_stacks *stacks)
{
	if (!combine_pass(stacks) || !delete_pass(stacks))
		return (0);
	return (1);
}
