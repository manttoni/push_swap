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

int	get_lesser(t_stack *a)
{
	int		lesser;
	unsigned int	i;

	lesser = INT_MIN;
	i = 0;
	while (i < a->len)
	{
		if (top(a, i) < top(a, 0) && top(a, i) > lesser)
			lesser = top(a, i);
		i++;
	}
	return (lesser);
}

int	get_greater(t_stack *b)
{
	int		greater;
	unsigned int	i;

	greater = INT_MAX;
	i = 0;
	while (i < b->len)
	{
		if (top(b, i) > top(b, 0) && top(b, i) < greater)
			greater = top(b, i);
		i++;
	}
	return (greater);
}
