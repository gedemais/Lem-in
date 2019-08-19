#include "main.h"

static inline int	get_path_max(t_env *env)
{
	unsigned int	i;
	int				ret_s;
	int				ret_e;

	i = 0;
	ret_s = 0;
	ret_e = 0;
	while (i < env->nb_rooms)
	{
		if (env->matrix[env->start][i] == 1)
			ret_s++;
		if (env->matrix[env->end][i] == 1)
			ret_e++;
		i++;
	}
	return (ret_s > ret_e ? ret_e : ret_s);
}

static inline int	**allocate_paths(t_env *env)
{
	int				path_max;
	unsigned int	i;

	i = 0;
	path_max = get_path_max(env);
	if (!(env->paths = (int**)malloc(sizeof(int*) * (unsigned long)
		(path_max + 1))))
		return (NULL);
	while (i < (unsigned int)path_max)
	{
		if (!(env->paths[i] = (int*)malloc(sizeof(int) * env->nb_rooms)))
			return (NULL);
		ft_memset(env->paths[i], -1, sizeof(int) * env->nb_rooms);
		i++;
	}
	env->paths[i] = NULL;
	return (env->paths);
}

int					store_paths(t_env *env, int room, bool next)
{
	static int	which = 0;
	static int	index = 0;

	if (!env->paths && !(env->paths = allocate_paths(env)))
		return (-1);
	if (next)
	{
		index = 0;
		which++;
	}
	else
	{
		env->paths[which][index] = room;
		index++;
	}
	return (0);
}
