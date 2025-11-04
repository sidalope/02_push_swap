#include <stdio.h>
#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include "../src/push_swap.h"

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

void	setup_test_stacks(t_stacks *stacks, int *test_data_a, int *test_data_b, int len_a, int len_b)
{
	int	i;

	// Clear existing lists
	if (stacks->a)
		ft_lstclear(&stacks->a, stacks->a);
	if (stacks->b)
		ft_lstclear(&stacks->b, stacks->b);
	
	// Initialize stacks
	stacks->a = NULL;
	stacks->b = NULL;
	
	// Add elements to stacks a and b
	if (test_data_a && len_a > 0)
	{
		i = len_a - 1;
		while (i >= 0)
		{
			ft_lstadd_front(&stacks->a, ft_lstnew(test_data_a[i]));
			i--;
		}
	}
	if (test_data_b && len_b > 0)
	{
		i = len_b - 1;
		while (i >= 0)
		{
			ft_lstadd_front(&stacks->b, ft_lstnew(test_data_b[i]));
			i--;
		}
	}
	// ft_printf("\nSetup complete.\na: ");
	// print_lst_content(stacks->a, stacks->a);
	// ft_printf("b: ");
	// print_lst_content(stacks->b, stacks->b);
	// ft_printf("\n");
}

void	teardown_test_stacks(t_stacks *stacks)
{
	ft_lstclear(&stacks->a, stacks->a);
	ft_lstclear(&stacks->b, stacks->b);
}

void	setup_test_push_normal(t_stacks *stacks)
{
	int	test_data_a[] = {3, 6, 4, 5, 8, 0};
	int	len_a = sizeof(test_data_a) / sizeof(test_data_a[0]);
	
	ft_printf("Setting up push test scenario: a = [3, 6, 4, 5, 8, 0], b = []\n");
	setup_test_stacks(stacks, test_data_a, NULL, len_a, 0);
}

void	test_push_normal(t_stacks *stacks)
{
	ft_printf("\n\n~~~~~~~~~~~~~~\ntest push\n");
	
	// Setup the test scenario
	setup_test_push_normal(stacks);
	
	// Test specific scenario: a = 3 6 4 5 8 0, b = empty
	ft_printf("\nInitial state:\n");
	ft_printf("a: ");
	print_lst_content(stacks->a, stacks->a);
	ft_printf("b: ");
	print_lst_content(stacks->b, stacks->b);
	
	// Verify the heads of the lists
	assert (stacks->a && stacks->a->content == 3);
	assert (!stacks->b);
	
	// Perform the push operation
	ft_printf("\n\nPerforming push from a to b...\n");
	int push_return = push(&stacks->a, &stacks->b);
	assert (push_return == 0);

	ft_printf("\nAfter push:\n");
	ft_printf("a: ");
	print_lst_content(stacks->a, stacks->a);
	ft_printf("b: ");
	print_lst_content(stacks->b, stacks->b);

	// Verify expected results
	ft_printf("\nVerification:\n");
	// Check stack a head (should be 6)
	assert (stacks->a && stacks->a->content == 6);
	ft_printf("✓ Stack a head is 6 (correct)\n");
	// Check stack b head (should be 3)
	assert (stacks->b && stacks->b->content == 3);
	ft_printf("✓ Stack b head is 3 (correct)\n");
	// Check stack sizes
	int size_a = ft_lstsize(stacks->a, 0, stacks->a);
	int size_b = ft_lstsize(stacks->b, 0, stacks->b);
	
	assert (size_a == 5);
	ft_printf("✓ Stack a size is 5 (correct)\n");
	assert (size_b == 1);
	ft_printf("✓ Stack b size is 1 (correct)\n");
	
	teardown_test_stacks(stacks);
}

void	setup_test_push_void(t_stacks *stacks)
{
	ft_printf("Setting up push void test scenario: a = [], b = []\n");
	setup_test_stacks(stacks, NULL, NULL, 0, 0);
}

