/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:33:07 by abisiani          #+#    #+#             */
/*   Updated: 2025/10/08 16:44:38 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*prev;

	if (!lst || !*lst)
		return ;
	prev = (*lst)->prev;
	(*lst)->prev = new;
	new->next = *lst;
	new->prev = prev;
	*lst = new;
}
