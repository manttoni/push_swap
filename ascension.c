/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:37:52 by amaula            #+#    #+#             */
/*   Updated: 2024/06/28 15:54:17 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	get_next_unsorted(t_stack *a)
{
	int	i;

	i = -1 * (long)a->len / 2;
	while (i < (long)a->len / 2)
	{
		if (top(a, i) > top(a, i + 1))
			return (i);
		i++;
	}
	return a->len + 1;
}
