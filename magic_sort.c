#include "push_swap.h"

static int	top(t_stack *stack, int index)
{
	if (index < 0)
		return (stack->numbers[stack->len + index]);
	return (stack->numbers[index]);
}
static unsigned int	absolute(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}
static void	*least_rotations(t_stack *a, t_stack *b, int *rotations)
{
	int		i;
	int		j;
	unsigned int	least;

	least = UINT_MAX;
	i = -1 * a->len / 2;
	while (i < a->len / 2)
	{
		j = -1 * b->len / 2;
		while (j <= b->len / 2)
		{
			if (top(a, i) > top(b, j)
			&& (top(a, i - 1) < top(b, j)
			|| top(a, i) < top(a, i - 1)))
				if (least > absolute(i) + absolute(j))
				{
					least = absolute(i) + absolute(j);
					rotations[0] = i;
					rotations[1] = j;
				}
			j++;
		}
		i++;
	}
}

static int	pusher(t_stack *a, t_stack *b)
{
	int	ops;

	ops = 0;
	while (a->len != 1)
        {
                if (top(a, 0) > top(a, 1))
                {
                        ops += swap(a);
                        if (top(b, 0) < top(b, 1))
                                swap(b); //free swap (ss)
                        p(a, b);
                }
                while (top(a, 0) < top(a, 1) && a->len > 1)
                {
                        ops += push(a, b);
                        p(a, b);
                }
        }
	return (ops);
}

static int	do_rotations(t_stack *stack, int rots)
{
	int	ops;

	ops = 0;
	while (rots != 0)
	{
		while (rots < 0)
		{
			ops += rotate_reverse(stack);
			rots++;
		}
		while (rots > 0)
		{
			ops += rotate(stack);
			rots--;
		}
	}
	return (ops);
}


int     magic_sort(t_stack *a, t_stack *b)
{
        int     ops;
	int	rotations[2];

        ops = pusher(a, b);
	while (b->len > 0)
	{
		ops += push(b, a);
		least_rotations(a, b, rotations);
		ops += do_rotations(a, rotations[0]) + do_rotations(b, rotations[1]);
	}
	while (top(a, 0) > top(a, -1))
		ops += rotate_reverse(a);
	//while (top(a, 0) < top(a, -1))
	//	ops += rotate(a);
	return (ops);
}
