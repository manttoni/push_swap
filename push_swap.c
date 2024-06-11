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

/* Compare top of stacks
 * Return
 * 0 if one is empty
 * + if a is bigger
 * - if b is bigger
 * Parameters
 * b = NULL if comparing top 2 of a */
int	compare(t_stack *a, t_stack *b)
{
	if (b == NULL)
		return (a->numbers[0] - a->numbers[1]);
	if (a->len == 0 || b->len == 0)
		return (0);

	return (a->numbers[0] - b->numbers[0]);
}

int	algo(t_stack *a, t_stack *b)
{
	int	ops;

	ops = 0;
	p(a, b);
	while (a->len != 0)
	{
		if (compare(a, NULL) > 0)
		{
			ops += swap(a);
			p(a, b);
		}
		while (compare(a, NULL) < 0 || a->len == 1)
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
			ft_printf("rotate:");
			p(a, b);
		}
		ops += push(b, a);
		ft_printf("push:");
		p(a, b);
		
		while (a->numbers[0] > a->numbers[a->len - 1] && b->numbers[0] < a->numbers[a->len - 1])
		{
			ops += rotate_reverse(a);
			ft_printf("rotate_reverse:");
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
	printf("Time: %f ms\n", 1000 * ((double)clock() / CLOCKS_PER_SEC));
}