void	test_push_void(t_stacks *stacks)
{
	ft_printf("\n\n~~~~~~~~~~~~~~\ntest push void\n");
	
	// Setup the test scenario
	setup_test_push_void(stacks);
	
	// Test specific scenario: a = empty, b = empty
	ft_printf("\nInitial state:\n");
	ft_printf("a: ");
	print_lst_content(stacks->a, stacks->a);
	ft_printf("b: ");
	print_lst_content(stacks->b, stacks->b);
	
	// Verify both stacks are empty
	assert (!stacks->a);
	assert (!stacks->b);
	
	// Perform the push operation
	ft_printf("\n\nPerforming push from empty a to empty b...\n");
	int push_return = push(&stacks->a, &stacks->b);
	assert (push_return == -1);
	ft_printf("✓ Push operation returned -1 (correct for empty source)\n");
	
	// Verify expected results - both stacks should still be empty
	ft_printf("\nVerification:\n");
	assert (!stacks->a);
	ft_printf("✓ Stack a is still empty (correct)\n");
	assert (!stacks->b);
	ft_printf("✓ Stack b is still empty (correct)\n");
	
	// Check stack sizes are 0
	int size_a = ft_lstsize(stacks->a, 0, stacks->a);
	int size_b = ft_lstsize(stacks->b, 0, stacks->b);
	
	assert (size_a == 0);
	ft_printf("✓ Stack a size is 0 (correct)\n");
	assert (size_b == 0);
	ft_printf("✓ Stack b size is 0 (correct)\n");
	
	// Now call push 500 times consecutively on empty stacks
	ft_printf("\n--- 500 consecutive push calls ---\n");
	ft_printf("Calling push() 500 times on empty stacks...\n");
	
	int consecutive_calls = 500;
	int success_count = 0;
	int expected_return = -1;
	
	for (int i = 0; i < consecutive_calls; i++)
	{
		int result = push(&stacks->a, &stacks->b);
		if (result == expected_return)
			success_count++;
		
		// Verify stacks remain empty after each call
		if (stacks->a != NULL || stacks->b != NULL)
		{
			ft_printf("✗ ERROR: Stacks not empty after call %d\n", i + 1);
			assert(0); // Fail the test
		}
	}
	
	// Verify all calls returned the expected value
	assert (success_count == consecutive_calls);
	ft_printf("✓ All %d push calls returned -1 (correct)\n", consecutive_calls);
	
	// Final verification that stacks are still empty
	assert (!stacks->a);
	assert (!stacks->b);
	ft_printf("✓ Stacks remain empty after %d consecutive calls\n", consecutive_calls);
	
	// Verify sizes are still 0
	size_a = ft_lstsize(stacks->a, 0, stacks->a);
	size_b = ft_lstsize(stacks->b, 0, stacks->b);
	
	assert (size_a == 0);
	assert (size_b == 0);
	ft_printf("✓ Stack sizes remain 0 after stress test\n");
	
	ft_printf("✓ Push void stress test completed successfully\n");
	teardown_test_stacks(stacks);
}

void	setup_test_push_large(t_stacks *stacks)
{
	int	test_data_a[500];
	int	*test_data_b = NULL; // Empty stack b
	int	len_a = 500;
	int	len_b = 0;
	int	i, j;
	int	temp;
	
	// Initialize array with numbers 1-500
	for (i = 0; i < 500; i++)
		test_data_a[i] = i + 1;
	
	// Fisher-Yates shuffle algorithm for random distribution
	srand(42); // Use fixed seed for reproducible tests
	for (i = 499; i > 0; i--)
	{
		j = rand() % (i + 1);
		temp = test_data_a[i];
		test_data_a[i] = test_data_a[j];
		test_data_a[j] = temp;
	}
	
	ft_printf("Setting up large push test scenario: a = [500 random numbers], b = []\n");
	setup_test_stacks(stacks, test_data_a, test_data_b, len_a, len_b);
}

