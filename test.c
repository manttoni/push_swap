/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:55:32 by amaula            #+#    #+#             */
/*   Updated: 2024/07/01 19:50:24 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

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

static void	run_permutations(char **ar, int l, int r, int *iterations)
{
	if (*iterations == 0)
		return ;
	if (l == r)
	{
		ft_printf("Iterations: %d\n", *iterations);
		if (*iterations == 0)
			return ;
		else if (*iterations > 0)
			(*iterations)--;	
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
			run_permutations(ar, l + 1, r, iterations);
			swap_str((&ar[l]), (&ar[i]));
		}
	}
}

static char	**rng(int len)
{
	char **rstr = malloc((1 + len) * sizeof(char*));
	for (int i = 0; i <= len; i++)
		rstr[i] = ft_itoa(i);
	srand(time(NULL));
	for (; len > 0; len--)
	{
		int r = rand() % len + 1;
		swap_str(&rstr[r], &rstr[len]);
	}

	return rstr;
}

int main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	int		len = ft_atoi(argv[1]);
	char	**ar;
	int		iterations = -1;
	if (argc > 2)
		iterations = ft_atoi(argv[2]);
	
	ar = rng(len);
	run_permutations(ar, 1, len + 1, &iterations);
	for (int i = 0; i <= len; i++)
		free(ar[i]);
	free(ar);
	return (0);
}
