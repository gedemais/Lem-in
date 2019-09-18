/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmond_karp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 05:30:15 by gedemais          #+#    #+#             */
/*   Updated: 2019/09/19 00:08:27 by gedemais         ###   ########.fr       */
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

static inline int		ek_loop(t_env *env, bool up)
{
	unsigned int	i;
	int				u;
	int				v;

	while (breadth_first_search(env, env->start, env->end, up))
	{
		i = 0;
		v = env->end;
		while (v != env->start)
		{
			env->paths[env->nb_paths].path[i] = v;
			u = env->parent[v];
			env->matrix[u][v]--;
			env->matrix[v][u]++;
			v = env->parent[v];
			i++;
		}
		env->paths[env->nb_paths].path[i] = env->start;
		env->paths[env->nb_paths].path[i + 1] = -1;
		env->paths[env->nb_paths].len = i;
		env->visited = ft_memset(env->visited, 0, sizeof(bool) * env->nb_rooms);
		env->max_flow++;
		env->nb_paths++;
	}
	return (0);
}

unsigned int			edmond_karp(t_env *env, bool up)
{
	env->visited = ft_memset(env->visited, 0, sizeof(bool) * env->nb_rooms);
	if (!env->paths && !(env->paths = allocate_paths(env)))
		return (0);
	ek_loop(env, up);
	env->paths = rev_paths(env->paths);
	return (env->max_flow);
}
