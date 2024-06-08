#include "push_swap.h"

static int	ft_atoi(char *s)
{
	long	ret;
	int	sign;

	sign = 1;
	ret = 0;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (*s)
	{
		ret *= 10;
		ret += *s++ - '0';
	}
	return (sign * ret);
}

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

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	i;

	i = 0;
	if (argc < 2)
		return (1);
	stack_a = malloc((argc - 1) * sizeof(int));
	stack_b = malloc((argc - 1) * sizeof(int));
	while (i < argc - 1)
	{
		if (!validate(*argv))
			return (1);
		stack_a[i++] = ft_atoi(*(++argv));
	}
	push_swap(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
