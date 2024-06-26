#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b, t_recorder *recorder)
{
	if (magic_sort(a, b, recorder) == 0)
		ft_printf("Error");
	for (unsigned int i = 0; i < recorder->len; i++)
		ft_printf("%s\n", recorder->operations[i]);
	ft_printf("\n\nOps: %u\n", recorder->len);
	for (unsigned int i = 0; i < a->len; i++)
		ft_printf("%d ", a->numbers[i]);
	ft_printf("\n");
}

