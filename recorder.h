#ifndef RECORDER_H
# define RECORDER_H

# include <stdlib.h>

typedef	s_recorder
{
	char			**operations;
	unsigned int	len;
	size_t			allocated;
	void			(*record)(char**, unsigned int, size_t);
}		t_recorder;

void	record(char **operations, unsigned int len, size_t allocated);

#endif
