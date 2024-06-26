#include "push_swap.h"

t_recorder	*init_recorder()
{
	t_recorder	*r;

	r = malloc(sizeof(t_recorder));
	if (r == NULL)
		return (NULL);
	r->operations = malloc(sizeof(char*));
	if (r->operations == NULL)
		return (NULL);
	r->len = 0;
	r->allocated = 1;
	return (r);
}

static void	*ft_realloc_operations(t_recorder *recorder, size_t new_size)
{
	char			**new_operations;
	unsigned int	i;

	i = 0;
	new_operations = malloc((new_size) * sizeof(char*));
	if (new_operations == NULL)
		return (NULL);
	while (i < recorder->len)
	{
		new_operations[i] = recorder->operations[i];
		i++;
	}
	free(recorder->operations);
	recorder->operations = new_operations;
	recorder->allocated = new_size;
	return (recorder);
}

int	record(t_recorder *recorder, char *operation)
{
	char	*last_operation;

	if (recorder->len > 0)
	{
		last_operation = recorder->operations[recorder->len - 1];
		if (ft_strncmp(last_operation, operation, 3) == 1)
		{
			last_operation[ft_strlen(last_operation) - 1] = last_operation[0];
			return (1);
		}
	}
	if (recorder->len == recorder->allocated)
	{
		ft_realloc_operations(recorder, recorder->allocated * 2);
		if (recorder->operations == NULL)
			return (0);
	}
	recorder->operations[recorder->len] = ft_strdup(operation);
	if (recorder->operations[recorder->len] == NULL)
		return (0);
	recorder->len++;
	return (1);
}