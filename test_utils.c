#include "push_swap.h"

void    pr(t_stack *a, t_stack *b)
{
        ft_printf("\n\ta:");
        for (int i = 0; i < a->len; ++i)
                ft_printf(" %d", a->numbers[i]);
        ft_printf("\n\tb:");
        for (int i = 0; i < b->len; ++i)
                ft_printf(" %d", b->numbers[i]);
        ft_printf("\n");
}

void    p(t_stack *a, t_stack *b)
{
        pr(a, b);
}