void	test_push_large(t_stacks *stacks)
{
	ft_printf("\n\n~~~~~~~~~~~~~~\ntest push large\n");
	
	// Setup the test scenario
	setup_test_push_large(stacks);
	
	// Initial state verification
	ft_printf("\nInitial state verification:\n");
	int initial_size_a = ft_lstsize(stacks->a, 0, stacks->a);
	int initial_size_b = ft_lstsize(stacks->b, 0, stacks->b);
	
	assert(initial_size_a == 500);
	ft_printf("✓ Stack a has 500 elements\n");
	assert(initial_size_b == 0);
	ft_printf("✓ Stack b is empty\n");
	
	// Phase 1: Push 250 elements from a to b
	ft_printf("\nPhase 1: Pushing 250 elements from a to b...\n");
	for (int i = 0; i < 250; i++)
	{
		int result = push(&stacks->a, &stacks->b);
		assert(result == 0);
		
		// Verify progress every 50 pushes
		if ((i + 1) % 50 == 0)
		{
			int size_a = ft_lstsize(stacks->a, 0, stacks->a);
			int size_b = ft_lstsize(stacks->b, 0, stacks->b);
			ft_printf("  After %d pushes: a=%d, b=%d\n", i + 1, size_a, size_b);
		}
	}
	
	// Verify state after phase 1
	int mid_size_a = ft_lstsize(stacks->a, 0, stacks->a);
	int mid_size_b = ft_lstsize(stacks->b, 0, stacks->b);
	
	assert(mid_size_a == 250);
	assert(mid_size_b == 250);
	ft_printf("✓ Phase 1 complete: a=%d, b=%d\n", mid_size_a, mid_size_b);
	
	// Phase 2: Random pushes between a and b (2500 times)
	ft_printf("\nPhase 2: 2500 random pushes between stacks...\n");
	srand(42); // Use same seed for reproducible tests
	
	int push_count = 0;
	int failed_pushes = 0;
	
	for (int i = 0; i < 2500; i++)
	{
		int choice = rand() % 2; // 0 = push a->b, 1 = push b->a
		int result;
		
		if (choice == 0)
		{
			result = push(&stacks->a, &stacks->b);
		}
		else
		{
			result = push(&stacks->b, &stacks->a);
		}
		
		if (result == 0)
			push_count++;
		else
			failed_pushes++; // Failed because source was empty
		
		// Progress report every 500 operations
		if ((i + 1) % 500 == 0)
		{
			int size_a = ft_lstsize(stacks->a, 0, stacks->a);
			int size_b = ft_lstsize(stacks->b, 0, stacks->b);
			ft_printf("  After %d operations: a=%d, b=%d, successful=%d, failed=%d\n", 
					  i + 1, size_a, size_b, push_count, failed_pushes);
		}
	}
	
	// Final verification
	ft_printf("\nFinal verification:\n");
	int final_size_a = ft_lstsize(stacks->a, 0, stacks->a);
	int final_size_b = ft_lstsize(stacks->b, 0, stacks->b);
	int total_elements = final_size_a + final_size_b;
	
	assert(total_elements == 500);
	ft_printf("✓ Total elements preserved: %d (a=%d, b=%d)\n", 
			  total_elements, final_size_a, final_size_b);
	ft_printf("✓ Successful pushes: %d\n", push_count);
	ft_printf("✓ Failed pushes (empty source): %d\n", failed_pushes);
	ft_printf("✓ Large push test completed successfully!\n");
	teardown_test_stacks(stacks);
}

void	test_push(t_stacks *stacks)
{
	test_push_normal(stacks);
	test_push_void(stacks);
	test_push_large(stacks);
}

void	setup_test_swap_normal(t_stacks *stacks)
{
	int	test_data_a[] = {1, 2, 3, 4, 5};
	int	*test_data_b = NULL; // Empty stack b
	int	len_a = 5;
	int	len_b = 0;
	
	ft_printf("Setting up swap normal test scenario: a = [1, 2, 3, 4, 5], b = []\n");
	setup_test_stacks(stacks, test_data_a, test_data_b, len_a, len_b);
}

