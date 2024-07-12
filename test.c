/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:55:32 by amaula            #+#    #+#             */
/*   Updated: 2024/07/10 15:09:11 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

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
	for (int i = 0; i < len; ++i)
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

static void	run_permutations(char **ar, int l, int r)
{
	if (l == r)
	{
		print_ar(ar, r);
		t_recorder *result = push_swap(r, ar);
		if (result == NULL)
		{
			ft_printf("Error\n");
			return ;
		}
		print_result(result);
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

static char	**rng(int len)
{
	char **rstr = malloc((len) * sizeof(char*));
	for (int i = 0; i < len; i++)
		rstr[i] = ft_itoa(i + 1);
	//srand(time(NULL));

	struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((unsigned int)(ts.tv_nsec ^ (uintptr_t)&len ^ getpid()));

	for (; len > 0; len--)
	{
		int r = rand() % len;
		swap_str(&rstr[r], &rstr[len - 1]);
	}

	return rstr;
}

static void	random_input_permutations(int len)
{
	char	**ar;
	
	ar = rng(len);
	run_permutations(ar, 0, len);
	for (int i = 0; i < len; i++)
		free(ar[i]);
	free(ar);
}

static void	input_input(int argc, char **argv)
{
	t_recorder	*result = push_swap(argc, argv);
	if (result == NULL)
	{
		ft_printf("Error\n");
		return ;
	}
	print_result(result);
	free_recorder(result);
}

static void random_all(int iterations, int len)
{
	char **random_list;
	t_recorder *result;

	while (iterations-- > 0)
	{
		random_list = rng(len);
		result = push_swap(len, random_list);
		print_ar(random_list, len);
		print_result(result);
		free_recorder(result);
		for(int i = 0; i <= len; ++i)
			free(random_list[i]);
		free(random_list);
	}
}

int main(int argc, char **argv)
{
	clock_t begin = clock();
	int iterations = 1;
	if (argc < 2)
		return (1);
	if (ft_strncmp("pops", argv[1], 4) == 0)
	{
		print_ops = 1;
		argv++;
		argc--;
	}
	if (ft_strncmp("perm", argv[1], 4) == 0)
	{
		argv += 1;
		argc -= 1;
		random_input_permutations(ft_atoi(argv[1]));
	}
	else if (ft_strncmp("rand", argv[1], 4) == 0)
	{
		iterations = ft_atoi(argv[2]);
		argv += 2;
		argc -= 2;
		random_all(iterations, ft_atoi(argv[1]));
	}
	else
		input_input(argc - 1, argv + 1);
	
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%f s\n", time_spent);
	return (0);
}
