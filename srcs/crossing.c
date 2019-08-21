#include "main.h"

static inline int	*rotate_path(t_env *env, int path, int *moves)
{
	int				index;
	unsigned int	i;

	i = 0;
	index = 0;
	while (env->paths[path].path[i] != env->end)
		i++;
	while (env->paths[path].path[i] != env->start)
	{
		env->paths[path].ants[i] = env->paths[path].ants[i - 1];
		if (env->paths[path].ants[i] != -1)
		{
			moves[index++] = env->paths[path].ants[i];
			moves[index++] = env->paths[path].path[i];
		}
		i--;
	}
	env->paths[path].ants[i] = (int)env->count++;
/*	int		j = 0;
	printf("---Path %d ---\n", path);
	while (j <= index)
	{
		printf("%d -> %s\n", moves[j], env->graph[moves[j + 1]].name);
		j += 2;
	}
	printf("\n");*/
	return (moves);
}

static inline int	**allocate_moves_buffer(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (env->paths[i].path && env->paths[i].path[0] != -1)
		i++;
	j = i;
	if (!(env->path_moves = (int**)malloc(sizeof(int*) * (unsigned int)(i + 1))))
			return (NULL);
	i = 0;
	while (i < j)
	{
		if (!(env->path_moves[i] = (int*)malloc(sizeof(int) * env->nb_rooms * 2)))
			return (NULL);
		i++;
	}
	env->path_moves[i] = NULL;
	return (env->path_moves);
}

int					crossing(t_env *env)
{
	unsigned int	i;

	i = 0;
	env->count = 1;
	env->paths[0].ants[0] = (int)env->count++;
	if (!(env->path_moves = allocate_moves_buffer(env)))
			return (-1);
	while (env->count < env->nb_ants) // Loop iterating through every ants
	{
		i = 0;
		while (env->paths[i].path && env->paths[i].path[0] != -1 && env->count < env->nb_ants) // ___ paths
		{
			ft_memset(env->path_moves[i], -1, sizeof(int) * env->nb_rooms * 2);
			env->path_moves[i] = rotate_path(env, (int)i, env->path_moves[i]);
			display_moves(env);
			i++;
		}
	}
	return (0);
}
