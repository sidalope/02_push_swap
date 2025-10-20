/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:42:46 by abisiani          #+#    #+#             */
/*   Updated: 2025/10/20 22:01:14 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_list_node *lst, size_t init_size, t_list_node *head)
{
	if (!lst)
		return (0);
	if (lst->next == head)
		return (++init_size);
	init_size = ft_lstsize(lst->next, ++init_size, head);
	return (init_size);
}
