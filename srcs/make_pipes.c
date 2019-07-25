#include "main.h"

static inline unsigned int	*dup_pipes(t_env *env)
{
	unsigned int	*dest;
	unsigned int	i;

	i = 0;
	if (!(dest = (unsigned int*)malloc(sizeof(unsigned int) * env->nb_rooms)))
			return (NULL);
	while (i < env->nb_rooms)
	{
		dest[i] = env->nb_pipes[i];
		i++;
	}
	return (dest);
}

static inline t_room		*allocate_pipes(t_env *env)
{
	unsigned int	i;

	i = 0;
	while (i < env->nb_rooms)
	{
		if (!(env->graph[i].pipes = (unsigned int*)malloc(sizeof(unsigned int)
				* env->nb_pipes[i])))
				return (NULL);
		i++;
	}
	return (env->graph);
}

t_room						*make_pipes(t_env *env, unsigned int i)
{
	unsigned int	j;
	char			s;

	j = 0;
	if (!(env->nb_pipes = count_pipes(env, i))
			|| !(env->tmp = dup_pipes(env)))
			return (NULL);
	if (!(env->graph = allocate_pipes(env)))
			return (NULL);
	while (env->file[i] && (s = get_line_state(&env->file[i], false)))
	{
		if (s == 'p')
			load_line(env, s, i, 0);
		next_line(env->file, &i);
	}
	ft_memcpy(env->nb_pipes, env->tmp, sizeof(unsigned int) * env->nb_rooms);
	return (env->graph);
}
