/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recorder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:52:00 by amaula            #+#    #+#             */
/*   Updated: 2024/07/09 14:52:01 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_recorder(t_recorder *recorder)
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

t_recorder	*init_recorder(void)
{
	t_recorder	*recorder;

	recorder = malloc(sizeof(t_recorder));
	if (recorder == NULL)
		return (NULL);
	recorder->operations = malloc(sizeof(char *));
	if (recorder->operations == NULL)
	{
		free(recorder);
		return (NULL);
	}
	recorder->len = 0;
	recorder->allocated = 1;
	return (recorder);
}

static void	*ft_realloc_operations(t_recorder *recorder, size_t new_size)
{
	char			**new_operations;
	unsigned int	i;

	i = 0;
	new_operations = malloc((new_size) * sizeof(char *));
	if (new_operations == NULL)
		return (NULL);
	while (i < recorder->len)
	{
		new_operations[i] = recorder->operations[i];
		i++;
	}
	free(recorder->operations);
	recorder->operations = new_operations;
	recorder->allocated = new_size;
	return (recorder);
}

int	record(t_recorder *recorder, char *operation)
{
	if (recorder->len == recorder->allocated)
	{
		ft_realloc_operations(recorder, recorder->allocated * 2);
		if (recorder->operations == NULL)
			return (0);
	}
	recorder->operations[recorder->len] = ft_strdup(operation);
	if (recorder->operations[recorder->len] == NULL)
		return (0);
	recorder->len++;
	return (1);
}
