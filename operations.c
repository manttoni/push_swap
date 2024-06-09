#include "push_swap.h"
#define RIGHT 1
#define LEFT -1
void	shift(t_stack *stack, int direction)
{
	int i;

	if (direction == RIGHT)
	{
		i = stack->len;
		while (i > 0)
			stack->numbers[i] = stack->numbers[--i];
		stack->len++;
	}
	else if (direction == LEFT)
	{
		i = 0;
		while (i < stack->len)
		{
			stack->numbers[i] = stack->numbers[i + 1];
			i++;
		}
		stack->len--;
	}
}

void	swap(t_stack *stack)
{
	int	tmp;
	int	*numbers;

	if (stack->len < 2)
		return ;
	numbers = stack->numbers;
	tmp = numbers[0];
	numbers[0] = numbers[1];
	numbers[1] = tmp;
}

void	push(t_stack *from, t_stack *to)
{
	if (from->len == 0)
		return ;
	shift(to, RIGHT);
	to->numbers[0] = from->numbers[0];
	shift(from, LEFT);
}
