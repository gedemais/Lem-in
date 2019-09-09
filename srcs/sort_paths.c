#include "main.h"

static inline void	swap_paths(t_path *a, t_path *b)
{
		t_path	tmp;

		tmp.path = a->path;
		a->path = b->path;
		b->path = tmp.path;

		tmp.len = a->len;
		a->len = b->len;
		b->len = tmp.len;
}

static inline void	print_paths(t_env *env)
{
	unsigned int		i;

	i = 0;
	while (i < env->nb_paths)
	{
		printf("%d\n", env->paths[i].len);
		i++;
	}
	printf("\n");
}

static inline bool	spec_cases(t_env *env)
{
	if (env->nb_paths == 1)
		return (true);
	if (env->nb_paths == 2)
	{
		if (env->paths[0].len > env->paths[1].len)
			swap_paths(&env->paths[0], &env->paths[1]);
		return (true);
	}
	return (false);
}

int					sort_paths(t_env *env)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	best;
	unsigned int	b_index;

	i = 0;
	if (spec_cases(env))
		return (0);
	while (i < env->nb_paths - 1)
	{
		j = i;
		b_index = j;
		best = env->paths[j].len;
		while (j < env->nb_paths)
		{
			if (best >= env->paths[j].len)
			{
				best = env->paths[j].len;
				b_index = j;
			}
			j++;
		}
		swap_paths(&env->paths[i], &env->paths[b_index]);
		i++;
	}
	print_paths(env);
	return (0);
}
