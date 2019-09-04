#include "main.h"

int			treat_paths(t_env *env)
{
	sort_paths(env);
	if (env->nb_ants < env->paths[0].len)
	{
		env->nb_paths = 1;
		env->paths[1].path[0] = -1;
		return (0);
	}
	return (0);
}

