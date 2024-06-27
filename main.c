#include "push_swap.h"
void	free_everything(t_stack *a, t_stack *b, t_recorder *recorder)
{
	free(a->numbers);
	free(b->numbers);
	free(a);
	free(b);
	while (recorder->len-- > 0)
		free(recorder->operations[recorder->len]);
	free(recorder);
}

int	main(int argc, char **argv)
{
	int	i;
	t_stack	*a;
	t_stack	*b;
	t_recorder *recorder;

	if (argc < 2)
		return (1);
	recorder = init_recorder();
	if (recorder == NULL)
		return (1);
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	a->len = 0;
	b->len = 0;
	a->numbers = malloc((argc - 1) * sizeof(int));
	b->numbers = malloc((argc - 1) * sizeof(int));
	i = 0;
	while (i < argc - 1)
	{
		if (!validate_int(argv[i + 1]) || 
			contains(ft_atoi(argv[i + 1]), a->numbers, a->len))
		{
			ft_printf("Error\n");
			free_everything(a, b, recorder);
			return (1);
		}
		a->numbers[i] = ft_atoi(argv[i + 1]);
		a->len++;
		i++;
	}
	push_swap(a, b, recorder);
	free_everything(a, b, recorder);
	return (0);
}
