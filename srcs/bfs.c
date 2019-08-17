/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 01:19:43 by gedemais          #+#    #+#             */
/*   Updated: 2019/08/17 05:21:57 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_path(int *path)
{
	unsigned int	i;

	i = 1;
	printf("Start\n");
	while (path[i] != -1 && i < 10)
	{
		printf("%d\n", path[i]);
		i++;
	}
}

bool	breadth_first_search(t_env *env)
{
	t_queue		*queue;
	int			u;
	int			v;

	ft_memset(env->visited, false, sizeof(bool) * env->nb_rooms); // Flush visited rooms
	ft_memset(env->parent, -1, sizeof(int) * env->nb_rooms + 1); // Flush visited rooms
	if (!(queue = lm_lstnew(env->start)))
			return (false);
	env->visited[env->start] = true; // Note the start room as visited
	while (queue)
	{
		u = (int)(*queue).index;
		printf("u = %d\n", u);
		lm_lst_pop(&queue);
		v = 0;
		while ((unsigned int)v < env->nb_rooms)
		{
			if (env->visited[v] == false && env->r_matrix[u][v] > 0)
			{
				lm_lst_push(&queue, lm_lstnew(v));
				env->parent[v] = u;
				env->visited[v] = true;
			}
			v++;
		}
	}
	print_path(env->parent);
	return (env->visited[env->end]);
}
