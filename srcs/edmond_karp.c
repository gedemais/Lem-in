#include "main.h"

static inline void	clear_buffs(t_env *env)
{
	env->parent = ft_memset(env->parent, -1, sizeof(int) * env->nb_rooms);
	env->visited = ft_memset(env->visited, 0, sizeof(bool) * env->nb_rooms);
}

static inline t_path	*rev_paths(t_path *paths)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	while (paths[i].path && paths[i].path[0] != -1)
	{
		j = 0;
		k = 0;
		while (paths[i].path[k] != -1)
			k++;
		k--;
		while (j < k)
		{
			ft_swap(&paths[i].path[j], &paths[i].path[k]);
			j++;
			k--;
		}
		i++;
	}
	return (paths);
}

unsigned int		edmond_karp(t_env *env)
{
	unsigned int	max_flow;
	unsigned int	path;
	unsigned int	i;
	int		u;
	int		v;

	max_flow = 0;
	path = 0;
	clear_buffs(env);
	env->paths = NULL;
	if (!(env->paths = allocate_paths(env)))
		return (0);
	while (breadth_first_search(env, env->start, env->end))
	{
		i = 0;
		v = env->end;
		while (v != env->start)
		{
			env->paths[path].path[i] = v;
			u = env->parent[v];
			env->matrix[u][v]--;
			env->matrix[v][u]++;
			v = env->parent[v];
			i++;
		}
		env->paths[path].path[i] = env->start;
		env->paths[path].path[i + 1] = -1;
		env->paths[path].len = i;
		clear_buffs(env);
		max_flow++;
		path++;
	}
	env->paths = rev_paths(env->paths);
	return (max_flow);
}
