/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:50:19 by amaula            #+#    #+#             */
/*   Updated: 2024/07/10 16:05:09 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operate_both(char *operation, t_stack *a, t_stack *b)
{
	int	op_success;

	op_success = 0;
	if (ft_strncmp(operation, "ss", 2) == 0 && a->len > 1 && b->len > 1)
		op_success = swap(a) * swap(b);
	else if (ft_strncmp(operation, "rr", 2) == 0 && ft_strlen(operation) == 2)
		op_success = rotate(a) * rotate(b);
	else if (ft_strncmp(operation, "rrr", 3) == 0)
		op_success = rotate_reverse(a) * rotate_reverse(b);
	return (op_success);
}

static int	operate_a(char *operation, t_stack *a, t_stack *b)
{
	int	op_success;

	op_success = 0;
	if (ft_strncmp(operation, "sa", 2) == 0)
		op_success = swap(a);
	else if (ft_strncmp(operation, "pa", 2) == 0)
		op_success = push(b, a);
	else if (ft_strncmp(operation, "ra", 2) == 0)
		op_success = rotate(a);
	else if (ft_strncmp(operation, "rra", 3) == 0)
		op_success = rotate_reverse(a);
	return (op_success);
}

static int	operate_b(char *operation, t_stack *a, t_stack *b)
{
	int	op_success;

	op_success = 0;
	if (ft_strncmp(operation, "sb", 2) == 0)
		op_success = swap(b);
	else if (ft_strncmp(operation, "pb", 2) == 0)
		op_success = push(a, b);
	else if (ft_strncmp(operation, "rb", 2) == 0)
		op_success = rotate(b);
	else if (ft_strncmp(operation, "rrb", 3) == 0)
		op_success = rotate_reverse(b);
	return (op_success);
}

int	operate(char *operation, t_stack *a, t_stack *b, t_recorder *recorder)
{
	int	op_success;

	if (operation[ft_strlen(operation) - 1] == 'a')
		op_success = operate_a(operation, a, b);
	else if (operation[ft_strlen(operation) - 1] == 'b')
		op_success = operate_b(operation, a, b);
	else
		op_success = operate_both(operation, a, b);
	if (op_success)
		if (record(recorder, operation) == 0)
			return (0);
	return (1);
}
