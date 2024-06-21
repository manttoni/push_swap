#include "push_swap.h"

static void	print(t_stack *a, t_stack *b)
{
	ft_printf("\na: ");
	for (unsigned int i = 0; i < a->len; ++i)
		ft_printf("%d ", top(a, i));
	ft_printf("\nb: ");
	for (unsigned int i = 0; i < b->len; ++i)
		ft_printf("%d ", top(b, i));
	ft_printf("\n");
}

/* Calculate least rotations to be able to push from b to a so that it stays sorted
 * If b is empty, calculate least rotations to have smallest number at first index */
static void	least_rotations(t_stack *a, t_stack *b, int *rotations)
{
	int	i;
	int	j;
	unsigned int	least;

	least = UINT_MAX;
	i = -1 * (long)a->len / 2;
	while (i < (long)a->len / 2)
	{
		j = -1 * (long)b->len / 2;
		while (j <= (long)(b->len / 2))
		{
			if (b->len == 0 && top(a, i) < top(a, i - 1))
			{
				if (least > absolute(i))
				{
					least = absolute(i);
					rotations[0] = i;
					rotations[1] = 0;
				}
			}
			else if (b->len != 0 && top(a, i) > top(b, j) && (top(a, i - 1) < top(b, j) || top(a, i) < top(a, i - 1)))
			{
				if (least > absolute(i) + absolute(j))
				{
					least = absolute(i) + absolute(j);
					rotations[0] = i;
					rotations[1] = j;
				}
			}
			j++;
		}
		i++;
	}
}

/* Push from a to b so that the biggest number stays in a
 * If a is in ascending order (circular), move to next step */
static int	pusher(t_stack *a, t_stack *b)
{
	int	ops;

	ops = 0;
	while (!is_ascending(a))
	{
		if (top(a, 0) > top(a, 1))
		{
			ops += swap(a);
			print(a, b);
		}
		if (is_ascending(a))
			break;
		while (top(a, 0) < top(a, 1) && a->len > 1)
		{
			ops += push(a, b);
			print(a, b);
		}
	}
	return (ops);
}

/* Rotate stacks, one rotation per stack at a time */
static int	do_rotations(t_stack *a, t_stack *b, int *rotations)
{
	int	ops;

	ops = 0;
	while (rotations[0] != 0 || rotations[1] != 0)
	{
		if (rotations[0] < 0)
		{
			ops += rotate_reverse(a);
			rotations[0]++;
			print(a, b);
		}
		else if (rotations[0] > 0)
		{
			ops += rotate(a);
			rotations[0]--;
			print(a, b);
		}
		if (rotations[1] < 0)
		{
			ops += rotate_reverse(b);
			rotations[1]++;
			print(a, b);
		}
		else if (rotations[1] > 0)
		{
			ops += rotate(b);
			rotations[1]--;
			print(a, b);
		}
	}
	return (ops);
}

/* Push numbers to b until a is sorted, then push from b without breaking sortedness
 * Can sort 100 ints in less than 800 operations */
int     magic_sort(t_stack *a, t_stack *b)
{
	int	ops;
	int	rotations[2];

	rotations[0] = 0;
	rotations[1] = 0;
	ops = pusher(a, b);
	while (b->len != 0)
	{
		least_rotations(a, b, rotations);
		ops += do_rotations(a, b, rotations);
		ops += push(b, a);
		print(a, b);
	}
	least_rotations(a, b, rotations);
	ops += do_rotations(a, b, rotations);
	return (ops);
}
