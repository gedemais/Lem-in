#include "main.h"

void	print_path(t_env *env, int *path)
{
	int		r;

	r = env->end;
	while (r != -1)
	{
		printf("%s\n", env->graph[r].name);
		r = path[r];
	}
}

static inline void	clear_buffs(t_env *env)
{
	env->parent = ft_memset(env->parent, -1, sizeof(int) * env->nb_rooms);
	env->visited = ft_memset(env->visited, 0, sizeof(bool) * env->nb_rooms);
}

unsigned int		edmond_karp(t_env *env)
{
	unsigned int	max_flow;
	int				u;
	int				v;

	max_flow = 0;
	clear_buffs(env);
	env->paths = NULL;
	while (breadth_first_search(env, env->start, env->end))
	{
		v = env->end;
		store_paths(env, v, false);
		while (v != env->start)
		{
			u = env->parent[v];
			env->matrix[u][v]--;
			env->matrix[v][u]++;
			v = env->parent[v];
			store_paths(env, v, false);
		}
		store_paths(env, v, true);
		clear_buffs(env);
		max_flow++;
	}
	return (max_flow);
}
