#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int	*numbers;
	int	len;
}	t_stack;


void	push_swap(t_stack *a, t_stack *b);
int	swap(t_stack *stack);
int	push(t_stack *from, t_stack *to);
int	rotate(t_stack *stack);
int	rotate_reverse(t_stack *stack);
int	iterative_merge_sort(t_stack *a, t_stack *b);

void	p(t_stack *a, t_stack *b);
void	pr(t_stack *a, t_stack *b);
int	magic_sort(t_stack *a, t_stack *b);

#endif