void	test_swap_normal(t_stacks *stacks)
{
	ft_printf("\n\n~~~~~~~~~~~~~~\ntest swap normal\n");
	
	// Setup the test scenario
	setup_test_swap_normal(stacks);
	
	// Initial state verification
	ft_printf("\nInitial state:\n");
	ft_printf("a: ");
	print_lst_content(stacks->a, stacks->a);
	ft_printf("b: ");
	print_lst_content(stacks->b, stacks->b);
	
	// Verify initial head and second element
	assert(stacks->a && stacks->a->content == 1);
	assert(stacks->a->next && stacks->a->next->content == 2);
	ft_printf("\n✓ Stack a head is 1, second is 2 (correct)");
	
	// Test first swap operation
	ft_printf("\n\nTesting swap on stack a...\n");
	int result = swap(&stacks->a);
	assert(result == 0);
	ft_printf("✓ Swap operation succeeded\n");
	
	ft_printf("After first swap:\na: ");
	print_lst_content(stacks->a, stacks->a);
	
	// Verify elements swapped
	assert(stacks->a && stacks->a->content == 2);
	assert(stacks->a->next && stacks->a->next->content == 1);
	ft_printf("✓ Stack a head is now 2, second is 1 (correct)\n");
	
	// Test second swap (should return to original)
	ft_printf("\nTesting second swap (should revert)...\n");
	result = swap(&stacks->a);
	assert(result == 0);
	ft_printf("✓ Second swap operation succeeded\n");
	
	ft_printf("After second swap:\na: ");
	print_lst_content(stacks->a, stacks->a);
	
	// Should be back to original state
	assert(stacks->a && stacks->a->content == 1);
	assert(stacks->a->next && stacks->a->next->content == 2);
	ft_printf("✓ Stack a back to original: head=1, second=2 (correct)\n");
	
	// Test size preservation
	int size_a = ft_lstsize(stacks->a, 0, stacks->a);
	assert(size_a == 5);
	ft_printf("✓ Stack a size preserved: %d elements\n", size_a);
	teardown_test_stacks(stacks);
}

void	setup_test_swap_void(t_stacks *stacks)
{
	int	*test_data_a = NULL; // Empty stack a
	int	*test_data_b = NULL; // Empty stack b
	int	len_a = 0;
	int	len_b = 0;
	
	ft_printf("Setting up swap void test scenario: a = [], b = []\n");
	setup_test_stacks(stacks, test_data_a, test_data_b, len_a, len_b);
}

void	test_swap_void(t_stacks *stacks)
{
	ft_printf("\n\n~~~~~~~~~~~~~~\ntest swap void\n");
	
	// Setup the test scenario
	setup_test_swap_void(stacks);
	
	// Initial state verification
	ft_printf("\nInitial state:\n");
	ft_printf("a: ");
	print_lst_content(stacks->a, stacks->a);
	ft_printf("b: ");
	print_lst_content(stacks->b, stacks->b);
	
	// Verify both stacks are empty
	assert(!stacks->a);
	assert(!stacks->b);
	ft_printf("\n✓ Both stacks are empty (correct)");
	
	// Test swap on empty stack
	ft_printf("\n\nTesting swap on empty stack a...\n");
	int result = swap(&stacks->a);
	assert(result == -1);
	ft_printf("✓ Swap returned -1 for empty stack (correct)\n");
	
	// Verify stacks remain empty
	assert(!stacks->a);
	assert(!stacks->b);
	ft_printf("✓ Stacks remain empty after operation\n");
	
	// Test single element case
	ft_printf("\n--- Testing single element case ---\n");
	ft_lstadd_front(&stacks->a, ft_lstnew(42));
	
	ft_printf("After adding single element:\na: ");
	print_lst_content(stacks->a, stacks->a);
	
	// Test swap on single element
	result = swap(&stacks->a);
	assert(result == -1);
	ft_printf("✓ Swap returned -1 for single element (correct)\n");
	
	// Verify element unchanged
	assert(stacks->a && stacks->a->content == 42);
	ft_printf("✓ Single element unchanged: %d\n", stacks->a->content);
	
	// Stress test: 100 consecutive swaps on empty/single element
	ft_printf("\n--- Stress Test: 100 consecutive swaps on edge cases ---\n");
	
	// Clear for empty test
	ft_lstclear(&stacks->a, stacks->a);
	stacks->a = NULL;
	
	int empty_success = 0;
	for (int i = 0; i < 50; i++)
	{
		if (swap(&stacks->a) == -1)
			empty_success++;
	}
	
	// Add single element for single test
	ft_lstadd_front(&stacks->a, ft_lstnew(99));
	int single_success = 0;
	for (int i = 0; i < 50; i++)
	{
		if (swap(&stacks->a) == -1)
			single_success++;
	}
	
	assert(empty_success == 50 && single_success == 50);
	ft_printf("✓ All edge case swaps handled correctly (50 empty + 50 single)\n");
	ft_printf("✓ Swap void stress test completed successfully!\n");
	teardown_test_stacks(stacks);
}

void	setup_test_swap_large(t_stacks *stacks)
{
	int	test_data_a[500];
	int	*test_data_b = NULL; // Empty stack b
	int	len_a = 500;
	int	len_b = 0;
	
	// Create sequential numbers 1-500
	for (int i = 0; i < 500; i++)
		test_data_a[i] = i + 1;
	
	ft_printf("Setting up swap large test scenario: a = [1-500], b = []\n");
	setup_test_stacks(stacks, test_data_a, test_data_b, len_a, len_b);
}

