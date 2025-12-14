/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:36:08 by abisani           #+#    #+#             */
/*   Updated: 2025/12/14 12:18:55 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Records a stack operation to the log for later optimization.
 * Returns 1 on success, 0 on allocation failure. */
int	log_op(t_list_node **log, char *operation)
{
	t_list_node	*new_node;

	new_node = ft_lstnew(operation);
	if (!new_node)
		return (0);
	ft_lstadd_front(log, new_node);
	return (1);
}
