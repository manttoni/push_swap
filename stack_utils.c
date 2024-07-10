/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:19:19 by amaula            #+#    #+#             */
/*   Updated: 2024/07/10 15:52:47 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(t_stack *stack, int stack_max)
{
	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->len = 0;
	stack->numbers = malloc(stack_max * sizeof(int));
	if (!stack->numbers)
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}

int	top(t_stack *stack, int index)
{
	if (index < 0)
		return (stack->numbers[index + stack->len]);
	return (stack->numbers[index % stack->len]);
}

unsigned int	absolute(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int	stack_max(t_stack *stack)
{
	int				max;
	unsigned int	i;

	i = 0;
	max = INT_MIN;
	while (i < stack->len)
	{
		if (top(stack, i) > max)
			max = top(stack, i);
		i++;
	}
	return (max);
}

int	stack_min(t_stack *stack)
{
	int				min;
	unsigned int	i;

	i = 0;
	min = INT_MAX;
	while (i < stack->len)
	{
		if (top(stack, i) < min)
			min = top(stack, i);
		i++;
	}
	return (min);
}
