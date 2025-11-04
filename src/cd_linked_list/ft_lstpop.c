/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:12:47 by abisiani          #+#    #+#             */
/*   Updated: 2025/11/01 14:25:01 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../push_swap.h"

void	ft_lstpop(t_list_node **lst)
{
	t_list_node	*next;
	t_list_node	*prev;

	if (!lst || !*lst)
		return ;
	next = NULL;
	prev = NULL;
	if ((*lst)->next == *lst)
	{
		free(*lst);
		*lst = NULL;
		return ;
	}
	next = (*lst)->next;
	prev = (*lst)->prev;
	prev->next = next;
	next->prev = prev;
	free(*lst);
	*lst = next;
}


	// next = (*lst)->next;
	// prev = (*lst)->prev;
	// free(*lst);
	// *lst = next;
	// prev->next = *lst;
	// (*lst)->prev = prev;