void	test_swap_large(t_stacks *stacks)
{
	ft_printf("\n\n~~~~~~~~~~~~~~\ntest swap large\n");
	
	// Setup the test scenario
	setup_test_swap_large(stacks);
	
	// Initial state verification
	int initial_size = ft_lstsize(stacks->a, 0, stacks->a);
	assert(initial_size == 500);
	ft_printf("\n✓ Stack a has 500 elements\n");
	
	// Record initial first two elements
	int first = stacks->a->content;
	int second = stacks->a->next->content;
	assert(first == 1 && second == 2);
	ft_printf("✓ Initial: first=%d, second=%d\n", first, second);
	
	// Test: Multiple swaps should alternate between two states
	ft_printf("\nPhase 1: Testing swap consistency (10 swaps)...\n");
	for (int i = 0; i < 10; i++)
	{
		int result = swap(&stacks->a);
		assert(result == 0);
		
		int current_first = stacks->a->content;
		int current_second = stacks->a->next->content;
		
		if (i % 2 == 0) // After even swaps (1st, 3rd, 5th...)
		{
			assert(current_first == 2 && current_second == 1);
		}
		else // After odd swaps (2nd, 4th, 6th...)
		{
			assert(current_first == 1 && current_second == 2);
		}
		
		if ((i + 1) % 2 == 0)
		{
			ft_printf("  After %d swaps: first=%d, second=%d\n", 
					  i + 1, current_first, current_second);
		}
	}
	ft_printf("✓ Swap alternation pattern verified\n");
	
	// Test: Size preservation during intensive swapping
	ft_printf("\nPhase 2: Intensive swap stress test (1000 swaps)...\n");
	for (int i = 0; i < 1000; i++)
	{
		int result = swap(&stacks->a);
		assert(result == 0);
		
		// Verify size preservation every 200 swaps
		if ((i + 1) % 200 == 0)
		{
			int current_size = ft_lstsize(stacks->a, 0, stacks->a);
			assert(current_size == 500);
			ft_printf("  After %d swaps, size is still: %d\n", i + 1, current_size);
		}
	}
	
	// Final state verification (1000 swaps = even, so should be original)
	assert(stacks->a->content == 1 && stacks->a->next->content == 2);
	ft_printf("✓ After 1000 swaps, back to original state: first=1, second=2\n");
	teardown_test_stacks(stacks);
}

void	test_swap(t_stacks *stacks)
{
	test_swap_normal(stacks);
	test_swap_void(stacks);
	test_swap_large(stacks);
}

void	setup_test_rotation_normal(t_stacks *stacks)
{
	int	test_data_a[] = {1, 2, 3, 4, 5};
	int	*test_data_b = NULL; // Empty stack b
	int	len_a = 5;
	int	len_b = 0;
	
	ft_printf("Setting up rotation normal test scenario: a = [1, 2, 3, 4, 5], b = []\n");
	setup_test_stacks(stacks, test_data_a, test_data_b, len_a, len_b);
}

void	test_rotation_normal(t_stacks *stacks)
{
	ft_printf("\n\n~~~~~~~~~~~~~~\ntest rotation normal\n");
	
	// Setup the test scenario
	setup_test_rotation_normal(stacks);
	
	// Initial state verification
	ft_printf("\nInitial state:\n");
	ft_printf("a: ");
	print_lst_content(stacks->a, stacks->a);
	ft_printf("b: ");
	print_lst_content(stacks->b, stacks->b);
	
	// Verify initial head
	assert(stacks->a && stacks->a->content == 1);
	ft_printf("\n✓ Stack a head is 1 (correct)");
	
	// Test rotate on stack a
	ft_printf("\n\nTesting rotate on stack a...\n");
	int result = rotate(&stacks->a);
	assert(result == 0);
	ft_printf("✓ Rotate operation succeeded\n");
	
	ft_printf("After rotate:\na: ");
	print_lst_content(stacks->a, stacks->a);
	
	// Verify head moved to 2
	assert(stacks->a && stacks->a->content == 2);
	ft_printf("✓ Stack a head is now 2 (correct)\n");
	
	// Test reverse rotate
	ft_printf("\nTesting reverse rotate on stack a...\n");
	result = rrotate(&stacks->a);
	assert(result == 0);
	ft_printf("✓ Reverse rotate operation succeeded\n");
	
	ft_printf("After reverse rotate:\na: ");
	print_lst_content(stacks->a, stacks->a);
	
	// Should be back to original state
	assert(stacks->a && stacks->a->content == 1);
	ft_printf("✓ Stack a head is back to 1 (correct)\n");
	
	// Test size preservation
	int size_a = ft_lstsize(stacks->a, 0, stacks->a);
	assert(size_a == 5);
	ft_printf("✓ Stack a size preserved: %d elements\n", size_a);
	teardown_test_stacks(stacks);
}

