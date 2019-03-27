/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:47:44 by qudesvig          #+#    #+#             */
/*   Updated: 2019/03/27 11:53:11 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_creator.h"

void	ft_display_infos(t_room *room, int nb_room)
{
	int		i;
	int		j;

	i = 0;
	while (i <= nb_room)
	{
		j = 0;
		printf("room n%d\n", i);
		printf("coord mid = %d %d\n", (int)room[i].coord.x, (int)room[i].coord.y);
		printf("coord top = %d %d\n", (int)room[i].top_left.x, (int)room[i].top_left.y);
		printf("coord bottom = %d %d\n", (int)room[i].bottom_right.x, (int)room[i].bottom_right.y);
		printf("nb_links = %d\n", room[i].nb_links);
		while (j < room[i].nb_links)
		{
			printf("liens vers salle %d\n", room[i].link[j]);
			j++;
		}
		printf("start = %d end = %d\n", room[i].start, room[i].end);
		i++;
	}
}
