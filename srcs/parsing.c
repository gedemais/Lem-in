#include "main.h"
/*
static inline bool	check_nb_ant(char *file)
{
	unsigned int	i;

	i = 0;
	while (file[i] && file[i] != '\n')
	{
		if (ft_isdigit(file[i]) == 0)
				return (true);
		i++;
	}
	if (i >= 10 || ft_atoi(file) > INT_MAX)
		return (true);
	return (false);
}*/

t_room		*parsing(char *file)
{
	t_room			*graph;

	graph = NULL;
	ft_putstr(file);
	if (!file)
		return (NULL);
	return (graph);
}
