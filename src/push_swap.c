/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:10:08 by abisiani          #+#    #+#             */
/*   Updated: 2025/10/15 20:33:13 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stacks *stacks)
{
	(void)stacks;
}

void	init(int argc, char *argv[], t_stacks *stacks)
{
	ft_printf("\nReading in... \n");
	stacks->a = NULL;
	stacks->b = NULL;
	while (argc > 0)
	{
		if (!ft_isnumber(argv[argc]))
			return (ps_error());
		ft_lstadd_front(&stacks->a, ft_lstnew(ft_atoi(argv[argc])));
		argc--;
	}
	ft_printf("The list:\n");
	ft_lstiter(stacks->a, stacks->a, print_content);
	check_and_rank(stacks->a, stacks->a);
	print_ranks(stacks->a);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	init(--argc, argv, &stacks);
	if (!is_sorted(stacks.a))
	{
		ft_printf("\nNot sorted.\n");
		push_swap(&stacks);
	}
	else
		ft_printf("\nAlready sorted.\n");
	ft_printf("Finished sorting.");
	push_swap(&stacks);

	return (0);
}
