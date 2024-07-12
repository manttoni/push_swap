/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:51:14 by amaula            #+#    #+#             */
/*   Updated: 2024/07/09 14:51:18 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	populate(t_stack *a, unsigned int max_stack, char **numbers)
{
	while (a->len < max_stack)
	{
		a->numbers[a->len] = ft_atoi(numbers[a->len]);
		a->len++;
	}
}

t_recorder	*push_swap(int len, char **numbers)
{
	t_stack		*a;
	t_stack		*b;
	t_recorder	*recorder;

	if (validate_input(len, numbers) == 0)
		return (NULL);
	recorder = init_recorder();
	if (!recorder)
		return (NULL);
	a = init_stack(len);
	if (!a)
	{
		free_recorder(recorder);
		return (NULL);
	}
	b = init_stack(len);
	if (!b)
	{
		free_recorder(recorder);
		free_stack(a);
		return (NULL);
	}
	populate(a, len, numbers);
	magic_sort(a, b, recorder);
	free_stack(a);
	free_stack(b);
	return (recorder);
}
