/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:58:28 by abisani           #+#    #+#             */
/*   Updated: 2025/12/18 14:49:39 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Free allocated memory and exit */
void	clean_up(t_stacks *stacks)
{
	ft_lstclear(&stacks->a, stacks->a);
	ft_lstclear(&stacks->b, stacks->b);
	ft_lstclear(&stacks->log, stacks->log);
}

/* Write error message to stderr, clean up, and exit */
void	ps_error(t_stacks *stacks)
{
	write(2, "Error\n", 7);
	clean_up(stacks);
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	if (argc == 1 || argc == 2)
		return (0);
	argc--;
	init(argc, argv, &stacks);
	if (is_sorted(stacks.a))
	{
		clean_up(&stacks);
		return (0);
	}
	if (argc > 1 && argc < 6)
		sort_five(&stacks);
	else if (argc < 350)
		chunk_sort(&stacks);
	else
		radix_sort(&stacks);
	naive_pass(&stacks);
	print_log(stacks.log->prev, stacks.log->prev);
	clean_up(&stacks);
	return (0);
}
