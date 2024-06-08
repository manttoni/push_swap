#include "push_swap.h"
#include <stdio.h>

int main(void)
{
	int *array = malloc(5 * sizeof(int));
	for(int i = 0; i < 5; ++i)
		array[i] = i;
	swap(array);
	for(int i = 0; i < 5; ++i)
		printf("%d\n", array[i]);
	free(array);
	return 0;
}
