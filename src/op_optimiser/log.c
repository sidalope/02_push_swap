/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:36:08 by abisani           #+#    #+#             */
/*   Updated: 2025/11/20 01:48:01 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//also init and tear down log
int	log_op(t_list_node **log, char *operation)
{
	t_list_node	*new_node;

	new_node = ft_lstnew(operation);
	if (!new_node)
		return (ps_error(), 0);
	ft_lstadd_front(log, new_node);
	return (1);
}
