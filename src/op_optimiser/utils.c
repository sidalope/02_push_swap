/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:59:54 by abisani           #+#    #+#             */
/*   Updated: 2025/11/15 08:00:40 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	delete_nodes(t_list_node **lst)
{
	t_list_node	*next;

	if (!lst || !*lst || ft_lstsize(*lst, 0, *lst) < 2)
		return (ps_error(), 0);
	next = (*lst)->next;
	ft_lstpop(&next);
	ft_lstpop(lst);
	return (1);
}

int	replace_nodes(t_list_node **lst, t_list_node *new)
{
	t_list_node	*current;
	t_list_node	*next;

	if (!lst || !*lst || !new || ft_lstsize(*lst, 0, *lst) < 2)
		return (ps_error(), 0);
	current = *lst;
	next = (*lst)->next;
	ft_lstadd_front(lst, new);
	ft_lstpop(&(next));
	ft_lstpop(&(current));
	return (1);
}

int	rotate_log(t_list_node **lst)
{
	if (!lst || !*lst)
		return (-1);
	*lst = (*lst)->next;
	return (0);
}

int	rrotate_log(t_list_node **lst)
{
	if (!lst || !*lst)
		return (-1);
	*lst = (*lst)->prev;
	return (0);
}
