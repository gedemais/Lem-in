#include "main.h"

/*
** Parse the first line of the file, supposed to contain the number of ants.
*/
static inline bool	check_nb_ant(char *file, unsigned int *index)
{
	unsigned int	i;

	i = 0;
	if (file[0] == '\0')
		return (true);
	while (file[i] && file[i] != '\n')
	{
		if (ft_isdigit(file[i]) == 0)
				return (true);
		i++;
	}
	if (i > 10 || ft_atoi(file) > INT_MAX)
		return (true);
	*index = i + 1;
	return (false);
}

/*
** Create a memory representation of the graph
*/
t_room				*parsing(t_env *env)
{
	unsigned int	i;

	i = 0;
	if (!env->file || check_nb_ant(env->file, &i))
	{
		ft_putstr_fd(env->file ? "Invalid number of ants.\n" : "read_fd_zero failed.\n", 2);
		return (NULL);
	}
	if ((env->nb_rooms = count_rooms(env->file, &i)) < 2)
	{
		ft_putstr_fd("Not enough rooms\n", 2);
		return (NULL);
	}
	if (!(env->graph = make_graph(env)))
	{
		free(env->file);
		return (NULL);
	}
	free(env->file);
	return (env->graph);
}
