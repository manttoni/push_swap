#include "recorder.h"
#include "push_swap.h"

t_recorder	*init_recorder()
{
	t_recorder	*r;

	r = malloc(sizeof(t_recorder));
	r->operations = malloc(sizeof(char*));
	if (r->operations == NULL)
		return (NULL);
	r->len = 0;
	r->allocated = 1;
	return (r);
}

int	record(t_recorder *recorder, char *operation)
{
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

void	*ft_realloc_operations(t_recorder *recorder, size_t new_size)
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

void	find_simultaneous(t_recorder *recorder)
{
	unsigned int	i;
	char			*current;
	char			*next;

	i = 0;
	while (i < recorder->len - 1)
	{
		current = recorder->operations[i];
		next = recorder->operations[i + 1];
		if (ft_strcmp(current, next) == 1)
		{
			current[ft_strlen(current) - 1] = current[0];
			ft_memmove(next, next + 1, recorder->len - i - 1);
			free(recorder->operations[recorder->len - 1]);
			recorder->len--;
		}
		i++;
	}
}
