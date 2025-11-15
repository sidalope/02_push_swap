/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naive_optimisation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:39:36 by abisani           #+#    #+#             */
/*   Updated: 2025/11/15 08:50:19 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	combine_node_pairs(t_stacks *stacks, char *ops)
{
	if (!ft_strncmp(ops, "sasb", 4) || !ft_strncmp(ops, "sbsa", 4))
	{
		replace_nodes(&(stacks->log), ft_lstnew((void *)"ss"));
		rotate_log(&(stacks->log));
		return (1);
	}
	else if (!ft_strncmp(ops, "rarb", 4) || !ft_strncmp(ops, "rbra", 4))
	{
		replace_nodes(&(stacks->log), ft_lstnew((void *)"rr"));
		rotate_log(&(stacks->log));
		return (1);
	}
	else if (!ft_strncmp(ops, "rrarrb", 6) || !ft_strncmp(ops, "rrbrra", 6))
	{
		replace_nodes(&(stacks->log), ft_lstnew((void *)"rrr"));
		rotate_log(&(stacks->log));
		return (1);
	}
	else
		rotate_log(&(stacks->log));
	return (0);
}

static int	combine_pass(t_stacks *stacks)
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
		if (combine_node_pairs(stacks, ops))
			i++;
		free(ops);
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
		if (del_node_pairs(stacks, ops))
			i++;
		free(ops);
	}
	rotate_log(&(stacks->log));
	return (1);
}

void	naive_pass(t_stacks *stacks)
{
	combine_pass(stacks);
	delete_pass(stacks);
}
