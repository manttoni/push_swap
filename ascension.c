/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:37:52 by amaula            #+#    #+#             */
/*   Updated: 2024/07/09 14:52:36 by amaula           ###   ########.fr       */
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
