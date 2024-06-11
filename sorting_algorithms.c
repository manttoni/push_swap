#include "push_swap.h"

int	insertion_sort(t_stack *stack, t_stack *tmp_stack)
{
	int	i;
	int	ops;

	i = 0;
	ops = 0;
	while (i < stack->len)
	{
		while (stack->numbers[1] < stack->numbers[0])
			ops += swap(stack) + rotate_reverse(stack);
		while (stack->numbers[1] > stack->numbers[0])
			ops += push(stack, tmp_stack);
