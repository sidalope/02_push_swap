/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naive_optimisation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:39:36 by abisani           #+#    #+#             */
/*   Updated: 2025/11/13 21:46:57 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	combine_node_pairs(t_stacks *stacks, char *ops)
{
	if (!ft_strncmp(ops, "sasb", 4) || !ft_strncmp(ops, "sbsa", 4))
		replace_nodes(&(stacks->log), ft_lstnew((void *)"ss"));
	else if (!ft_strncmp(ops, "rarb", 4) || !ft_strncmp(ops, "rbra", 4))
		replace_nodes(&(stacks->log), ft_lstnew((void *)"rr"));
	else if (!ft_strncmp(ops, "rrarrb", 6) || !ft_strncmp(ops, "rrbrra", 6))
		replace_nodes(&(stacks->log), ft_lstnew((void *)"rrr"));
	else
		rotate_log(&(stacks->log));
}

static void	del_node_pairs(t_stacks *stacks, char *ops)
{
	if (!ft_strncmp(ops, "papb", 4) || !ft_strncmp(ops, "pbpa", 4)
		|| !ft_strncmp(ops, "sasa", 4) || !ft_strncmp(ops, "sbsb", 4)
		|| !ft_strncmp(ops, "rrara", 5) || !ft_strncmp(ops, "rarra", 5)
		|| !ft_strncmp(ops, "rrbrb", 5) || !ft_strncmp(ops, "rbrrb", 5))
		delete_nodes(&(stacks->log));
	else
		rotate_log(&(stacks->log));
}


static void	combine_pass(t_stacks *stacks)
{
	char		*ops;
	int			len;

	ops = NULL;
	len = ft_lstsize(stacks->log, 0, stacks->log);
	if (!stacks || !stacks->log)
		return ;
	while (len--)
	{
		ops = ft_strjoin(stacks->log->content, stacks->log->next->content);
		combine_node_pairs(stacks, ops);
		free(ops);
	}
}

static void	delete_pass(t_stacks *stacks)
{
	char		*ops;
	int			len;

	ops = NULL;
	len = ft_lstsize(stacks->log, 0, stacks->log);
	if (!stacks || !stacks->log)
		return ;
	while (len--)
	{
		ops = ft_strjoin(stacks->log->content, stacks->log->next->content);
		del_node_pairs(stacks, ops);
		free(ops);
	}
}

void	naive_pass(t_stacks *stacks)
{
	combine_pass(stacks);
	delete_pass(stacks);
}
