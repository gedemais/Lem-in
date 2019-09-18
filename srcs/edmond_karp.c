/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmond_karp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 05:30:15 by gedemais          #+#    #+#             */
/*   Updated: 2019/09/18 08:05:10 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

unsigned int		edmond_karp(t_env *env, bool up)
{
	unsigned int	max_flow; // a tej
	unsigned int	path; // a tej
	unsigned int	i;
	int				u;
	int				v;

	max_flow = 0;
	path = 0;
	env->visited = ft_memset(env->visited, 0, sizeof(bool) * env->nb_rooms);
	if (!env->paths && !(env->paths = allocate_paths(env)))
		return (0);
	while (breadth_first_search(env, env->start, env->end, up))
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
		env->visited = ft_memset(env->visited, 0, sizeof(bool) * env->nb_rooms);
		max_flow++;
		path++;
	}
	env->nb_paths = path;
	env->paths = rev_paths(env->paths);
	return (max_flow);
}
