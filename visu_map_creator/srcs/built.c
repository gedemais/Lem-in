/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:30:42 by qudesvig          #+#    #+#             */
/*   Updated: 2019/03/27 11:52:55 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_creator.h"

t_room	*ft_realloc_rooms(t_win *param, int x, int y)
{
	t_room		*tmp;
	int			i;
	int			j;

	i = 0;
	if (!(tmp = (t_room*)malloc(sizeof(t_room) * (WIN->map.nb_room + 2))))
		return (NULL);
	while (i < WIN->map.nb_room)
	{
		if (WIN->map.rooms[i].nb_links == 0)
			tmp[i].link = NULL;
		else
		{
			if (!(tmp[i].link = (int*)malloc(sizeof(int) * WIN->map.rooms[i].nb_links)))
				return (NULL);
			j = 0;
			while (j < WIN->map.rooms[i].nb_links)
			{
				printf("liens vers salle %d\n", WIN->map.rooms[i].link[j]);
				tmp[i].link[j] = WIN->map.rooms[i].link[j];
				j++;
			}
			free(WIN->map.rooms[i].link);
		}
		tmp[i].coord.x = WIN->map.rooms[i].coord.x;
		tmp[i].coord.y = WIN->map.rooms[i].coord.y;
		tmp[i].top_left.x = WIN->map.rooms[i].top_left.x;
		tmp[i].top_left.y = WIN->map.rooms[i].top_left.y;
		tmp[i].bottom_right.x = WIN->map.rooms[i].bottom_right.x;
		tmp[i].bottom_right.y = WIN->map.rooms[i].bottom_right.y;
		tmp[i].nb_links = WIN->map.rooms[i].nb_links;
		tmp[i].start = WIN->map.rooms[i].start;
		tmp[i].end = WIN->map.rooms[i].end;
		i++;
	}
	tmp[i].link = NULL;
	tmp[i].coord.x = x;
	tmp[i].coord.y = y;
	tmp[i].top_left.y = y - 10;
	tmp[i].top_left.x = x - 10;
	tmp[i].bottom_right.y = y + 10;
	tmp[i].bottom_right.x = x + 10;
	tmp[i].nb_links = 0;
	tmp[i].start = false;
	tmp[i].end = false;
	free(WIN->map.rooms);
	WIN->map.rooms = tmp;
	return (tmp);
}

t_room	*ft_new_room(int x, int y, void *param)
{
	WIN->map.nb_room += 1;
	if (!(WIN->map.rooms))
	{
		if (!(WIN->map.rooms = (t_room*)malloc(sizeof(t_room))))
			return (NULL);
		WIN->map.rooms[0].top_left.x = x - 10;
		WIN->map.rooms[0].top_left.y = y - 10;
		WIN->map.rooms[0].bottom_right.x = x + 10;
		WIN->map.rooms[0].bottom_right.y = y + 10;
		WIN->map.rooms[0].start = false;
		WIN->map.rooms[0].end = false;
		WIN->map.rooms[0].nb_links = 0;
	}
	else
	{
		if (!(WIN->map.rooms = ft_realloc_rooms(WIN, x, y)))
			return (NULL);
	}
	WIN->map.rooms[WIN->map.nb_room].coord.x = x;
	WIN->map.rooms[WIN->map.nb_room].coord.y = y;
	WIN->map.rooms[WIN->map.nb_room].top_left.x = x - 10;
	WIN->map.rooms[WIN->map.nb_room].top_left.y = y - 10;
	WIN->map.rooms[WIN->map.nb_room].bottom_right.x = x + 10;
	WIN->map.rooms[WIN->map.nb_room].bottom_right.y = y + 10;
	WIN->map.rooms[WIN->map.nb_room].nb_links = 0;
	ft_display_infos(WIN->map.rooms, WIN->map.nb_room);
	ft_draw_room(WIN);
	return (WIN->map.rooms);
}

int		ft_is_in(void *param, int x, int y)
{
	int		i;

	i = 0;
	while (i <= WIN->map.nb_room)
	{
		if (x >= (int)WIN->map.rooms[i].top_left.x && x <= (int)WIN->map.rooms[i].bottom_right.x
				&& y >= (int)WIN->map.rooms[i].top_left.y && y <= (int)WIN->map.rooms[i].bottom_right.y)
			return (i);
		i++;
	}
	return (-1);
}

int		*ft_realloc_links(void *param, int r1)
{
	int		*tmp;
	int		i;

	i = 0;
	if (!(tmp = (int*)malloc(sizeof(int) * (WIN->map.rooms[r1].nb_links + 1))))
		return (NULL);
	while (i < WIN->map.rooms[r1].nb_links - 1 && WIN->map.rooms[r1].link[i] != -1)
	{
		tmp[i] = WIN->map.rooms[r1].link[i];
		i++;
	}
	tmp[i] = -1;
	if (WIN->map.rooms[r1].nb_links > 1)
		free(WIN->map.rooms[r1].link);
	return (tmp);
}

int		ft_new_link(int x, int y, void *param, int links_hit)
{
	static int	first = -1;
	int			scnd;

	scnd = -1;
	if (links_hit == 1)
		if ((first = ft_is_in(param, x, y)) == -1)
			return (0);
	if (links_hit == 0)
	{
		if ((scnd = ft_is_in(param, x, y)) == -1 || first == scnd)
			return (0);
		WIN->map.rooms[first].nb_links++;
		WIN->map.rooms[scnd].nb_links++;
		if (!(WIN->map.rooms[first].link = ft_realloc_links(param, first))
				|| !(WIN->map.rooms[scnd].link = ft_realloc_links(param, scnd)))
			return (-1);
		WIN->map.rooms[first].link[WIN->map.rooms[first].nb_links - 1] = scnd;
		WIN->map.rooms[scnd].link[WIN->map.rooms[scnd].nb_links - 1] = first;
		ft_draw_link(param, first, scnd);
		first = -1;
	}
	return (0);
}
