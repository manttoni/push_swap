/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:52:12 by amaula            #+#    #+#             */
/*   Updated: 2024/07/01 16:55:10 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_recorder(t_recorder *recorder)
{
	unsigned int	i;

	i = 0;
	while (i < recorder->len)
	{
		free(recorder->operations[i]);
		i++;
	}
	free(recorder->operations);
	free(recorder);
}

int main(int argc, char **argv)
{
	t_recorder		*result;
	unsigned int	i;

	i = 0;
	result = push_swap(argc, argv);
	if (result == NULL)
	{
		ft_printf("Error\n");
		return (1);
	}
	while (i < result->len)
	{
		ft_printf("%s\n", result->operations[i]);
		i++;
	}
	free_recorder(result);
	return (0);
}