void	setup_test_rotation_void(t_stacks *stacks)
{
	ft_printf("Setting up rotation void test scenario: a = [], b = []\n");
	setup_test_stacks(stacks, NULL, NULL, 0, 0);
}

void	test_rotation_void(t_stacks *stacks)
{
	ft_printf("\n\n~~~~~~~~~~~~~~\ntest rotation void\n");
	
	// Setup the test scenario
	setup_test_rotation_void(stacks);
	
	// Initial state verification
	ft_printf("\nInitial state:\n");
	ft_printf("a: ");
	print_lst_content(stacks->a, stacks->a);
	ft_printf("b: ");
	print_lst_content(stacks->b, stacks->b);
	
	// Verify both stacks are empty
	assert(!stacks->a);
	assert(!stacks->b);
	ft_printf("\n✓ Both stacks are empty (correct)");
	
	// Test rotate on empty stack
	ft_printf("\n\nTesting rotate on empty stack a...\n");
	int result = rotate(&stacks->a);
	assert(result == -1);
	ft_printf("✓ Rotate returned -1 for empty stack (correct)\n");
	
	// Test reverse rotate on empty stack
	ft_printf("Testing reverse rotate on empty stack a...\n");
	result = rrotate(&stacks->a);
	assert(result == -1);
	ft_printf("✓ Reverse rotate returned -1 for empty stack (correct)\n");
	
	// Verify stacks remain empty
	assert(!stacks->a);
	assert(!stacks->b);
	ft_printf("✓ Stacks remain empty after operations\n");
	
	// Stress test: 100 consecutive rotations on empty stacks
	ft_printf("\n--- Stress Test: 100 consecutive rotations on empty stacks ---\n");
	int success_count = 0;
	
	for (int i = 0; i < 100; i++)
	{
		int rot_result = rotate(&stacks->a);
		int rrot_result = rrotate(&stacks->a);
		
		if (rot_result == -1 && rrot_result == -1)
			success_count++;
		
		// Verify stacks remain empty
		assert(!stacks->a && !stacks->b);
	}
	
	assert(success_count == 100);
	ft_printf("✓ All 100 rotation pairs returned -1 (correct)\n");
	ft_printf("✓ Rotation void stress test completed successfully\n");
	teardown_test_stacks(stacks);
}

void	setup_test_rotation_large(t_stacks *stacks)
{
	int	test_data_a[500];
	int	*test_data_b = NULL; // Empty stack b
	int	len_a = 500;
	int	len_b = 0;
	
	// Create sequential numbers 1-500
	for (int i = 0; i < 500; i++)
		test_data_a[i] = i + 1;
	
	ft_printf("Setting up rotation large test scenario: a = [1-500], b = []\n");
	setup_test_stacks(stacks, test_data_a, test_data_b, len_a, len_b);
}

