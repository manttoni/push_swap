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

static void	free_all(t_recorder *r, t_stack *a, t_stack *b)
{
	if (r)
		free_recorder(r);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
}

t_recorder	*push_swap(int len, char **numbers)
{
	t_stack		*a;
	t_stack		*b;
	t_recorder	*recorder;

	if (validate_input(len, numbers) == 0)
		return (NULL);
	recorder = init_recorder();
	a = init_stack(len);
	b = init_stack(len);
	if (!recorder || !a || !b)
	{
		free_all(recorder, a ,b);
		return (NULL);
	}
	populate(a, len, numbers);
	magic_sort(a, b, recorder);
	free_stack(a);
	free_stack(b);
	return (recorder);
}
