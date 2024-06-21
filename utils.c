/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:37:16 by amaula            #+#    #+#             */
/*   Updated: 2024/06/20 17:17:45 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	is_ascending(t_stack *stack)
{
	unsigned int	i;
	int		flag;

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
			
