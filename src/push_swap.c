/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:10:08 by abisiani          #+#    #+#             */
/*   Updated: 2025/10/17 14:18:05 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_up(t_stacks *stacks)
{
	ft_lstclear(&stacks->a, stacks->a);
	ft_lstclear(&stacks->b, stacks->b);
}

void	push_swap(t_stacks *stacks)
{
	(void)stacks;
}

int	init(int argc, char *argv[], t_stacks *stacks)
{
	ft_printf("\nReading in... \n");
	stacks->a = NULL;
	stacks->b = NULL;
	while (argc > 0)
	{
		if (!ft_isnumber(argv[argc]))
			return (ps_error(), 0);
		ft_lstadd_front(&stacks->a, ft_lstnew(ft_atoi(argv[argc])));
		argc--;
	}
	ft_printf("The list:\n");
	ft_lstiter(stacks->a, stacks->a, print_content);
	if (!check_and_rank(stacks->a, stacks->a))
		return (0);
	print_ranks(stacks->a);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	if (!init(--argc, argv, &stacks))
		return (1);
	if (!is_sorted(stacks.a))
	{
		ft_printf("\nNot sorted.\n");
		push_swap(&stacks);
		ft_printf("Finished sorting.");
	}
	else
		ft_printf("\nAlready sorted.\n");
	clean_up(&stacks);
	return (0);
}
