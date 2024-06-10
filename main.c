#include "push_swap.h"

static int	validate_int(char *s)
{
	int	len;

	len = 0;
	if (*s == '-')
		s++;
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			s++;
		else
			return (0);
		len++;
	}
	return (len <= 10);
}

void	free_everything(t_stack *a, t_stack *b)
{
	free(a->numbers);
	free(b->numbers);
	free(a);
	free(b);
}

int	main(int argc, char **argv)
{
	int	i;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
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
		if (!validate_int(argv[i + 1]))
		{
			free_everything(a, b);
			return (1);
		}
		a->numbers[i] = ft_atoi(argv[i + 1]);
		a->len++;
		i++;
	}
	push_swap(a, b);
	free_everything(a, b);
	return (0);
}
