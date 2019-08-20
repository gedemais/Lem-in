#include "main.h"

static inline void	rotate_path(t_env *env, unsigned int p)
{
	unsigned int	i;

	i = 0;
	while (env->paths[p].path[i] != env->end)
		i++;
	if (env->paths[p].ants[i] > -1)
		i--;
	while (env->paths[p].path[i] != env->start)
	{
		env->paths[p].ants[i + 1] = env->paths[p].ants[i];
		i--;
	}
	env->paths[p].ants[i + 1] = (int)env->count;
	env->count++;
}

int					crossing(t_env *env)
{
	unsigned int	i;
	int				k;
	int				epoch = 0;

	env->count = 0;
	while (env->count < env->nb_ants)
	{
//		printf("Epoch %d\n", epoch);
		i = 0;
		while (env->paths[i].path && env->paths[i].path[0] != -1)
		{
//			printf("path %u :\n", i);
			rotate_path(env, i);
			k = 0;
			while (env->paths[i].path[k] != -1)
			{
//				printf("%s : %d\n", env->graph[env->paths[i].path[k]].name, env->paths[i].ants[k]);
				k++;
			}
//			printf("\n---------------\n");
			i++;
		}
		epoch++;
	}
	return (0);
}
