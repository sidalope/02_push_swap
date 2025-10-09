/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:52:40 by abisiani          #+#    #+#             */
/*   Updated: 2025/10/09 10:53:17 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../push_swap.h"

void	ft_lstadd_back(t_list_node **lst, t_list_node *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}
