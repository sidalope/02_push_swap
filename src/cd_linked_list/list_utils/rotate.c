/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:14:56 by abisiani          #+#    #+#             */
/*   Updated: 2025/10/09 16:33:52 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#include "../../push_swap.h"

int	rotate(t_list_node **lst)
{
	if (!lst || !*lst)
		return (-1);
	*lst = (*lst)->next;
	return (0);
}

int	rrotate(t_list_node **lst)
{
	if (!lst || !*lst)
		return (-1);
	*lst = (*lst)->prev;
	return (0);
}