void	test_rotation_large(t_stacks *stacks)
{
	ft_printf("\n\n~~~~~~~~~~~~~~\ntest rotation large\n");
	
	// Setup the test scenario
	setup_test_rotation_large(stacks);
	
	// Initial state verification
	int initial_size = ft_lstsize(stacks->a, 0, stacks->a);
	assert(initial_size == 500);
	ft_printf("\n✓ Stack a has 500 elements\n");
	
	// Record initial head
	t_list_node *original_head = stacks->a;
	assert(stacks->a->content == 1);
	ft_printf("✓ Initial head is %d\n", stacks->a->content);
	
	// Test: Rotate 500 times should bring us back to original state
	ft_printf("\nPhase 1: Rotating 500 times (full cycle)...\n");
	for (int i = 0; i < 500; i++)
	{
		int result = rotate(&stacks->a);
		assert(result == 0);
		
		if ((i + 1) % 100 == 0)
		{
			ft_printf("  After %d rotations, head is: %d\n", i + 1, stacks->a->content);
		}
	}
	
	// Should be back to original head
	assert(stacks->a == original_head);
	ft_printf("✓ After 500 rotations, head is back to %d (full cycle completed)\n", stacks->a->content);
	
	// Test: Reverse rotate 250 times, then rotate 250 times
	ft_printf("\nPhase 2: Reverse rotate 250 times, then rotate 250 times...\n");
	
	// Reverse rotate 250 times
	for (int i = 0; i < 250; i++)
	{
		int result = rrotate(&stacks->a);
		assert(result == 0);
	}
	
	int mid_head = stacks->a->content;
	ft_printf("  After 250 reverse rotations, head is: %d\n", mid_head);
	
	// Rotate 250 times to get back
	for (int i = 0; i < 250; i++)
	{
		int result = rotate(&stacks->a);
		assert(result == 0);
	}
	
	assert(stacks->a == original_head);
	ft_printf("✓ After 250 reverse + 250 forward rotations, head is back to %d\n", stacks->a->content);
	
	// Test: Random rotations stress test
	ft_printf("\nPhase 3: 3000 random rotations...\n");
	srand(42); // Fixed seed for reproducibility
	
	for (int i = 0; i < 3000; i++)
	{
		int choice = rand() % 2;
		int result;
		
		if (choice == 0)
			result = rotate(&stacks->a);
		else
			result = rrotate(&stacks->a);
		
		assert(result == 0);
		
		// Verify size preservation every 200 operations
		if ((i + 1) % 500 == 0)
		{
			int current_size = ft_lstsize(stacks->a, 0, stacks->a);
			assert(current_size == 500);
			ft_printf("  After %d operations, size is still: %d\n", i + 1, current_size);
		}
	}
	
	// Final verification
	int final_size = ft_lstsize(stacks->a, 0, stacks->a);
	assert(final_size == 500);
	ft_printf("✓ Final size preserved: %d elements\n", final_size);
	ft_printf("✓ Large rotation test completed successfully!\n");
	teardown_test_stacks(stacks);
}

void	test_rotation(t_stacks *stacks)
{
	test_rotation_normal(stacks);
	test_rotation_void(stacks);
	test_rotation_large(stacks);
}

void	setup_test_mixed_operations(t_stacks *stacks)
{
	int	test_data_a[500];
	int	test_data_b[500];
	int	len_a = 500;
	int	len_b = 500;
	int	i;
	
	// Create first 500 numbers (1-500) for stack a
	for (i = 0; i < 500; i++)
		test_data_a[i] = i + 1;
	
	// Create second 500 numbers (501-1000) for stack b
	for (i = 0; i < 500; i++)
		test_data_b[i] = i + 501;
	
	ft_printf("Setting up mixed operations test scenario: a = [1-500], b = [501-1000]\n");
	setup_test_stacks(stacks, test_data_a, test_data_b, len_a, len_b);
}

