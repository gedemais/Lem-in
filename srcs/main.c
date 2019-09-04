/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 06:38:55 by gedemais          #+#    #+#             */
/*   Updated: 2019/09/04 07:16:58 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static inline int		init_env(t_env *e)
{
	ft_memset(e, 0, sizeof(t_env));
	if (!(e->file = read_fd_zero(&e->file_len))  || !(e->graph = parsing(e)))
		return  (-1);
	if  (!(e->visited = (bool*)malloc(sizeof(bool) * e->nb_rooms))
		|| !(e->parent = (int*)malloc(sizeof(int) * (e->nb_rooms + 1)))
		|| !(e->arriveds = (bool*)malloc(sizeof(bool) * (unsigned)(e->nb_ants + 1))))
		return (-1);
	ft_memset(e->arriveds, false, sizeof(bool) * (unsigned int)(e->nb_ants + 1));
	return (0);
}

static inline int		lem_in(t_env *env)
{
	if (init_env(env) == -1 
		|| (env->max_flow = edmond_karp(env)) <= 0)
		return (-1);
		
	if (treat_paths(env) != 0)
		return (-1);
	ft_putendl(env->file);
	if (crossing(env) != 0)
		return (-1);
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
