/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:12:47 by abisiani          #+#    #+#             */
/*   Updated: 2025/11/15 05:57:33 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstpop(t_list_node **lst)
{
	t_list_node	*next;
	t_list_node	*prev;

	if (!lst || !*lst)
		return ;
	next = NULL;
	prev = NULL;
	if ((*lst)->next == *lst)
	{
		free(*lst);
		*lst = NULL;
		return ;
	}
	next = (*lst)->next;
	prev = (*lst)->prev;
	prev->next = next;
	next->prev = prev;
	free(*lst);
	*lst = next;
}
