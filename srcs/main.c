/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 06:38:55 by gedemais          #+#    #+#             */
/*   Updated: 2019/08/19 07:54:21 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static inline int		lem_in(t_env *env)
{
	ft_memset(env, 0, sizeof(env));
	if (!(env->file = read_fd_zero()) || !(env->graph = parsing(env)))
		return (-1);
	if (!(env->visited = (bool*)malloc(sizeof(bool) * env->nb_rooms))
		|| !(env->parent = (int*)malloc(sizeof(int) * (env->nb_rooms + 1))))
		return (false);
	if ((env->max_flow = edmond_karp(env)) <= 0)
			return (-1);
/*	int	 i = 0;
	while (env->paths[i] && env->paths[i][0] != -1)
	{
		printf("Path[%d] :\n", i);
		print_path(env, env->paths[i]);
		printf("\n");
		i++;
	}*/
//	if (env->nb_ants < env->max_flow)

	free_env(env);
	return (0);
}

int						main(void)
{
	t_env	env;

	if (lem_in(&env) == -1)
	{
		free_env(&env);
		ft_putstr("ERROR\n");
		return (1);
	}
	return (0);
}
