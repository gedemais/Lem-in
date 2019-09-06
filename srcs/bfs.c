/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 01:19:43 by gedemais          #+#    #+#             */
/*   Updated: 2019/09/06 06:29:11 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
/*
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

bool				breadth_first_search(t_env *env, int s, int e, bool up)
{
	t_queue		*queue;
	int			u;
	int			v;

	if (!(queue = lm_lstnew(s)))
		return (false);
	env->visited[s] = true;
	env->parent[0] = -1;
//	printf("Start\n");
	while (queue)
	{
//		printf("Pre-pop :\n");
//		print_queue(env, queue);
		u = (int)queue->index;
		lm_lst_pop(&queue);
	//	printf("Post-pop :\n");
	//	print_queue(env, queue);
		v = up ? -1 : (int)env->nb_rooms;
		while ((up && ++v < (int)env->nb_rooms) || (!up && --v >= 0))
			if (env->visited[v] == false && env->matrix[u][v] > 0)
			{
		//		printf("Pre-push :\n");
		//		print_queue(env, queue);
				if (lm_lst_push(&queue, v) != 0)
					return (false);
			//	printf("Post-push :\n");
			//	print_queue(env, queue);
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
