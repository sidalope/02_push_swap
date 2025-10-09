/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:26:08 by abisiani          #+#    #+#             */
/*   Updated: 2025/10/09 11:29:56 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../push_swap.h"

t_list_node	*ft_lstnew(void *content)
{
	t_list_node	*new_node;

	new_node = (t_list_node *) malloc(sizeof(t_list_node));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->rank = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
