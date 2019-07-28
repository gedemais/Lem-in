#include "main.h"

bool					find_start_end(t_env *env)
{
	unsigned int	i;

	i = 0;
	env->start = -1;
	env->end = -1;
	while (i < env->nb_rooms)
	{
		if (env->graph[i].type == 's')
					env->start = (int)i;
		else if (env->graph[i].type == 'e')
					env->end = (int)i;
		i++;
	}
	if (env->start == -1 || env->end == -1)
			return (true);
	return (false);
}

static inline t_queue	*queue_lstnew(unsigned int index)
{
	t_queue		*new;

	if (!(new = (t_queue*)malloc(sizeof(t_queue))))
			return (NULL);
	new->index = index;
	return (new);
}

static inline int		queue_push(t_queue **queue, t_queue *new)
{
	t_queue		*tmp;

	tmp = *queue;
	new->next = *queue;
	*queue = new;
	return (0);
}

static inline int		queue_pop(t_queue **queue)
{
	t_queue	*tmp;

	tmp = (*queue)->next;
	free(*queue);
	*queue = tmp;
	return (0);
}
/*
static inline void		print_lst(t_queue *queue)
{
	t_queue	*tmp = queue;

		while (tmp)
		{
			printf("%d\n", tmp->index);
			tmp = tmp->next;
		}
				printf("\n");
}*/

bool					bfs(t_env *env, int s, int t)
{
	t_queue			*queue;
	unsigned int	room;
	unsigned int	i;

	room = 0;
	if (!(queue = queue_lstnew((unsigned int)s)))
			return (false);
	queue->next = NULL;
//	env->visited = ft_memset(env->visited, false, sizeof(bool) * env->nb_rooms);
	env->parent = ft_memset(env->parent, -1, sizeof(int) * env->nb_rooms);
	env->visited[s] = true;
	while (queue)
	{
		i = 0;
		room = queue->index;
		queue_pop(&queue);
		while (i < env->nb_rooms)
		{
			if (env->visited[i] == false && env->r_matrix[room][i] > 0)
			{
				queue_push(&queue, queue_lstnew(i));
		//		print_lst(queue);
				env->parent[i] = (int)room;
				env->visited[i] = true;
			}
			i++;
		}
	}
	return (env->visited[t] ? true : false);
}
