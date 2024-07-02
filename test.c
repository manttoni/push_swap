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
#include <stdio.h>

int	print_ops = 0;

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

static void	print_result(t_recorder *result)
{
	if (print_ops == 1)
		for (unsigned int i = 0; i < result->len; ++i)
			ft_printf("%s\n", result->operations[i]);
	ft_printf("Ops: %u\n", result->len);
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
		print_result(result);
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

static void	random_input_permutations(int argc, char **argv)
{
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
}

static void	input_input(int argc, char **argv)
{
	t_recorder	*result = push_swap(argc, argv);
	print_result(result);
	free_recorder(result);
}

int main(int argc, char **argv)
{
	clock_t begin = clock();
	if (argc < 2)
		return (1);
	if (ft_strncmp("pops", argv[1], 4) == 0)
	{
		print_ops = 1;
		argv++;
		argc--;
	}
	if (argc < 4)
		random_input_permutations(argc, argv);
	else
		input_input(argc, argv);
	
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%f s\n", time_spent);
	return (0);
}
