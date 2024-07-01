/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:37:52 by amaula            #+#    #+#             */
/*   Updated: 2024/07/01 18:34:15 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ascending(t_stack *stack)
{
	unsigned int	i;
	int				flag;

	flag = 0;
	i = 0;
	while (i < stack->len)
	{
		if (top(stack, i) > top(stack, i + 1))
		{
			if (flag == 1)
				return (0);
			else
				flag = 1;
		}
		i++;
	}
	return (1);
}

int	get_next_unsorted(t_stack *a)
{
	int				i;
	unsigned int	least_rotations;
	int				ret;

	ret = 0;
	least_rotations = UINT_MAX;
	i = -1 * (long)a->len / 2;
	while (i < (long)a->len / 2)
	{
		if (top(a, i) > top(a, i + 1))
			if (least_rotations > absolute(i))
			{
				least_rotations = absolute(i);
				ret = i;
			}
		i++;
	}
	return (ret);
}
