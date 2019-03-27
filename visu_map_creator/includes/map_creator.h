/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:11:38 by qudesvig          #+#    #+#             */
/*   Updated: 2019/03/27 12:30:44 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CREATOR_H
# define MAP_CREATOR_H
# include "mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# define WIN ((t_win*)param)
# define ENV ((t_win*)env)
# define IMG ((t_win*)(param))->map.img_ptr
# define MAP ((t_map*)stru)

# define WDT 1080
# define HEI 720

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef	struct	s_room
{
	int		nb_links;
	int		*link;
	bool	start;
	bool	end;
	t_point	coord;
	t_point	top_left;
	t_point	bottom_right;
}				t_room;

typedef	struct	s_draw
{
	t_point		d;
	int			i;
	int			cumul;
	t_point		act;
	t_point		x;
	t_point		inc;
}				t_draw;

typedef struct	s_map
{
	char		*map;
	void		*img_ptr;
	int			bpp;
	int			endian;
	int			size_line;
	int			squar_size;
	int			nb_room;
	t_room		*rooms;
}				t_map;

typedef struct	s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			len;
	int			height;
	t_point		mid;
	t_map		map;
	int			fd;
}				t_win;

void			ft_usage(void);
void			ft_clean(void *param);

void			map_creator(char *file);
int				ft_event_key(int key, void *param);
void			ft_init_env(void *env, int fd);

char			*ft_fill_pixel(char *map, t_point coord, int color);
void			ft_trace_line(t_point p1, t_point p2, void *param, int color);
void			ft_draw_room(void *param);
void			ft_draw_link(void *param, int r1, int r2);

t_room			*ft_new_room(int x, int y, void *param);
t_room			*ft_start_end(void *param, int x, int y);
int				ft_new_link(int x, int y, void *param, int links_hit);
int				ft_mouse_event(int button, int x, int y, void *param);
int				ft_is_in(void *param, int x, int y);

void			ft_export(int fd, void *param);
void			ft_free_env(t_map *map);

void			ft_display_infos(t_room *room, int nb_room);

void			ft_error(void);
#endif
