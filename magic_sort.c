#include "push_swap.h"

static int	top(t_stack *stack, int index)
{
	if (index == -1)
		return (stack->numbers[stack->len - 1]);
	return (stack->numbers[index]);
}

static int	find_spot(t_stack *a, long b_num)
{
	int	i;
	int	ops;

	ops = 0;
	i = 0;
	while (i < a->len)
	{
		if (b_num < (long)top(a, i))
		{
			if (b_num > (long)top(a, i - 1))
				break;
			if (top(a, i) < top(a, i - 1))
				break ;
		}
		i++;
	}
	while (i > 0 && i <= a->len / 2)
	{
		ops += rotate(a);
		i--;
	}
	while (a->len - i > 0 && i != 0)
	{
		ops += rotate_reverse(a);
		i++;
	}
	return (ops);
}

int     magic_sort(t_stack *a, t_stack *b)
{
        int     ops;

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
		if (a->len > 1)
			ops += find_spot(a, top(b, 0));
                ops += push(b, a);
                p(a, b);
        }
	ops += find_spot(a, LONG_MIN);
	return (ops);
}
