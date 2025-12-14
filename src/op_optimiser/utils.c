/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:59:54 by abisani           #+#    #+#             */
/*   Updated: 2025/12/14 13:34:39 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Deletes two consecutive nodes from lst */
int	delete_nodes(t_list_node **lst)
{
	t_list_node	*next;

	if (!lst || !*lst || ft_lstsize(*lst, 0, *lst) < 2)
		return (0);
	next = (*lst)->next;
	ft_lstpop(&next);
	ft_lstpop(lst);
	return (1);
}

/* 
** Takes a new node and replaces two consecutive nodes in lst.
** Returns 1 if something was replaced.
*/
int	replace_nodes(t_list_node **lst, t_list_node *new)
{
	t_list_node	*current;
	t_list_node	*next;

	if (!lst || !*lst || !new || ft_lstsize(*lst, 0, *lst) < 2)
		return (0);
	current = *lst;
	next = (*lst)->next;
	ft_lstadd_front(lst, new);
	ft_lstpop(&(next));
	ft_lstpop(&(current));
	return (1);
}

/* Rotates the log without adding operations to log (as in rotate()) */
int	rotate_log(t_list_node **lst)
{
	if (!lst || !*lst)
		return (-1);
	*lst = (*lst)->next;
	return (0);
}

/* Rrotates the log without adding operations to log (as in rrotate()) */
int	rrotate_log(t_list_node **lst)
{
	if (!lst || !*lst)
		return (-1);
	*lst = (*lst)->prev;
	return (0);
}
