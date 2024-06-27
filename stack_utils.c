#include "push_swap.h"

t_stack	*init_stack(t_stack *stack, int stack_max)
{
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->len = 0;
	stack->numbers = malloc(stack_max * sizeof(int));
	if (!stack->numbers)
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}

int	top(t_stack *stack, int index)
{
	if (index < 0)
		return (stack->numbers[index + stack->len]);
	return (stack->numbers[index % stack->len]);
}

unsigned int	absolute(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int	is_ascending(t_stack *stack)
{
	unsigned int	i;
	int		flag;

	flag = 0;
	i = 0;
	while (i < stack->len)
	{
		if (top(stack, i) > top(stack, i + 1))
		{
			if (flag == 1)
				return (0);
			else
				flag = 1;
		}
		i++;
	}
	return (1);
}
