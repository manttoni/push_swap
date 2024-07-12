#include "push_swap.h"

unsigned int    absolute(int i)
{
        if (i < 0)
                return (-i);
        return (i);
}

int     stack_max(t_stack *stack)
{
        int                             max;
        unsigned int    i;

        i = 0;
        max = INT_MIN;
        while (i < stack->len)
        {
                if (top(stack, i) > max)
                        max = top(stack, i);
                i++;
        }
        return (max);
}

int     stack_min(t_stack *stack)
{
        int                             min;
        unsigned int    i;

        i = 0;
        min = INT_MAX;
        while (i < stack->len)
        {
                if (top(stack, i) < min)
                        min = top(stack, i);
                i++;
        }
        return (min);
}
