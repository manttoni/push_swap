#include "push_swap.h"

static int	merge(t_stack *a, t_stack *b, int size)
{
	int	mid;
	int	ops;

	ops = 0;
	mid = size / 2;
	while (mid > 0)
	{
		ops += push(a, b);
		p(a, b);
		mid--;
		size--;
	}
	while (size > 0)
	{
		while (b->numbers[0] < b->numbers[b->len - 1] && b->len >= 2)
		{
			ops += rotate_reverse(b);
			ft_printf("reverse");
			p(a, b);
		}
		if (b->numbers[b->len - 1] > a->numbers[0])
		{
			ops += push(a, b);
			size--;
			p(a, b);
			continue ;
		}
		while (b->numbers[0] > a->numbers[0] && b->len >= 2)
		{
			ops += rotate(b);
			ft_printf("rotate");
			p(a, b);
		}
		ops += push(a, b);
		size--;
		p(a, b);
	}
	while (b->numbers[0] < b->numbers[b->len - 1])
	{
		ops += rotate_reverse(b);
		p(a, b);
	}
	while (b->len != 0)
	{
		ops += push(b, a);
		p(a, b);
	}
	return (ops);
}

int	iterative_merge_sort(t_stack *a, t_stack *b)
{
	int	size;
	int	ops;
	int	iterated;
	int	rotator;

	ops = 0;
	size = 2;
	p(a, b);
	while (size <= a->len)
	{
		iterated = 0;
		while (iterated + size <= a->len)
		{
			ops += merge(a, b, size);
			iterated += size;
			rotator = size;
			while (rotator > 0 && rotator != a->len)
			{
				ops += rotate(a);
				p(a, b);
				rotator--;
			}
		}
		rotator = a->len - iterated;
		while (rotator > 0)
		{
			ops += rotate(a);
			p(a, b);
			rotator--;
		}
		size *= 2;
	}
	return (ops);
}
