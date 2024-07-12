/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:55:07 by amaula            #+#    #+#             */
/*   Updated: 2024/07/10 15:48:05 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				*numbers;
	unsigned int	len;
}	t_stack;

typedef struct s_recorder
{
	char			**operations;
	unsigned int	len;
	size_t			allocated;
}	t_recorder;

int				golden_cut(t_stack *stack);
int				stack_min(t_stack *stack);
int				stack_max(t_stack *stack);
void			free_recorder(t_recorder *recorder);
void			free_stack(t_stack *stack);
int				validate_input(int argc, char **argv);
void			least_rotations(t_stack *a, t_stack *b, int *rotations);
int				operate(char *op, t_stack *a, t_stack *b, t_recorder *rec);
int				record(t_recorder *recorder, char *operation);
t_recorder		*init_recorder(void);
t_stack			*init_stack(int len);
t_recorder		*push_swap(int len, char **numbers);
int				swap(t_stack *stack);
int				push(t_stack *from, t_stack *to);
int				rotate(t_stack *stack);
int				rotate_reverse(t_stack *stack);
int				magic_sort(t_stack *a, t_stack *b, t_recorder *recorder);
unsigned int	absolute(int i);
int				top(t_stack *stack, int index);
int				is_ascending(t_stack *stack);

#endif
