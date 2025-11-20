/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:58:28 by abisani           #+#    #+#             */
/*   Updated: 2025/11/20 01:13:53 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clean_up(t_stacks *stacks)
{
	ft_lstclear(&stacks->a, stacks->a);
	ft_lstclear(&stacks->b, stacks->b);
	ft_lstclear(&stacks->log, stacks->log);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	argc--;
	if (!init(argc, argv, &stacks))
		return (1);
	if (is_sorted(stacks.a))
		return (0);
	if (!chunk_sort(&stacks))
		return (1);
	if (!naive_pass(&stacks))
		return (1);
	print_log(stacks.log->prev, stacks.log->prev);
	clean_up(&stacks);
	return (0);
}
