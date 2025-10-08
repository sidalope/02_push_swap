/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdll_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:13:35 by abisani           #+#    #+#             */
/*   Updated: 2025/10/06 14:44:06 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_clst_insert(t_list **lst, t_list *new)
{
	t_list	*head;

	if (!*lst)
		*lst = new;
	head = (*lst)->next;
	(*lst)->next = new;
	new->next = head;
}
