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

t_path				*allocate_paths(t_env *env)
{
	int				path_max;
	unsigned int	i;

	i = 0;
	path_max = get_path_max(env);
	if (!(env->paths = (t_path*)malloc(sizeof(t_path) * (unsigned long)
		(path_max + 1))))
		return (NULL);
	while (i < (unsigned int)path_max)
	{
		if (!(env->paths[i].path = (int*)malloc(sizeof(int) * env->nb_rooms)))
			return (NULL);
		ft_memset(env->paths[i].path, -1, sizeof(int) * env->nb_rooms);
		i++;
	}
	env->paths[i].path = NULL;
	return (env->paths);
}
