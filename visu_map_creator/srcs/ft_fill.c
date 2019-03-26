/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:45:37 by qudesvig          #+#    #+#             */
/*   Updated: 2019/03/25 13:35:27 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_creator.h"

char	*ft_fill_pixel(char *map, t_point coord, int color)
{
	int		i;

	if (coord.y <= 0 || coord.x <= 0 || coord.y >= HEI || coord.x >= WDT)
		return (map);
	i = ((round(coord.y) - 1) * WDT + round(coord.x)) * 4;
	map[i] = color >> 16 & 255;
	map[i + 1] = color >> 8 & 255;
	map[i + 2] = color & 255;
	return (map);
}

bool		ft_is_start(t_room *rooms, int nb_room)
{
	int		i;

	i = 0;
	while (i <= nb_room)
	{
		if (rooms[i].start == true)
			return (true);
		i++;
	}
	return (false);
}

void		ft_fill_square(void *param, int room, bool start)
{
	t_point		xtmp;
	t_point		x2tmp;
	int			i;

	xtmp.x = WIN->map.rooms[room].top_left.x;
	xtmp.y = WIN->map.rooms[room].top_left.y;
	x2tmp.x = WIN->map.rooms[room].top_left.x;
	x2tmp.y = WIN->map.rooms[room].bottom_right.y;
	i = 0;
	while (i < 20)
	{
		xtmp.x++;
		x2tmp.x++;
		ft_trace_line(xtmp, x2tmp, param, (start == true) ? 0x32CD32 : 0xFF0000);
		i++;
	}
}

t_room		*ft_start_end(void *param, int x, int y)
{
	int		room;
	int		i;
	bool	start;

	i = 0;
	start = ft_is_start(WIN->map.rooms, WIN->map.nb_room);
	if ((room = ft_is_in(param, x, y)) == -1 || start == true)
		return (WIN->map.rooms);
	while (i < room)
		i++;
	if (start == false)
		WIN->map.rooms[i].start = true;
	else
		WIN->map.rooms[i].end = true;
	ft_fill_square(WIN, room, start);
	return (WIN->map.rooms);
}
