/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:55:32 by amaula            #+#    #+#             */
/*   Updated: 2024/07/01 18:26:19 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_str(char **x, char **y)
{
	char	*temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

static void	print_ar(char **ar, int len)
{
	ft_printf("\nSorting:");
	for (int i = 1; i < len; ++i)
		ft_printf(" %s", ar[i]);
	ft_printf("\n");
}

static void	run_permutations(char **ar, int l, int r)
{
	if (l == r)
	{
		print_ar(ar, r);
		t_recorder *result = push_swap(r, ar);
		ft_printf("Ops: %u\n", result->len);
		free_recorder(result);
	}
	else
	{
		for (int i = l; i < r; ++i)
		{
			swap_str((&ar[l]), (&ar[i]));
			run_permutations(ar, l + 1, r);
			swap_str((&ar[l]), (&ar[i]));
		}
	}
}


int main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	int		len = ft_atoi(argv[1]) + 1;
	char	*ar[len];
	
	for (int i = 0; i < len; ++i)
		ar[i] = ft_itoa(i);

	run_permutations(ar, 1, len);
	return (0);
}
