/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:10:08 by abisiani          #+#    #+#             */
/*   Updated: 2025/10/03 17:25:03 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	push_swap(t_list stack)
// {

// }

// static t_list	init_stack(char *argv[])
// {

// }

int	main(int argc, char *argv[])
{
	t_list	*stack;

	if (argc == 1)
		return (0);
	argc--;
	stack = ft_lstnew(argv[argc]);
	while (argc > 0)
	{
		ft_printf("%s ", argv[argc]);
		ft_lstadd_front(&stack, ft_lstnew(argv[argc]));
		argc--;
	}
	return (0);
}
