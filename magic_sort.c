#include "push_swap.h"

/* Push from a to b so that the biggest number stays in a
 * If a is in ascending order (circular), move to next step */
static int	pusher(t_stack *a, t_stack *b, t_recorder *recorder)
{
	while (!is_ascending(a))
	{
		if (top(a, 0) > top(a, 1))
			if (operate("sa", a, b, recorder) == 0)
				return (0);
		if (is_ascending(a))
			break;
		while (top(a, 0) < top(a, 1) && a->len > 1)
			if (operate("pb", a, b, recorder) == 0)
				return (0);
	}
	return (1);
}

/* Rotate stacks, one rotation per stack at a time */
static int	do_rotations_push(t_stack *a, t_stack *b, int *rotations, t_recorder *recorder)
{
	char	*a_operation;
	char	*b_operation;

	while (rotations[0] != 0 || rotations[1] != 0)
	{
		a_operation = NULL;
		b_operation = NULL;
		if (rotations[0] < 0)
		{
			a_operation = "rra";
			rotations[0]++;
		}
		else if (rotations[0] > 0)
		{
			a_operation = "ra";
			rotations[0]--;
		}
		if (a_operation && operate(a_operation, a, b, recorder) == 0)
			return (0);
		if (rotations[1] < 0)
		{
			b_operation = "rrb";
			rotations[1]++;
		}
		else if (rotations[1] > 0)
		{
			b_operation = "rb";
			rotations[1]--;
		}
		if (b_operation && operate(b_operation, a, b, recorder) == 0)
			return (0);
	}
	if (b->len != 0)
		if (operate("pa", a, b, recorder) == 0)
			return (0);
	return (1);
}

/* Push numbers to b until a is sorted, then push from b without breaking sortedness
 * Can sort 100 ints in less than 800 operations */
int     magic_sort(t_stack *a, t_stack *b, t_recorder *recorder)
{
	int	rotations[2];

	rotations[0] = 0;
	rotations[1] = 0;
	if (pusher(a, b, recorder) == 0)
		return (0);
	while (b->len != 0 || top(a, 0) > top(a, -1))
	{
		least_rotations(a, b, rotations);
		if (do_rotations_push(a, b, rotations, recorder) == 0)
			return (0);
		if (!is_ascending(a))
			return(0);
	}
	return (1);
}
