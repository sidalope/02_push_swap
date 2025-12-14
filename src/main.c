/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:58:28 by abisani           #+#    #+#             */
/*   Updated: 2025/12/14 12:13:10 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Free allocated memory and exit */
void	clean_up(t_stacks *stacks)
{
	ft_lstclear(&stacks->a, stacks->a);
	ft_lstclear(&stacks->b, stacks->b);
	ft_lstclear(&stacks->log, stacks->log);
	exit(0);
}

/* Write error message to stderr, clean up, and exit */
void	ps_error(t_stacks *stacks)
{
	write(2, "Error\n", 7);
	clean_up(stacks);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	argc--;
	init(argc, argv, &stacks);
	if (is_sorted(stacks.a))
		clean_up(&stacks);
	if (argc > 1 && argc < 6)
		sort_five(&stacks);
	else
		chunk_sort(&stacks);
	naive_pass(&stacks);
	print_log(stacks.log->prev, stacks.log->prev);
	clean_up(&stacks);
	return (0);
}
