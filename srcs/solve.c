#include "main.h"

int		solve(t_env *env)
{
	int				u;
	int				v;
	int				max_flow;
	int				pflow;

	max_flow = 0;
	while (bfs(env, env->start, env->end))
	{
		pflow = INT_MAX;
		v = (int)env->graph[env->end].index;
		while (v != (int)env->start)
		{
			u = env->parent[v];
			pflow = (pflow < env->r_matrix[u][v]) ? pflow : env->r_matrix[u][v];
			v = env->parent[v];
		}
		v = (int)env->graph[env->end].index;
		while (v != (int)env->start)
		{
			u = env->parent[v];
			env->r_matrix[u][v] -= pflow;
			env->r_matrix[v][u] += pflow;
			v = env->parent[v];
		}
	}
	return (max_flow);
}
