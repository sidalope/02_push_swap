/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:10:08 by abisiani          #+#    #+#             */
/*   Updated: 2025/10/08 16:13:23 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	push_swap(t_list *stack_a)
{
	t_list	*stack_b;
	// t_list	*tmp;
	stack_b = NULL;
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	swap(&stack_b);
	ft_printf("\n");
	while (stack_a && stack_a->content)
	{
		ft_printf("a: %s\n", stack_a->content);
		stack_a = stack_a->next;
	}
	ft_printf("\n");
	while (stack_b && stack_b->content)
	{
		ft_printf("b: %s\n", stack_b->content);
		stack_b = stack_b->next;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	size_t	size;

	size = argc - 1;
	if (argc == 1)
		return (0);
	argc--;
	stack_a = ft_lstnew(argv[argc]);
	ft_printf("\nIn the order they're read in: \n");
	while (argc > 0)
	{
		ft_printf("%s ", argv[argc]);
		ft_lstadd_front(&stack_a, ft_lstnew(argv[argc]));
		argc--;
	}
	push_swap(stack_a);

	return (0);
}
