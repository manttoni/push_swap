#include "push_swap.h"

int	stack_max(t_stack *stack)
{
	int				max;
	unsigned int	i;

	i = 0;
	max = INT_MIN;
	while (i < stack->len)
	{
		if (top(stack, i) > max)
			max = top(stack, i);
		i++;
	}
	return (max);
}

int	stack_min(t_stack *stack)
{
	int				min;
	unsigned int	i;

	i = 0;
	min = INT_MAX;
	while (i < stack->len)
	{
		if (top(stack, i) < min)
			min = top(stack, i);
		i++;
	}
	return (min);
}

static int	is_aligned(t_stack *a, t_stack *b, int i, int j)
{
	if (top(b, j) < top(a, i) && top(b, j) > top(a, i - 1))
		return (1);
	if (top(b, j) < top(a, i) && top(a, i - 1) == stack_max(a))
		return (1);
	if (top(b, j) > top(a, i - 1) && top(a, i) == stack_min(a))
		return (1);
	return (0);
}

static void	update_rotations(int *rotations, int i, int j, unsigned int *least)
{
	int				same_sign;
	unsigned int	greater;

	greater = absolute(i);
	if (absolute(j) > absolute(i))
		greater = absolute(j);
	same_sign = rotations[0] < 0 && rotations[1] < 0;
	same_sign = same_sign || (rotations[0] > 0 && rotations[1] > 0);
	if (same_sign && *least > greater)
	{
		*least = greater;
		rotations[0] = i;
		rotations[1] = j;
	}
	else if (*least > absolute(i) + absolute(j))
	{
		*least = absolute(i) + absolute(j);
		rotations[0] = i;
		rotations[1] = j;
	}
}

void	least_rotations(t_stack *a, t_stack *b, int *rotations)
{
	int	i;
	int	j;
	unsigned int	least;

	least = UINT_MAX;
	i = -1 * (long)a->len / 2;
	while (i <= (long)a->len / 2)
	{
		j = -1 * (long)b->len / 2;
		while (j <= (long)(b->len / 2))
		{
			if (b->len == 0 && top(a, i) < top(a, i - 1))
				update_rotations(rotations, i, 0, &least);
			else if (b->len != 0 && is_aligned(a, b, i, j))
				update_rotations(rotations, i, j, &least);
			j++;
		}
		i++;
	}
}

