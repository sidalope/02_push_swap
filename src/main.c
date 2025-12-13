/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:58:28 by abisani           #+#    #+#             */
/*   Updated: 2025/12/13 19:16:26 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Free all allocated memory and exit */
static void	clean_up(t_stacks *stacks)
{
	ft_lstclear(&stacks->a, stacks->a);
	ft_lstclear(&stacks->b, stacks->b);
	ft_lstclear(&stacks->log, stacks->log);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	argc--;
	if (!init(argc, argv, &stacks))
		clean_up(&stacks);
	if (is_sorted(stacks.a))
		clean_up(&stacks);
	if (argc > 1 && argc < 6)
		sort_five(&stacks);
	else if (!chunk_sort(&stacks))
		clean_up(&stacks);
	if (!naive_pass(&stacks))
		clean_up(&stacks);
	print_log(stacks.log->prev, stacks.log->prev);
	clean_up(&stacks);
	return (0);
}
