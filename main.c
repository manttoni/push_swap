/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:52:12 by amaula            #+#    #+#             */
/*   Updated: 2024/07/09 14:49:35 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_result(t_recorder *result)
{
	unsigned int	i;

	i = 0;
	while (i < result->len)
	{
		ft_printf("%s\n", result->operations[i]);
		i++;
	}
}

static void	free_numbers(char **numbers)
{
	char	**ptr;

	ptr = numbers;
	while (*numbers)
	{
		free(*numbers);
		numbers++;
	}
	free(ptr);
}

int	main(int argc, char **argv)
{
	t_recorder	*result;
	int		len;
	char		**numbers;

	if (argc == 1 || ft_strlen(argv[1]) == 0)
		return (1);
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		len = ft_countchar(argv[1], ' ') + 1;
		numbers = ft_split(argv[1], ' ');
	}
	else
	{
		numbers = argv + 1;
		len = argc - 1;
	}
	result = push_swap(len, numbers);
	if (len != argc - 1)
		free_numbers(numbers);
	if (result == NULL)
	{
		ft_printf("Error\n");
		return (1);
	}
	print_result(result);
	free_recorder(result);
	return (0);
}
