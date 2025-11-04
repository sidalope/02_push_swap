/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:09:34 by abisiani          #+#    #+#             */
/*   Updated: 2025/11/04 11:16:16 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// static void	print_push()

int	push(t_list_node **src, t_list_node **dest, t_list_node *list_a)
{
	t_list_node	*second;
	t_list_node	*last;

	if (!src || !*src)
		return (-1);
	if (*src == list_a)
		ft_printf("pb\n");
	else
		ft_printf("pa\n");
	if ((*src)->next == *src)
	{
		ft_lstadd_front(dest, *src);
		*src = NULL;
		return (0);
	}
	second = (*src)->next;
	last = (*src)->prev;
	ft_lstadd_front(dest, *src);
	second->prev = last;
	last->next = second;
	*src = second;
	return (0);
}
