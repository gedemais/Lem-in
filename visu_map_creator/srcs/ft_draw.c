/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 21:20:50 by qudesvig          #+#    #+#             */
/*   Updated: 2019/03/25 13:32:29 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_creator.h"

void	ft_draw_x(t_draw draw, void *param, int color)
{
	draw.cumul = draw.d.x / 2;
	while (draw.i <= draw.d.x)
	{
		draw.x.x += draw.inc.x;
		draw.cumul += draw.d.y;
		if (draw.cumul >= draw.d.x)
		{
			draw.cumul -= draw.d.x;
			draw.x.y += draw.inc.y;
		}
		draw.act.x = draw.x.x;
		draw.act.y = draw.x.y;
		ft_fill_pixel(WIN->map.map, draw.act, color);
		draw.i++;
	}
}

void	ft_draw_y(t_draw draw, void *param, int color)
{
	draw.cumul = draw.d.y / 2;
	while (draw.i <= draw.d.y)
	{
		draw.x.y += draw.inc.y;
		draw.cumul += draw.d.x;
		if (draw.cumul >= draw.d.y)
		{
			draw.cumul -= draw.d.y;
			draw.x.x += draw.inc.x;
		}
		draw.act.x = draw.x.x;
		draw.act.y = draw.x.y;
		ft_fill_pixel(WIN->map.map, draw.act, color);
		draw.i++;
	}
}

void	ft_trace_line(t_point p1, t_point p2, void *param, int color)
{
	t_draw draw;

	draw.x.x = round(p1.x);
	draw.x.y = round(p1.y);
	draw.d.x = round(p2.x - p1.x);
	draw.d.y = round(p2.y - p1.y);
	draw.inc.x = (draw.d.x > 0) ? 1 : -1;
	draw.inc.y = (draw.d.y > 0) ? 1 : -1;
	draw.d.x *= (draw.d.x > 0) ? 1 : -1;
	draw.d.y *= (draw.d.y > 0) ? 1 : -1;
	draw.i = 1;
	draw.act.x = draw.x.x;
	draw.act.y = draw.x.y;
	ft_fill_pixel(WIN->map.map, draw.act, color);
	if (draw.d.x > draw.d.y)
		ft_draw_x(draw, param, color);
	else
		ft_draw_y(draw, param, color);
}

void	ft_draw_room(void *param)
{
	t_point	tmp;

	tmp.x = WIN->map.rooms[WIN->map.nb_room].coord.x + WIN->map.squar_size;
	tmp.y = WIN->map.rooms[WIN->map.nb_room].coord.y - WIN->map.squar_size;
	WIN->map.rooms[WIN->map.nb_room].top_left.x = WIN->map.rooms[WIN->map.nb_room].coord.x - WIN->map.squar_size; 
	WIN->map.rooms[WIN->map.nb_room].top_left.y = WIN->map.rooms[WIN->map.nb_room].coord.y - WIN->map.squar_size;
	WIN->map.rooms[WIN->map.nb_room].bottom_right.x = WIN->map.rooms[WIN->map.nb_room].coord.x + WIN->map.squar_size; 
	WIN->map.rooms[WIN->map.nb_room].bottom_right.y = WIN->map.rooms[WIN->map.nb_room].coord.y + WIN->map.squar_size;
	ft_trace_line(tmp, WIN->map.rooms[WIN->map.nb_room].top_left, WIN, 0xFFFFFF);
	ft_trace_line(tmp, WIN->map.rooms[WIN->map.nb_room].bottom_right, WIN, 0xFFFFFF);
	tmp.x = WIN->map.rooms[WIN->map.nb_room].coord.x - WIN->map.squar_size;
	tmp.y = WIN->map.rooms[WIN->map.nb_room].coord.y + WIN->map.squar_size;
	ft_trace_line(tmp, WIN->map.rooms[WIN->map.nb_room].top_left, WIN, 0xFFFFFF);
	ft_trace_line(tmp, WIN->map.rooms[WIN->map.nb_room].bottom_right, WIN, 0xFFFFFF);
}

void	ft_draw_link(void *param, int r1, int r2)
{
	ft_trace_line(WIN->map.rooms[r1].coord, WIN->map.rooms[r2].coord, param, 0xFFFFFF);
}
