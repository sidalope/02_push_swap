/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:58:28 by abisani           #+#    #+#             */
/*   Updated: 2025/11/19 21:00:57 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	write_log_file(FILE *fp, t_list_node *curr, t_list_node *head)
// {
// 	if (!curr || !head || !fp)
// 	{
// 		ps_error();
// 		return ;
// 	}
// 	fprintf(fp, "%s\n", (char *) curr->content);
// 	if (curr->prev == head)
// 		return ;
// 	write_log_file(fp, curr->prev, head);
// }

static void	clean_up(t_stacks *stacks)
{
	ft_lstclear(&stacks->a, stacks->a);
	ft_lstclear(&stacks->b, stacks->b);
	ft_lstclear(&stacks->log, stacks->log);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	// FILE		*fp;

	if (argc == 1)
		return (0);
	argc--;
	if (!init(argc, argv, &stacks))
		return (1);
	if (!is_sorted(stacks.a))
		chunk_sort(&stacks);
	// print_chunks(stacks.b, &stacks);
	// if (!is_sorted(stacks.a))
	// 	ft_printf("Error sorting\n");
	// fp = fopen("before.txt", "w");
	// write_log_file(fp, stacks.log->prev, stacks.log->prev);
	// fclose(fp);
	// naive_pass(&stacks);
	// fp = fopen("after.txt", "w");
	// write_log_file(fp, stacks.log->prev, stacks.log->prev);
	// fclose(fp);
	// print_log(stacks.log->prev, stacks.log->prev);
	print_ranks(&stacks);
	ft_printf("\n");
	clean_up(&stacks);
	return (0);
}