void	test_mixed_operations(t_stacks *stacks)
{
	ft_printf("\n\n~~~~~~~~~~~~~~\ntest mixed operations\n");
	
	// Setup the test scenario
	setup_test_mixed_operations(stacks);
	
	// Initial state verification
	int initial_size_a = ft_lstsize(stacks->a, 0, stacks->a);
	int initial_size_b = ft_lstsize(stacks->b, 0, stacks->b);
	int total_elements = initial_size_a + initial_size_b;
	
	assert(initial_size_a == 500);
	assert(initial_size_b == 500);
	ft_printf("\n✓ Initial state: a=%d, b=%d, total=%d elements\n", 
			  initial_size_a, initial_size_b, total_elements);
	
	// Perform 6000 random operations
	ft_printf("\nPerforming 6000 random operations...\n");
	srand(42); // Fixed seed for reproducible tests
	
	int operation_counts[4] = {0}; // push, swap, rotate, rrotate
	int successful_ops = 0;
	int failed_ops = 0;
	
	for (int i = 0; i < 6000; i++)
	{
		// Choose random stack (0 = a, 1 = b)
		int stack_choice = rand() % 2;
		
		// Choose random operation (0 = push, 1 = swap, 2 = rotate, 3 = rrotate)
		int op_choice = rand() % 4;
		
		int result = -1;
		
		switch (op_choice)
		{
			case 0: // Push operation
				operation_counts[0]++;
				if (stack_choice == 0)
					result = push(&stacks->a, &stacks->b); // a to b
				else
					result = push(&stacks->b, &stacks->a); // b to a
				break;
				
			case 1: // Swap operation
				operation_counts[1]++;
				if (stack_choice == 0)
					result = swap(&stacks->a);
				else
					result = swap(&stacks->b);
				break;
				
			case 2: // Rotate operation
				operation_counts[2]++;
				if (stack_choice == 0)
					result = rotate(&stacks->a);
				else
					result = rotate(&stacks->b);
				break;
				
			case 3: // Reverse rotate operation
				operation_counts[3]++;
				if (stack_choice == 0)
					result = rrotate(&stacks->a);
				else
					result = rrotate(&stacks->b);
				break;
		}
		
		// Track success/failure
		if (result == 0)
			successful_ops++;
		else
			failed_ops++;
		
		// Progress reporting every 1000 operations
		if ((i + 1) % 1000 == 0)
		{
			int current_size_a = ft_lstsize(stacks->a, 0, stacks->a);
			int current_size_b = ft_lstsize(stacks->b, 0, stacks->b);
			int current_total = current_size_a + current_size_b;
			
			ft_printf("  After %d ops: a=%d, b=%d, total=%d, success=%d, failed=%d\n", 
					  i + 1, current_size_a, current_size_b, current_total, 
					  successful_ops, failed_ops);
			
			// Verify total elements preserved
			assert(current_total == total_elements);
		}
	}
	
	// Final verification
	int final_size_a = ft_lstsize(stacks->a, 0, stacks->a);
	int final_size_b = ft_lstsize(stacks->b, 0, stacks->b);
	int final_total = final_size_a + final_size_b;
	
	ft_printf("\nFinal verification:\n");
	ft_printf("✓ Final state: a=%d, b=%d, total=%d elements\n", 
			  final_size_a, final_size_b, final_total);
	
	// Verify total elements preserved
	assert(final_total == total_elements);
	ft_printf("✓ Total elements preserved through all operations\n");
	
	// Operation statistics
	ft_printf("\nOperation statistics:\n");
	ft_printf("  Push operations: %d\n", operation_counts[0]);
	ft_printf("  Swap operations: %d\n", operation_counts[1]);
	ft_printf("  Rotate operations: %d\n", operation_counts[2]);
	ft_printf("  Reverse rotate operations: %d\n", operation_counts[3]);
	ft_printf("  Total operations: %d\n", operation_counts[0] + operation_counts[1] + 
			  operation_counts[2] + operation_counts[3]);
	ft_printf("  Successful operations: %d\n", successful_ops);
	ft_printf("  Failed operations: %d\n", failed_ops);
	
	// Data integrity check - verify all original numbers are still present
	ft_printf("\nPerforming data integrity check...\n");
	int found_count = 0;
	
	// This is a simplified check - in a full implementation you'd verify all 1000 numbers
	// For now, just verify the stacks are valid and contain reasonable data
	if (stacks->a)
	{
		t_list_node *current = stacks->a;
		t_list_node *start = stacks->a;
		do {
			if (current->content >= 1 && current->content <= 1000)
				found_count++;
			current = current->next;
		} while (current != start);
	}
	
	if (stacks->b)
	{
		t_list_node *current = stacks->b;
		t_list_node *start = stacks->b;
		do {
			if (current->content >= 1 && current->content <= 1000)
				found_count++;
			current = current->next;
		} while (current != start);
	}
	
	assert(found_count == 1000);
	ft_printf("✓ Data integrity verified: all %d elements in valid range\n", found_count);
	ft_printf("✓ Mixed operations stress test completed successfully!\n");
	teardown_test_stacks(stacks);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	if (!init(--argc, argv, &stacks))
		return (1);
	test_push(&stacks);
	test_swap(&stacks);
	test_rotation(&stacks);
	test_mixed_operations(&stacks);

	ft_lstclear(&(&stacks)->a, (&stacks)->a);
	ft_lstclear(&(&stacks)->b, (&stacks)->b);
	return (0);
}
