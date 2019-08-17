/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 06:38:55 by gedemais          #+#    #+#             */
/*   Updated: 2019/08/17 01:42:45 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <assert.h>

static inline int		lem_in(t_env *env)
{
	ft_memset(env, 0, sizeof(env));
	if (!(env->file = read_fd_zero()) || !(env->graph = parsing(env)))
		return (-1);
	if (!(env->visited = (bool*)malloc(sizeof(bool) * env->nb_rooms))
		|| !(env->parent = (int*)malloc(sizeof(int) * (env->nb_rooms + 1))))
		return (false);
	if (!breadth_first_search(env))
			printf("No path found !\n");
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
