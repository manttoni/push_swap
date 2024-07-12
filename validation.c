/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:52:15 by amaula            #+#    #+#             */
/*   Updated: 2024/07/09 14:52:19 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_integer(char *str)
{
	long	res;

	res = ft_strtol(str);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	if (res > INT_MAX || res < INT_MIN)
		return (0);
	return (1);
}

static int	all_unique(int len, char **numbers)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < len)
	{
		while (i + j < len)
		{
			if (ft_strncmp(numbers[i], numbers[i + j], 12) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_input(int len, char **numbers)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (!is_integer(numbers[i]))
			return (0);
		i++;
	}
	return (all_unique(len, numbers));
}
