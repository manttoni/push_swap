#include "push_swap.h"

static int	is_aligned(t_stack *a, t_stack *b, int i, int j)
{
	return (top(a, i) > top(b, j) && (top(a, i - 1) < top(b, j) || top(a, i) < top(a, i - 1)));
}

static void	update_rotations(int *rotations, int i, int j, unsigned int *least)
{
	int				same_sign;
	unsigned int	greater;

	greater = absolute(i);
	if (absolute(j) > absolute(i))
		greater = absolute(j);
	same_sign = (rotations[0] < 0 && rotations[1] < 0) || (rotations[0] > 0 && rotations[1] > 0);
	if (same_sign && *least > greater)
	{
		*least = greater;
		rotations[0] = i;
		rotations[1] = j;
	}
	else if (*least > absolute(i) + absolute(j))
	{
		*least = absolute(i) + absolute(j);
		rotations[0] = i;
		rotations[1] = j;
	}
}

/* Calculate least rotations to be able to push from b to a so that it stays sorted
 * If b is empty, calculate least rotations to have smallest number at first index */
void	least_rotations(t_stack *a, t_stack *b, int *rotations)
{
	int	i;
	int	j;
	unsigned int	least;

	least = UINT_MAX;
	i = -1 * (long)a->len / 2;
	while (i <= (long)a->len / 2)
	{
		j = -1 * (long)b->len / 2;
		while (j <= (long)(b->len / 2))
		{
			if (b->len == 0 && top(a, i) < top(a, i - 1))
				update_rotations(rotations, i, 0, &least);
			else if (b->len != 0 && is_aligned(a, b, i, j))
				update_rotations(rotations, i, j, &least);
			j++;
		}
		i++;
	}
}

