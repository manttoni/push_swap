/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:18:28 by amaula            #+#    #+#             */
/*   Updated: 2024/07/09 14:50:04 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define RIGHT 1
#define LEFT -1

static void	shift(t_stack *stack, int direction)
{
	unsigned int	i;

	if (stack->len == 0)
		return ;
	if (direction == RIGHT)
	{
		i = stack->len - 1;
		while (i > 0)
		{
			stack->numbers[i] = stack->numbers[i - 1];
			i--;
		}
	}
	else if (direction == LEFT)
	{
		i = 0;
		while (i < stack->len - 1)
		{
			stack->numbers[i] = stack->numbers[i + 1];
			i++;
		}
	}
}

int	swap(t_stack *stack)
{
	int	tmp;
	int	*numbers;

	if (stack->len < 2)
		return (0);
	numbers = stack->numbers;
	tmp = numbers[0];
	numbers[0] = numbers[1];
	numbers[1] = tmp;
	return (1);
}

int	push(t_stack *from, t_stack *to)
{
	if (from->len == 0)
		return (0);
	to->len++;
	shift(to, RIGHT);
	to->numbers[0] = from->numbers[0];
	shift(from, LEFT);
	from->len--;
	return (1);
}

int	rotate(t_stack *stack)
{
	int	first;

	if (stack->len <= 1)
		return (0);
	first = stack->numbers[0];
	shift(stack, LEFT);
	stack->numbers[stack->len - 1] = first;
	return (1);
}

int	rotate_reverse(t_stack *stack)
{
	int	last;

	if (stack->len <= 1)
		return (0);
	last = stack->numbers[stack->len - 1];
	shift(stack, RIGHT);
	stack->numbers[0] = last;
	return (1);
}
