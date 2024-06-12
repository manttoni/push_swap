#include "push_swap.h"

static int	top(t_stack *stack, int index)
{
	if (index == -1)
		return (stack->numbers[stack->len - 1]);
	return (stack->numbers[index]);
}

static int	find_spot(t_stack *a, t_stack *b)
{
	int	i;
	int	ops;

	ops = 0;
	i = 1;
	while (i < a->len)
	{
		if (top(a, i) > top(b, 0) && top(a, i - 1) < top(b, 0))
		{
			while (i > 0)
			{
				ops += rotate(a);
				ft_printf("rotate");
				p(a, b);
				i--;
			}
			return (ops);
		}
		i++;
	}
	while (top(a, 0) > top(a, -1) && top(b, 0) < top(a, -1))
	{
		ops += rotate_reverse(a);
		ft_printf("reverse");
		p(a, b);
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
                        ft_printf("swap");
                        p(a, b);
                }
                while (a->numbers[0] < a->numbers[1] && a->len > 1)
                {
                        ops += push(a, b);
                        ft_printf("push");
                        p(a, b);
                }
        }
        ft_printf("--------------------------------------");
        while (b->len != 0)
        {
		ops += find_spot(a, b);
                ops += push(b, a);
                ft_printf("push");
                p(a, b);
        }


        return (ops);
}
