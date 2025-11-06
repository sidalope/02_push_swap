/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:36:08 by abisani           #+#    #+#             */
/*   Updated: 2025/11/06 21:56:21 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//also init and tear down log
void	log_op(t_list_node **log, char *operation)
{
	ft_lstadd_front(log, ft_lstnew(operation));
}
