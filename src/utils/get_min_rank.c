/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_rank.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:45:35 by abisiani          #+#    #+#             */
/*   Updated: 2025/12/14 13:13:57 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_min_rank(t_list_node *lst)
{
	int			lst_size;
	int			min;

	lst_size = ft_lstsize(lst, 0, lst);
	min = lst->rank;
	while (lst_size--)
	{
		if (lst->rank < min)
			min = lst->rank;
		lst = lst->next;
	}
	return (min);
}
