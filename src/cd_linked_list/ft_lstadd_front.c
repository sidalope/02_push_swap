/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:33:07 by abisiani          #+#    #+#             */
/*   Updated: 2025/10/09 12:45:37 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../push_swap.h"

void	ft_lstadd_front(t_list_node **lst, t_list_node *new)
{
	t_list_node *last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		new->next = new;
		new->prev = new;
		*lst = new;
		return ;
	}
	last = (*lst)->prev;
	(*lst)->prev = new;
	last->next = new;
	new->next = *lst;
	new->prev = last;
	*lst = new;
}
