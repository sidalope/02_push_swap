/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:58:28 by abisani           #+#    #+#             */
/*   Updated: 2025/11/13 21:44:41 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clean_up(t_stacks *stacks)
{
	ft_lstclear(&stacks->a, stacks->a);
	ft_lstclear(&stacks->b, stacks->b);
	ft_lstclear(&stacks->log, stacks->log);
	// ft_lstclear(&stacks->sort_sizes_a, stacks->sort_sizes_a);
	// ft_lstclear(&stacks->sort_sizes_b, stacks->sort_sizes_b);
}

// ft_lstclear(&stacks->list_sizes_min, stacks->list_sizes_min);
// ft_lstclear(&stacks->list_sizes_mid, stacks->list_sizes_mid);
// ft_lstclear(&stacks->list_sizes_max, stacks->list_sizes_max);

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	argc--;
	if (!init(argc, argv, &stacks))
		return (1);
	if (!is_sorted(stacks.a))
		halfway_sort(&stacks);
	if (!is_sorted(stacks.a))
		ft_printf("Error sorting");
	// print_lists(&stacks);
	naive_pass(&stacks);
	// print_lists(&stacks);
	print_log(stacks.log->prev, stacks.log->prev);
	clean_up(&stacks);
	return (0);
}
