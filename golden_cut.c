/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   golden_cut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:52:46 by amaula            #+#    #+#             */
/*   Updated: 2024/07/10 15:22:35 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned int	get_index(t_stack *stack)
{
	unsigned int	index;
	unsigned int	i;

	i = 0;
	index = 0;
	while (i < stack->len)
	{
		if (top(stack, i) < top(stack, 0))
			index++;
		i++;
	}
	return (index);
}

int	golden_cut(t_stack *stack)
{
	int				cut;
	unsigned int	index;

	cut = 38;
	index = get_index(stack);
	return (index < cut * stack->len / 100);
}
