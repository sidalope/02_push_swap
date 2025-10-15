/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:53:10 by abisiani          #+#    #+#             */
/*   Updated: 2025/10/15 19:45:23 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstiter(t_list_node *current, t_list_node *head, void (*f)(int))
{
	if (!current || !head || !f)
		return ;
	f(current->content);
	if (current->next == head)
		return ;
	ft_lstiter(current->next, head, f);
}

// void	ft_lstiter(t_list_node *lst, t_list_node *head, void (*f)(int))
// {
// 	t_list_node	*last;

// 	if (!lst || !f)
// 		return ;
// 	last = lst->prev;
// 	while (lst != last)
// 	{
// 		f(lst->content);
// 		lst = lst->next;
// 	}
// 	f(lst->content);
// }