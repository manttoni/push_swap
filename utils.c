/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:37:16 by amaula            #+#    #+#             */
/*   Updated: 2024/06/26 16:38:33 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(t_stack *a, t_stack *b)
{
	ft_printf("\na: ");
	for(unsigned int i = 0; i < a->len; i++)
		ft_printf("%d ", top(a, i));
	ft_printf("\nb: ");
	for(unsigned int i = 0; i < b->len; i++)
		ft_printf("%d ", top(b, i));
	ft_printf("\n");
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

static void	operate2(char *operation, t_stack *a, t_stack *b)
{
	if (*operation == 'r' && ft_strlen(operation) == 2)
	{
		if (operation[1] == 'a')
			rotate(a);
		else
			rotate(b);
	}
	else if (ft_strlen(operation) == 3)
	{
		if (operation[2] == 'a')
			rotate_reverse(a);
		else
			rotate_reverse(b);
	}
}

int	operate(char *operation, t_stack *a, t_stack *b, t_recorder *recorder)
{
	if (*operation == 's')
	{
		if (operation[1] == 'a')
			swap(a);
		else
			swap(b);
	}
	else if (*operation == 'p')
	{
		if (operation[1] == 'a')
			push(b, a);
		else
			push(a, b);
	}
	operate2(operation, a, b);
	if (record(recorder, operation) == 0)
		return (0);
	ft_printf("\n%s", operation);
	return (1);
}
