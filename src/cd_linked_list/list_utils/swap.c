/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:15:02 by abisiani          #+#    #+#             */
/*   Updated: 2025/10/09 16:31:39 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../push_swap.h"

int	swap(t_list_node **lst)
{
	t_list_node	*second;
	t_list_node	*third;
	t_list_node	*last;

	if (!lst || !*lst || (*lst)->next == *lst)
		return (-1);
	second = (*lst)->next;
	third = (*lst)->next->next;
	if(third == *lst)
	{
		*lst = second;
		return (0);
	}
	last = (*lst)->prev;
	(*lst)->next = third;
	(*lst)->prev = second;
	second->next = *lst;
	second->prev = last;
	third->prev = *lst;
	last->next = second;
	*lst = second;
	return (0);
}

	// c = b->next;
	// (*lst)->next = c;
	// b->next = *lst;
	// *lst = b;