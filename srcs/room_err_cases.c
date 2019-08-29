#include "main.h"

static inline bool	check_same_rooms(t_env *env)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < env->nb_rooms)
	{
		j = i + 1;
		while (j < env->nb_rooms)
		{
			if (env->graph[i].name[0] == env->graph[j].name[0])
				if (ft_strcmp(env->graph[i].name, env->graph[j].name) == 0)
					return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static inline bool	check_same_coords(t_env *env)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < env->nb_rooms)
	{
		j = i + 1;
		while (j < env->nb_rooms)
		{
			if (env->graph[i].x == env->graph[j].x
				&& env->graph[i].y == env->graph[j].y)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool				room_err_cases(t_env *env)
{
	if (check_same_rooms(env) || check_same_coords(env))
		return (true);
	return (false);
}
