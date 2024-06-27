#include "push_swap.h"

static int	is_integer(char *str)
{
	long	res;

	res = ft_strtol(str);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	if (res > INT_MAX || res < INT_MIN)
		return (0);
	return (1);
}

static int	all_unique(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < argc)
	{
		while (i + j < argc)
		{
			if (ft_strncmp(argv[i], argv[i + j], 12) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_input(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!is_integer(argv[i]))
			return (0);
		i++;
	}
	return (all_unique(argc, argv));
}
