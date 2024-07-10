/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:53:55 by amaula            #+#    #+#             */
/*   Updated: 2024/07/10 16:08:03 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_aligned(t_stack *a, t_stack *b, int i, int j)
{
	if (b->len == 0)
	{
		if (top(a, i) < top(a, i - 1))
			return (1);
		return (0);
	}
	if (top(b, j) < top(a, i) && top(b, j) > top(a, i - 1))
		return (1);
	if (top(b, j) < top(a, i) && top(a, i - 1) == stack_max(a))
		return (1);
	if (top(b, j) > top(a, i - 1) && top(a, i) == stack_min(a))
		return (1);
	return (0);
}

static unsigned int	get_rotations(int i, int j)
{
	unsigned int	greater;

	if (i * j > 0)
	{
		greater = absolute(i);
		if (absolute(j) > absolute(i))
			greater = absolute(j);
		return (greater);
	}
	return (absolute(i) + absolute(j));
}

void	least_rotations(t_stack *a, t_stack *b, int *rotations)
{
	int				i;
	int				j;
	unsigned int	least;

	least = UINT_MAX;
	i = -1 * (long)a->len / 2;
	while (i <= (long)a->len / 2)
	{
		j = -1 * (long)b->len / 2;
		while (j <= (long)(b->len / 2))
		{
			if (get_rotations(i, j) < least && is_aligned(a, b, i, j))
			{
				least = get_rotations(i, j);
				rotations[0] = i;
				rotations[1] = j;
			}
			j++;
		}
		i++;
	}
}
