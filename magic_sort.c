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
static void	least_rotations(t_stack *a, t_stack *b, int *rotations)
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
			if (b->len == 0 && top(a, i) < top(a, i - 1))
			{
				if (least > absolute(i))
				{
					least = absolute(i);
					rotations[0] = i;
					rotations[1] = 0;
				}
			}
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
			{
                                swap(b); //free swap (ss)
				ft_printf("ss\n");
			}
			else
				ft_printf("sa\n");
                }
                while (top(a, 0) < top(a, 1) && a->len > 1)
                {
                        ops += push(a, b);
                        ft_printf("pb\n");
                }
        }
	return (ops);
}

static int	do_rotations(t_stack *a, t_stack *b, int *rotations)
{
	int	ops;

	ops = 0;
	while (rotations[0] != 0 || rotations[1] != 0)
	{
		ft_printf("rotations 0 = %d 1 = %d\n", rotations[0], rotations[1]);
		if (rotations[0] < 0)
		{
			ops += rotate_reverse(a);
			rotations[0]++;
			ft_printf("rra\n");
		}
		else if (rotations[0] > 0)
		{
			ops += rotate(a);
			rotations[0]--;
			ft_printf("ra\n");
		}
		if (rotations[1] < 0)
		{
			ops += rotate_reverse(b);
			rotations[1]++;
			ft_printf("rrb\n");
		}
		else if (rotations[1] > 0)
		{
			ops += rotate(b);
			rotations[1]--;
			ft_printf("rb\n");
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
		ft_printf("pa\n");
		least_rotations(a, b, rotations);
		ops += do_rotations(a, b, rotations);
	}
	least_rotations(a, b, rotations);
	ops += do_rotations(a, b, rotations);
	return (ops);
}
