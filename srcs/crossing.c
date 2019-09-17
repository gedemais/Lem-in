/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crossing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 01:33:56 by gedemais          #+#    #+#             */
/*   Updated: 2019/09/17 07:53:19 by demaisonc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static inline bool	arriveds(t_env *env)
{
	unsigned int	i;

	i = 1;
	while (i < env->nb_ants)
	{
		if (env->arriveds[i] == false)
			return (true);
		i++;
	}
	return (false);
}

static inline int	rotate_path(t_env *env, unsigned int p)
{
	int		move[2];
	int		i;

	i = 0;
	while (env->paths[p].path[i] != env->end && env->paths[p].path[i] != -1)
		i++;
	while (env->paths[p].path[i] != env->start)
	{
		env->paths[p].ants[i] = env->paths[p].ants[i - 1];
		if (env->paths[p].path[i] == env->end && env->paths[p].ants[i] != -1 && env->end && env->paths[p].ants[i] < env->nb_ants)
			env->arriveds[env->paths[p].ants[i]] = true;
		if (env->paths[p].ants[i] != -1 && env->paths[p].path[i] != -1)
		{
			move[0] = env->paths[p].ants[i];
			move[1] = env->paths[p].path[i];
			output_buffer(env, move, false, false);
		}
		i--;
	}
	if (env->paths[p + 1].path && env->paths[p + 1].path[0] != -1)
	{
		env->paths[p + 1].ants[0] = (env->count <= env->nb_ants && env->paths[p + 1].ammos > 0) ? (int)env->count++ : -1;
		if (env->paths[p + 1].ammos > 0)
			env->paths[p + 1].ammos--;
	}
	return (0);
}

int			crossing(t_env *env)
{
	unsigned int	i;

	env->count = 1;
	env->nb_ants++;
	while (env->count <= env->nb_ants || arriveds(env))
	{
		i = 0;
		env->paths[0].ammos--;
		env->paths[0].ants[0] = (int)env->count++;
		while (i < env->nb_paths && (env->count <= env->nb_ants || arriveds(env)))
		{
			rotate_path(env, i);
			i++;
		}
		output_buffer(env, NULL, true, false);
	}
	output_buffer(env, NULL, false, true);
	return (0);
}
