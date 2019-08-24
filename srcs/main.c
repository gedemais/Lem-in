/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 06:38:55 by gedemais          #+#    #+#             */
/*   Updated: 2019/08/20 03:59:31 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
static inline void		print_paths(t_env *env, t_path *paths)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (paths[i].path && paths[i].path[0] != -1)
	{
		j = 0;
		printf("--- Path %u ---\n%u edges\n", i, paths[i].len);
		while (paths[i].path[j] != -1)
		{
			printf("%s\n", env->graph[paths[i].path[j]].name);
			j++;
		}
		printf("----------------\n");
		i++;
	}
}*/

static inline int		lem_in(t_env *env)
{
	ft_memset(env, 0, sizeof(env));
	if (!(env->file = read_fd_zero(&env->file_len)) || !(env->graph = parsing(env))
		|| !(env->visited = (bool*)malloc(sizeof(bool) * env->nb_rooms))
		|| !(env->parent = (int*)malloc(sizeof(int) * (env->nb_rooms + 1))))
		return (-1);
	if ((env->max_flow = edmond_karp(env)) <= 0)
			return (-1);
//	print_paths(env, env->paths);
	ft_putendl(env->file);
	if (crossing(env) != 0)
			return (-1);
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
