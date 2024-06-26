#include "push_swap.h"

void	print(t_stack *a, t_stack *b)
{
	ft_printf("\na: ");
	for(unsigned int i = 0; i < a->len; i++)
		ft_printf("%d ", top(a, i));
	ft_printf("\nb: ");
	for(unsigned int i = 0; i < b->len; i++)
		ft_printf("%d ", top(b, i));
	ft_printf("\n");
}

int	operate(char *operation, t_stack *a, t_stack *b, t_recorder *recorder)
{
	int	op_success;

	op_success = 0;
	if (ft_strncmp(operation, "sa", 2) == 0)
		op_success = swap(a);
	else if (ft_strncmp(operation, "sb", 2) == 0)
		op_success = swap(b);
	else if (ft_strncmp(operation, "ss", 2) == 0 && a->len > 1 && b->len > 1)
		op_success = swap(a) * swap(b);
	else if (ft_strncmp(operation, "pa", 2) == 0)
		op_success = push(b, a);
	else if (ft_strncmp(operation, "pb", 2) == 0)
		op_success = push(a, b);
	else if (ft_strncmp(operation, "ra", 2) == 0)
		op_success = rotate(a);
	else if (ft_strncmp(operation, "rb", 2) == 0)
		op_success = rotate(b);
	else if (ft_strncmp(operation, "rr", 2) == 0 && ft_strlen(operation) == 2)
		op_success = rotate(a) * rotate(b);
	else if (ft_strncmp(operation, "rra", 3) == 0)
		op_success = rotate_reverse(a);
	else if (ft_strncmp(operation, "rrb", 3) == 0)
		op_success = rotate_reverse(b);
	else if (ft_strncmp(operation, "rrr", 3) == 0)
		op_success = rotate_reverse(a) * rotate_reverse(b);
	if (op_success)
		if (record(recorder, operation) == 0)
			return (0);
	return (1);
}

