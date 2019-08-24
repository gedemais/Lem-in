#include "main.h"

static inline unsigned int	count_paths(t_env *env)
{
	unsigned int	ret;

	ret = 0;
	while (env->paths[ret].path && env->paths[ret].path[0] != -1)
			ret++;
	return (ret);
}

static inline int			rotate_path(t_env *env, unsigned int p)
{
	int		i;

	i = 0;
	while (env->paths[p].path[i] != env->end && env->paths[p].path[i] != -1)
		i++;
	while (env->paths[p].path[i] != env->start)
	{
		env->paths[p].ants[i] = env->paths[p].ants[i - 1];
		i--;
	}
	if (env->paths[p + 1].path && env->paths[p + 1].path[0] != -1)
		env->paths[p + 1].ants[0] = (int)env->count++;
	int		j = 1;
	while (env->paths[p].path[j] != env->end)
	{
		printf("path %d [%d] = %d\n", p, j, env->paths[p].ants[j]);
		j++;
	}
	printf("\n");
	return (0);
}

int							crossing(t_env *env)
{
	unsigned int	i;
	unsigned int	nb_paths;

	env->count = 1;
	nb_paths = count_paths(env);
	env->paths[0].ants[0] = (int)env->count++;
	while (env->count < env->nb_ants) // Tant qu'il y a des fourmis a envoyer
	{
		i = 0;
		while (i < nb_paths && env->count < env->nb_ants)
		{
			// Rotate le chemin i et stocker tous ses mouvements valides
			rotate_path(env, i);
			i++;
		}
		env->paths[0].ants[0] = (int)env->count;
		env->count++;
	}
	return (0);
}
