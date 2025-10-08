/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:09:34 by abisiani          #+#    #+#             */
/*   Updated: 2025/10/08 15:11:04 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../push_swap.h"

int	push(t_list **src, t_list **dest)
{
	t_list	*next;

	if (!src || !*src)
		return (-1);
	next = (*src)->next;
	ft_lstadd_front(dest, (*src));
	*src = next;
	return (0);
}