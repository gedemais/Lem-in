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

int					sort_paths(t_env *env)
{
		unsigned int	i;
		unsigned int	j;
		unsigned int	best;
		unsigned int	b_index;

		i = 0;
		while (i < env->nb_paths - 1)
		{
				j = i + 1;
				b_index = j;
				best = env->paths[j].len;
				while (j < env->nb_paths)
				{
						if (best > env->paths[j].len)
						{
							best = env->paths[j].len;
							b_index = j;
						}
						j++;
				}
				swap_paths(&env->paths[i], &env->paths[b_index]);
				i++;
		}
		return (0);
}
