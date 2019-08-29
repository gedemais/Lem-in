#include "main.h"

static inline unsigned int	count_paths(t_env *env)
{
	unsigned int	ret;

	ret = 0;
	while (env->paths[ret].path && env->paths[ret].path[0] != -1)
			ret++;
	return (ret);
}

static inline bool			arriveds(t_env *env)
{
	unsigned int	i;

	i = 1;
	while (i < env->nb_ants)
	{
		if (env->arriveds[i] == false)
			return (true);
		i++;
	}
	return (false);
}

static inline int			rotate_path(t_env *env, unsigned int p)
{
	int		move[2];
	int		i;

	i = 0;
	while (env->paths[p].path[i] != env->end && env->paths[p].path[i] != -1)
		i++;
	while (env->paths[p].path[i] != env->start)
	{
		env->paths[p].ants[i] = env->paths[p].ants[i - 1];
		if (env->paths[p].path[i] == env->end && env->paths[p].ants[i] != -1 && env->end && env->paths[p].ants[i] < env->nb_ants)
			env->arriveds[env->paths[p].ants[i]] = true;
		if (env->paths[p].ants[i] != -1 && env->paths[p].path[i] != -1)
		{
			move[0] = env->paths[p].ants[i];
			move[1] = env->paths[p].path[i];
			output_buffer(env, move, false, false);
		}
		i--;
	}
	if (env->paths[p + 1].path && env->paths[p + 1].path[0] != -1)
		env->paths[p + 1].ants[0] = (env->count < env->nb_ants) ? (int)env->count++ : -1;
	return (0);
}

int							crossing(t_env *env)
{
	unsigned int	i;
	unsigned int	nb_paths;

	env->count = 1;
	env->nb_ants++;
	nb_paths = count_paths(env);
	env->paths[0].ants[0] = (int)env->count++;
	i = 0;
/*	while (env->paths[i].path && env->paths[i].path[0] != -1)
	{
		for (int j = 0; env->paths[i].path[j] != env->end ; j++)
			printf("Path %u [%u] : %s\n", i, j, env->graph[env->paths[i].path[j]].name);
		printf("\n");
		i++;
	}*/
	while (env->count <= env->nb_ants || arriveds(env)) // Tant qu'il y a des fourmis a envoyer
	{
		i = 0;
		while (i < nb_paths && (env->count <= env->nb_ants || arriveds(env)))
		{
			rotate_path(env, i);
			i++;
		}
		output_buffer(env, NULL, true, false);
		env->paths[0].ants[0] = (int)env->count;
		env->count++;
	}
	output_buffer(env, NULL, false, true);
	return (0);
}
