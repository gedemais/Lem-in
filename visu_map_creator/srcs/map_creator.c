/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:19:20 by qudesvig          #+#    #+#             */
/*   Updated: 2019/03/26 16:56:34 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_creator.h"

void	ft_error(void)
{
	ft_putstr_fd("map error\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_exit(void *param, int fd)
{
	ft_export(fd, param);
	ft_free_env(&(WIN->map));
	mlx_destroy_image(WIN->mlx_ptr, WIN->map.img_ptr);
	mlx_destroy_window(((t_win*)param)->mlx_ptr, ((t_win*)param)->win_ptr);
	exit(EXIT_SUCCESS);
}

int		ft_event_key(int key, void *param)
{
	if (key == 53)
		ft_exit(param, WIN->fd);
	return (0);
}

int		ft_mouse_event(int button, int x, int y, void *param)
{
	static int	links_hits = 2;

	if (button == 1)
		WIN->map.rooms = ft_new_room(x, y, param);
	else if (button == 2)
	{
		links_hits--;
		ft_new_link(x, y, param, links_hits);
		if (links_hits == 0)
			links_hits = 2;
	}
	else if (button == 3)
		WIN->map.rooms = ft_start_end(param, x, y);
	mlx_put_image_to_window(WIN->mlx_ptr, WIN->win_ptr, WIN->map.img_ptr, 0, 0);
	return (0);
}

void	map_creator(char *file)
{
	t_win	win;
	int		fd;
	void	*ft_ex;

	ft_ex = &ft_exit;
	fd = open(file, O_CREAT | O_WRONLY, 0777);
	ft_init_env(&win, fd);
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.map.img_ptr, 0, 0);
	mlx_hook(win.win_ptr, 2, 1L << 0, ft_event_key, &win);
	mlx_mouse_hook(win.win_ptr, ft_mouse_event, &win);
	mlx_hook(win.win_ptr, 17, 1L << 17, ft_ex, &win);
	mlx_loop(win.mlx_ptr);
}
