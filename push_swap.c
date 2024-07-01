#include "push_swap.h"

static t_recorder	*finish(t_stack *a, t_stack *b, t_recorder *recorder)
{
	if (a)
	{
		free(a->numbers);
		free(a);
	}
	if (b)
	{
		free(b->numbers);
		free(b);
	}
	return (recorder);
}

static void	populate(t_stack *a, unsigned int max_stack, char **numbers)
{
	while (a->len < max_stack)
	{
		a->numbers[a->len] = ft_atoi(numbers[a->len]);
		a->len++;
	}
}

t_recorder	*push_swap(int argc, char **argv)
{
	t_stack		*a;
	t_stack 	*b;
	t_recorder	*recorder;

	a = NULL;
	b = NULL;
	recorder = NULL;
	if (validate_input(argc, argv) == 0)
		return (finish(a, b, recorder));
	recorder = init_recorder(recorder);
	a = init_stack(a, argc - 1);
	b = init_stack(b, argc - 1);
	if (!recorder || !a || !b)
		return (finish(a, b, recorder));
	populate(a, argc - 1, argv + 1);
	magic_sort(a, b, recorder);
	return (finish(a, b, recorder));
}
