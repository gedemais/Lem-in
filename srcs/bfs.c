/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 01:19:43 by gedemais          #+#    #+#             */
/*   Updated: 2019/08/17 01:47:29 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	breadth_first_search(t_env *env)
{
	t_queue		*queue;

	ft_memset(env->visited, 0, sizeof(bool) * env->nb_rooms); // Flush visited rooms
	if (!(queue = lm_lstnew(env->start)))
			return (false);
	env->visited[env->start] = env->start;
	print_lst(queue);
	return (true);
}
