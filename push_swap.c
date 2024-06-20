#include "push_swap.h"
#include <time.h>
#include <stdio.h>

void	run_and_print(t_stack *a, 
		t_stack *b, 
		int (*f)(t_stack *a, t_stack *b))
{
	t_stack	*copy = malloc(sizeof(t_stack));
	int	*numbers_copy = malloc(a->len * sizeof(int));
	copy->numbers = numbers_copy;
	copy->len = a->len;
	for(unsigned int i = 0; i < a->len; ++i)
		numbers_copy[i] = a->numbers[i];
	ft_printf("\n\tOps: %d\n", f(copy, b));
	if (is_ascending(copy))
		ft_printf("\nPASS\n");
	else 
		ft_printf("\nNOT ASCENDING\n");
	free(numbers_copy);
	free(copy);
	if (b->len != 0)
		ft_printf("\nFAIL\n");
}


void	push_swap(t_stack *a, t_stack *b)
{
	run_and_print(a, b, magic_sort);
}

