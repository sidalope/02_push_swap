/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:53:10 by abisiani          #+#    #+#             */
/*   Updated: 2025/10/09 14:10:04 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../push_swap.h"

void	ft_lstiter(t_list_node *lst, void (*f)(void *))
{
	size_t	i;
	t_list_node *last;

	i = 0;
	if (!lst || !f)
		return ;
	last = lst->prev;
	while (lst != last)
	{
		f(lst->content);
		lst = lst->next;
	}
	f(lst->content);
}
