#include "push_swap.h"
#include <time.h>
#include <stdio.h>

int	is_ascending(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len - 1)
	{
		if (stack->numbers[i] > stack->numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	algo(t_stack *a, t_stack *b)
{
	int	ops;

	ops = 0;
	p(a, b);
	while (a->len != 1)
	{
		if (a->numbers[0] > a->numbers[1])
		{
			ops += swap(a);
			if (b->numbers[0] < b->numbers[1])
				swap(b); //free swap (ss)
			p(a, b);
		}
		while (a->numbers[0] < a->numbers[1] && a->len > 1)
		{
			ops += push(a, b);
			p(a, b);
		}
	}
	ft_printf("--------------------------------------");
	while (b->len != 0)
	{
		while (a->numbers[0] < b->numbers[0] && a->len >= 2)
		{
			ops += rotate(a);
			p(a, b);
		}
		ops += push(b, a);
		p(a, b);
		while (a->numbers[0] > a->numbers[a->len - 1] && b->numbers[0] < a->numbers[a->len - 1])
		{
			ops += rotate_reverse(a);
			p(a, b);
		}
	}


	return (ops);
}

int	algo2(t_stack *a, t_stack *b)
{
	int	ops;
	int	max;

	max = INT_MIN;
	ops = 0;
	p(a, b);
	while (a->len != 1)
	{
		if(a->numbers[0] > max)
			max = a->numbers[0];
		ops += push(a, b);
		p(a, b);
	}
	while (b->numbers[0] != max && b->len > 1)
		ops += rotate(b);
	ft_printf("--------------------------------------");
	while (b->len != 0)
	{
		while (a->numbers[0] < b->numbers[0] && a->len >= 2)
		{
			ops += rotate(a);
			p(a, b);
		}
		ops += push(b, a);
		p(a, b);
		while (a->numbers[0] > a->numbers[a->len - 1] && b->numbers[0] < a->numbers[a->len - 1])
		{
			ops += rotate_reverse(a);
			p(a, b);
		}
	}


	return (ops);
}

void	push_swap(t_stack *a, t_stack *b)
{

	int	*array = malloc(a->len * sizeof(int));
	for (int i = 0; i < a->len; ++i)
		array[i] = a->numbers[i];
	t_stack	*copy = malloc(sizeof(t_stack));
	copy->numbers = array;
	copy->len = a->len;

	ft_printf("\nAlgo:");
	ft_printf("\n\tOps: %d\n", algo(a, b));
	pr(a, b);
	ft_printf("\nMerge:");
	ft_printf("\n\tOps: %d\n", iterative_merge_sort(copy, b));
	pr(copy, b);
	free(array);
	free(copy);
}
