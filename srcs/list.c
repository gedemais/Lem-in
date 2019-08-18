/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 01:29:20 by gedemais          #+#    #+#             */
/*   Updated: 2019/08/18 04:36:54 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		print_lst(t_env *env, t_queue *lst)
{
	t_queue	*tmp;
	
	if (!lst)
			return ;
	tmp = lst;
	printf("lst :\n");
	while (tmp)
	{
		printf("%s\n", env->graph[tmp->index].name);
		tmp = tmp->next;
	}
}

t_queue		*lm_lstnew(int room)
{
	t_queue	*new;

	if (!(new = (t_queue*)malloc(sizeof(t_queue))))
		return (NULL);
	new->index = (unsigned int)room;
	new->next = NULL;
	return (new);
}

int			lm_lst_pop(t_queue **lst)
{
	t_queue	*tmp;

	tmp = (*lst);
	(*lst) = (tmp->next) ? tmp->next : NULL;
	free(tmp);
	return (0);
}

int			lm_lst_push(t_queue **lst, int index)
{
	t_queue	*tmp;

	tmp = (*lst);
	if (!*lst)
	{
		if (!(*lst = lm_lstnew(index)))
				return (-1);
		(*lst)->next = NULL;
		return (0);
	}
	while (tmp->next)
		tmp = tmp->next;
	if (!(tmp->next = lm_lstnew(index)))
			return (-1);
	tmp->next->next = NULL;
	return (0);
}

int	ft_ms_lst_pushfront(t_queue **lst, t_queue *new)
{
	t_queue	*tmp;

	if (!new || !*lst)
		return (-1);
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (0);
}
