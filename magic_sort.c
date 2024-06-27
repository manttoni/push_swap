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

char	*get_operation(int *rotations)
{
	if (rotations[0] * rotations[1] > 0)
	{
		if (rotations[0] > 0)
		{
			rotations[0]--;
			rotations[1]--;
			return ("rr");
		}
		else
		{
			rotations[0]++;
			rotations[1]++;
			return ("rrr");
		}
	}
	if (rotations[0] > 0)
	{
		rotations[0]--;
		return ("ra");
	}
	else if (rotations[0] < 0)
	{
		rotations[0]++;
		return ("rra");
	}
	if (rotations[1] > 0)
	{
		rotations[1]--;
		return ("rb");
	}
	else if (rotations[1] < 0)
	{
		rotations[1]++;
		return ("rrb");
	}
	return (NULL);
}

/* Rotate stacks, one rotation per stack at a time */
static int	do_rotations_push(t_stack *a, t_stack *b, int *rotations, t_recorder *recorder)
{
	while (rotations[0] != 0 || rotations[1] != 0)
		if (operate(get_operation(rotations), a, b, recorder) == 0)
			return (0);
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
