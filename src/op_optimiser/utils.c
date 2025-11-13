/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:59:54 by abisani           #+#    #+#             */
/*   Updated: 2025/11/13 21:09:43 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	delete_nodes(t_list_node **lst)
{
	t_list_node	*new;
	t_list_node	*next;

	new = (*lst)->next->next;
	next = (*lst)->next;
	// if (ft_lstsize(*lst, 0, *lst) == 2)
	// 	new = NULL;
	ft_lstpop(&(next));
	ft_lstpop(lst);
	*lst = new;
}

void	replace_nodes(t_list_node **lst, t_list_node *new)
{
	t_list_node	*current;
	t_list_node	*next;

	if (!lst || !*lst || !new)
		return ;
	current = *lst;
	next = (*lst)->next;
	*lst = next->next;
	ft_lstpop(&(next));
	ft_lstpop(&(current));
	ft_lstadd_front(lst, new);
}

int	rotate_log(t_list_node **lst)
{
	if (!lst || !*lst)
		return (-1);
	*lst = (*lst)->next;
	return (0);
}
