/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:53:10 by abisiani          #+#    #+#             */
/*   Updated: 2025/11/06 20:55:06 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstiter(t_list_node *current, t_list_node *head, void (*f)(void*))
{
	if (!current || !head || !f)
		return ;
	f(current->content);
	if (current->next == head)
		return ;
	ft_lstiter(current->next, head, f);
}
