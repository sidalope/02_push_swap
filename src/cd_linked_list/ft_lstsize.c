/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:42:46 by abisiani          #+#    #+#             */
/*   Updated: 2025/10/09 10:53:04 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../push_swap.h"

int	ft_lstsize(t_list_node *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 1;
	while (lst->next)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
