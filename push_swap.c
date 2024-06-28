#include "push_swap.h"

static void	print_operations(t_recorder *recorder)
{
	unsigned int	i;

	i = 0;
	while (i < recorder->len)
	{
		ft_printf("%s\n", recorder->operations[i]);
		i++;
	}
	ft_printf("OPS: %u\n", recorder->len);
}

static void	free_everything(t_recorder *recorder, t_stack *a, t_stack *b)
{
	unsigned int	i;

	i = 0;
	while (i < recorder->len)
	{
		free(recorder->operations[i]);
		i++;
	}
	free(recorder->operations);
	free(recorder);
	free(a->numbers);
	free(a);
	free(b->numbers);
	free(b);
}

static int	finish(t_recorder *recorder, t_stack *a, t_stack *b, int rvalue)
{
	if (rvalue != 0)
		ft_printf("Error\n");
	if (rvalue == 0)
		print_operations(recorder);
	if (rvalue != 2)
		free_everything(recorder, a, b);
	return (rvalue);
}

static void	populate(t_stack *a, unsigned int max_stack, char **numbers)
{
	while (a->len < max_stack)
	{
		a->numbers[a->len] = ft_atoi(numbers[a->len]);
		a->len++;
	}
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack 	*b;
	t_recorder	*recorder;

	a = NULL;
	b = NULL;
	recorder = NULL;
	if (validate_input(argc, argv) == 0)
		return (finish(NULL, NULL, NULL,  2));
	recorder = init_recorder(recorder);
	a = init_stack(a, argc - 1);
	b = init_stack(b, argc - 1);
	if (!recorder || !a || !b)
		return (finish(recorder, a, b, 1));
	populate(a, argc - 1, ++argv);
	if (magic_sort(a, b, recorder) == 0)
		return (finish(recorder, a, b, 1));
	return (finish(recorder, a, b, 0));
}
