/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:58:15 by abisiani          #+#    #+#             */
/*   Updated: 2025/10/09 11:25:46 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../push_swap.h"

t_list_node	*ft_lstmap(t_list_node *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list_node	*new_llist;
	t_list_node	*new_node;
	void	*content;

	new_llist = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			if (new_llist)
				ft_lstclear(&new_llist, del);
			return (NULL);
		}
		if (new_llist)
			ft_lstadd_back(&new_llist, new_node);
		else
			new_llist = new_node;
		lst = lst->next;
	}
	return (new_llist);
}
