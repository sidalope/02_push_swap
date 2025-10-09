/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:10:08 by abisiani          #+#    #+#             */
/*   Updated: 2025/10/09 14:45:33 by abisiani         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	push_swap(t_stacks *stacks)
{
	(void)stacks
;}

void	init(int argc, char *argv[], t_stacks *stacks)
{
	ft_printf("\nReading in... \n");
	stacks->a = NULL;
	stacks->b = NULL;
	while (argc > 0)
	{
		ft_lstadd_front(&stacks->a, ft_lstnew(argv[argc]));
		argc--;
	}
	ft_printf("The list:\n");
	ft_lstiter(stacks->a, print_content);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	init(--argc, argv, &stacks);
	push_swap(&stacks);

	return (0);
}
