/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:19:25 by abisiani          #+#    #+#             */
/*   Updated: 2025/11/19 20:45:30 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclear(t_list_node **current, t_list_node *head)
{
	t_list_node	*next;

	if (!current || !*current || !head)
		return ;
	next = (*current)->next;
	if ((*current)->costs)
		free((*current)->costs);
	free(*current);
	*current = NULL;
	if (next == head)
		return ;
	ft_lstclear(&next, head);
}
