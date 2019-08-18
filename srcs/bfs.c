/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 01:19:43 by gedemais          #+#    #+#             */
/*   Updated: 2019/08/18 04:45:30 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void				print_path(t_env *env, int *path)
{
	unsigned int	i;

	i = 1;
	printf("Path :\n");
	printf("%s\n", env->graph[0].name);
	while (path[i] != -1 || i < 10)
	{
		if (path[i] != -1)
			printf("%s\n", env->graph[path[i]].name);
		else
			printf("%d\n", path[i]);
		i++;
	}
}
/*
static inline int	*cpy_q(t_queue *queue, int *path)
{
	t_queue			*tmp;
	unsigned int	len;

	len = 0;
	tmp = queue;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	tmp = queue;
	while (tmp)
	{
		path[len] = (int)tmp->index;
		tmp = tmp->next;
		len--;
	}
	return (path);
}*/

bool				breadth_first_search(t_env *env)
{
	t_queue		*queue;
	int			u;
	int			v;

	u = 0;
	v = 0;
	ft_memset(env->visited, false, sizeof(bool) * env->nb_rooms); // Flush visited rooms
	ft_memset(env->parent, -1, sizeof(int) * env->nb_rooms + 1); // Flush visited rooms
	if (!(queue = lm_lstnew(env->start)))
			return (false);
	env->visited[env->start] = true; // Note the start room as visited
	while (queue)
	{
		printf("Top\n");
		u = (int)queue->index;
		lm_lst_pop(&queue);
		print_lst(env, queue);
		v = 0;
		while (v < (int)env->nb_rooms)
		{
			if (env->visited[v] == false && env->r_matrix[u][v] > 0)
			{
				lm_lst_push(&queue, v);
				env->visited[v] = true;
				env->parent[v] = u;
				printf("v = %s\n", env->graph[v].name);
				print_path(env, env->parent);
				print_lst(env, queue);
			}
			v++;
		}
	}
	return (env->visited[env->end]);
}
