#include "main.h"

static inline t_env	*free_graph(t_env *env)
{
	unsigned int	i;

	i = 0;
	while (i < env->nb_rooms)
	{
		if (env->graph[i].name)
			free(env->graph[i].name);
		i++;
	}
	free(env->graph);
	return (env);
}

static inline char	**free_matrix(char **matrix, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		ft_strdel(&matrix[i]);
		i++;
	}
	free(matrix);
	return ((matrix = NULL));
}

t_env			*free_env(t_env *env)
{
	if (env->graph)
		env = free_graph(env);
	if (env->file)
			free(env->file);
	if (env->matrix)
		env->matrix = free_matrix(env->matrix, env->nb_rooms);
	if (env->r_matrix)
		env->r_matrix = free_matrix(env->r_matrix, env->nb_rooms);
	return (env);
}
