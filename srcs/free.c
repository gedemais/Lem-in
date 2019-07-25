#include "main.h"

static inline t_env	*free_graph(t_env *env)
{
	unsigned int	i;

	i = 0;
	while (i < env->nb_rooms)
	{
		if (env->graph[i].name)
			free(env->graph[i].name);
		if (env->graph[i].pipes)
			free(env->graph[i].pipes);
		i++;
	}
	free(env->graph);
	return (env);
}

t_env			*free_env(t_env *env)
{
	if (env->graph)
		env = free_graph(env);
	return (env);
}
