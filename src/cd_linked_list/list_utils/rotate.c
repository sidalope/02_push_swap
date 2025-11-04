/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:14:56 by abisiani          #+#    #+#             */
/*   Updated: 2025/11/04 11:16:37 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../push_swap.h"

int	rotate(t_list_node **lst, t_list_node *list_a)
{
	if (!lst || !*lst)
		return (-1);
	if (*lst == list_a)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
	*lst = (*lst)->next;
	return (0);
}

int	rrotate(t_list_node **lst, t_list_node *list_a)
{
	if (!lst || !*lst)
		return (-1);
	if (*lst == list_a)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
	*lst = (*lst)->prev;
	return (0);
}
