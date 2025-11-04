/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:58:28 by abisani           #+#    #+#             */
/*   Updated: 2025/11/01 14:12:35 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

static void	clean_up(t_stacks *stacks)
{
	ft_lstclear(&stacks->a, stacks->a);
	ft_lstclear(&stacks->b, stacks->b);
	ft_lstclear(&stacks->list_sizes_min, stacks->list_sizes_min);
	ft_lstclear(&stacks->list_sizes_mid, stacks->list_sizes_mid);
	ft_lstclear(&stacks->list_sizes_max, stacks->list_sizes_max);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	argc--;
	if (!init(argc, argv, &stacks))
		return (1);
	if (!is_sorted(stacks.a))
	{
		ft_printf("\nNot sorted.\n");
		msort(&stacks, argc);
		// ft_printf("Finished sorting.");
		print_lists(&stacks);
	}
	else
		ft_printf("\nAlready sorted.\n");
	clean_up(&stacks);
	return (0);
}
