/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 01:19:43 by gedemais          #+#    #+#             */
/*   Updated: 2019/08/19 06:35:55 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
/*
   static inline int	get_queue_back(t_queue *queue)
   {
	t_queue	*tmp;

	tmp = queue;
	if (!queue->next)
			return ((int)queue->index);
	while (tmp->next)
		tmp = tmp->next;
	return ((int)tmp->index);
}

static inline void	print_queue(t_env *env, t_queue *queue)
{
		t_queue	*tmp;

		tmp = queue;
		while (queue)
		{
				printf("%s\n", env->graph[queue->index].name);
				queue = queue->next;
		}
		printf("\n");
}*/

bool				breadth_first_search(t_env *env, int s, int e)
{
	t_queue		*queue;
	int			u;
	int			v;

	if (!(queue = lm_lstnew(s)))
		return (false);
	env->visited[s] = true;
	while (queue)
	{
		u = (int)queue->index;
		lm_lst_pop(&queue);
		v = -1;
		while (++v < (int)env->nb_rooms)
			if (env->visited[v] == false && env->matrix[u][v] > 0)
			{
				if (lm_lst_push(&queue, v) != 0)
					return (false);
				env->parent[v] = u;
				env->visited[v] = true;
				if (v == e)
				{
					lm_lstdel(queue);
					return (true);
				}
			}
	}
	lm_lstdel(queue);
	return (false);
}
