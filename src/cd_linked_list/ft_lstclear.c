/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:19:25 by abisiani          #+#    #+#             */
/*   Updated: 2025/10/20 13:34:03 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclear(t_list_node **current, t_list_node *head)
{
	t_list_node	*next;

	if (!current || !*current || !head)
		return ;
	next = (*current)->next;
	free(*current);
	if (next == head)
		return ;
	ft_lstclear(&next, head);
}
