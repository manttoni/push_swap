#include "push_swap.h"
#include <time.h>
#include <stdio.h>

void	p(t_stack *a, t_stack *b)
{
	ft_printf("\n\ta:");
	for (int i = 0; i < a->len; ++i)
		ft_printf(" %d", a->numbers[i]);
	ft_printf("\n\tb:");
	for (int i = 0; i < b->len; ++i)
		ft_printf(" %d", b->numbers[i]);
	ft_printf("\n");
}

int	algo(t_stack *a, t_stack *b)
{
	int	ops;

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
		while (a->numbers[0] < b->numbers[0] && a->len >= 2)
		{
			ops += rotate(a);
			p(a, b);
		}
		ops += push(b, a);
		p(a, b);
		while (a->numbers[0] > a->numbers[a->len - 1] && b->numbers[0] < a->numbers[a->len - 1])
		{
			ops += rotate_reverse(a);
			p(a, b);
		}
	}


	return (ops);
}



void	push_swap(t_stack *a, t_stack *b)
{
	int	ops;

	ops = algo(a, b);
	ft_printf("\nOps: %d\n", ops);
	printf("Time: %g ms\n", 1000 * ((double)clock() / CLOCKS_PER_SEC));
}
