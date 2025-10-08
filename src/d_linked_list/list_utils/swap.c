/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:15:02 by abisiani          #+#    #+#             */
/*   Updated: 2025/10/08 16:09:09 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../push_swap.h"

int	swap(t_list **src)
{
	t_list	*b;
	t_list	*c;

	if (!src || !*src || !(*src)->next)
		return (-1);
	b = (*src)->next;
	c = b->next;
	(*src)->next = c;
	b->next = *src;
	*src = b;
	return (0);
}