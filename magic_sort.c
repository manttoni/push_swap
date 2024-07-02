/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:30:07 by amaula            #+#    #+#             */
/*   Updated: 2024/07/01 19:54:36 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pusher(t_stack *a, t_stack *b, t_recorder *recorder)
{
	while (!is_ascending(a))
	{
		/*if (top(a, 0) > top(a, 1))
			if (operate("sa", a, b, recorder) == 0)
				return (0);
		if (is_ascending(a))
			break ;*/
		if (operate("pb", a, b, recorder) == 0)
			return (0);
	}
	return (1);
}

char	*get_operation2(int *rotations)
{
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
	return (get_operation2(rotations));
}

static int	align_push(t_stack *a, t_stack *b, int *rots, t_recorder *rec)
{
	while (rots[0] != 0 || rots[1] != 0)
		if (operate(get_operation(rots), a, b, rec) == 0)
			return (0);
	if (b->len != 0)
		if (operate("pa", a, b, rec) == 0)
			return (0);
	return (1);
}

int	magic_sort(t_stack *a, t_stack *b, t_recorder *recorder)
{
	int	rotations[2];

	rotations[0] = 0;
	rotations[1] = 0;
	if (pusher(a, b, recorder) == 0)
		return (0);
	while (b->len != 0 || top(a, 0) > top(a, -1))
	{
		least_rotations(a, b, rotations);
		if (align_push(a, b, rotations, recorder) == 0)
			return (0);
		if (!is_ascending(a))
			return (0);
	}
	return (1);
}
