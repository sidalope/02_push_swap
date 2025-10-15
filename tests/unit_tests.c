#include <stdio.h>
#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include "../src/push_swap.h"


// void	check_and_rank(t_stacks *stacks)
// {
// 	t_list_node	*lst;
// 	t_list_node	*lst_comparison;

// 	lst = stacks->a;
// 	lst_comparison = stacks->a;

// 	while (lst != stacks->a->prev)
// 	{
// 		while (lst_comparison != stacks->a->prev)
// 		{
// 			is_smaller(lst->content, lst_comparison);
// 			lst_comparison = lst_comparison->next;
// 		}
// 		is_smaller(lst->content, lst_comparison);
// 		lst_comparison = lst_comparison->next;
// 		lst = lst->next;
// 	}
// 	while (lst_comparison != stacks->a->prev)
// 	{
// 		is_smaller(lst->content, lst_comparison);
// 		lst_comparison = lst_comparison->next;
// 	}
// 	is_smaller(lst->content, lst_comparison);
// }

// void	*__real_malloc(size_t size);
// void	__real_free(void *ptr);

// void	*__wrap_malloc(size_t size)
// {
// 	void	*ptr;
// 	// void *tracePtrs[10];
// 	// size_t count;
// 	// 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47
// 	if (rand() % 101)
// 		ptr = __real_malloc(size);
// 	else
// 		ptr = NULL;
// 	dprintf(2, "%s at line %i\n", __FILE__, __LINE__);
// 	dprintf(2, "%s()\n", __func__);
// 	dprintf(2, "caller: %p()\n",__builtin_return_address(0));
// 	dprintf(2, "malloc(%zu) = %p\n\n", size, ptr);
// 	return (ptr);
// }

// void	__wrap_free(void *ptr)
// {
// 	dprintf(2, "free(%p)\n\n", ptr);
// 	__real_free(ptr);
// }

void print_content(int content)
{
    printf("%d ", content);
}

void	test_push(t_stacks *stacks)
{
	printf("\n\n~~~~~~~~~~~~~~\ntest push\n");
	printf("\npush()\na: ");
	push(&stacks->a, &stacks->b);
	ft_lstiter(stacks->a, stacks->a, print_content);
	printf("\nb: ");
	ft_lstiter(stacks->b, stacks->b, print_content);
	printf("\n");
	printf("\npush()\na: ");
	push(&stacks->a, &stacks->b);
	ft_lstiter(stacks->a, stacks->a, print_content);
	printf("\nb: ");
	ft_lstiter(stacks->b, stacks->b, print_content);
	printf("\n");
	printf("\npush() 5x\na: ");
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	ft_lstiter(stacks->a, stacks->a, print_content);
	printf("\nb: ");
	ft_lstiter(stacks->b, stacks->b, print_content);
	printf("\n");
	printf("\npush() 20x\na: ");
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	ft_lstiter(stacks->a, stacks->a, print_content);
	printf("\nb: ");
	ft_lstiter(stacks->b, stacks->b, print_content);
	printf("\n");
}

void	test_swap(t_stacks *stacks)
{
	push(&stacks->b, &stacks->a);
	push(&stacks->b, &stacks->a);
	push(&stacks->b, &stacks->a);
	push(&stacks->b, &stacks->a);
	push(&stacks->b, &stacks->a);
	printf("\n~~~~~~~~~~~~~~\ntest swap\na: ");
	ft_lstiter(stacks->a, stacks->a, print_content);
	printf("\n\nswap a\n");
	swap(&stacks->a);
	printf("a: ");
	ft_lstiter(stacks->a, stacks->a, print_content);
	printf("\n\nswap a\n");
	swap(&stacks->a);
	printf("a: ");
	ft_lstiter(stacks->a, stacks->a, print_content);
	printf("\n\npush and swap a");
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	printf("\na: ");
	ft_lstiter(stacks->a, stacks->a, print_content);
	printf("\nb: ");
	ft_lstiter(stacks->b, stacks->b, print_content);
	printf("\n\nswap a again");
	swap(&stacks->a);
	printf("\na: ");
	ft_lstiter(stacks->a, stacks->a, print_content);
	printf("\n\nswap empty a");
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	push(&stacks->a, &stacks->b);
	swap(&stacks->a);
	printf("\na: ");
	ft_lstiter(stacks->a, stacks->a, print_content);
	printf("\n\nswap one in a");
	push(&stacks->b, &stacks->a);
	printf("\na: ");
	ft_lstiter(stacks->a, stacks->a, print_content);
	swap(&stacks->a);
	printf("\na: ");
	ft_lstiter(stacks->a, stacks->a, print_content);

}

void	test_rotation(t_stacks *stacks)
{
	printf("\n\n~~~~~~~~~~~~~~\ntest rotation\n");
	printf("\nb: ");
	ft_lstiter(stacks->b, stacks->b, print_content);
	printf("\n\nrotate");
	rotate(&stacks->b);
	printf("\nb: ");
	ft_lstiter(stacks->b, stacks->b, print_content);
	printf("\n\nrotate again");
	rotate(&stacks->b);
	printf("\nb: ");
	ft_lstiter(stacks->b, stacks->b, print_content);
	printf("\n\nreverse rotate");
	rrotate(&stacks->b);
	printf("\nb: ");
	ft_lstiter(stacks->b, stacks->b, print_content);
	printf("\n\nreverse rotate again");
	rrotate(&stacks->b);
	printf("\nb: ");
	ft_lstiter(stacks->b, stacks->b, print_content);
	printf("\n\nrotate 40x");
	for (int i=40; i > 0; i--)
	{
		rotate(&stacks->b);
		printf("\nb: ");
		ft_lstiter(stacks->b, stacks->b, print_content);
	}
	printf("\n\nreverse rotate 40x");
	for (int i=40; i > 0; i--)
	{
		rrotate(&stacks->b);
		printf("\nb: ");
		ft_lstiter(stacks->b, stacks->b, print_content);
	}
}

void	init(int argc, char *argv[], t_stacks *stacks)
{
	ft_printf("\nReading in... \n");
	stacks->a = NULL;
	stacks->b = NULL;
	while (argc > 0)
	{
		ft_lstadd_front(&stacks->a, ft_lstnew(ft_atoi(argv[argc])));
		argc--;
	}
	ft_printf("The list:\n");
	ft_lstiter(stacks->a, stacks->a, print_content);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	init(--argc, argv, &stacks);
	test_push(&stacks);
	test_swap(&stacks);
	test_rotation(&stacks);

	return (0);
}
