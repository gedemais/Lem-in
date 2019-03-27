/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 11:10:32 by qudesvig          #+#    #+#             */
/*   Updated: 2019/03/27 12:34:18 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_creator.h"

void	ft_export_links(void *param, int fd)
{
	int		i;
	int		j;

	i = 0;
	ft_putendl_fd("#links", fd);
	while (i < WIN->map.nb_room)
	{
		j = 0;
		while (j < WIN->map.rooms[i].nb_links)
		{
			if (WIN->map.rooms[i].link[j] > i)
			{
				ft_putnbr_fd(i, fd);
				ft_putchar_fd('-', fd);
				ft_putnbr_fd(WIN->map.rooms[i].link[j], fd);
				ft_putchar_fd('\n', fd);
			}
			j++;
		}
		i++;
	}
}

void	ft_export(int fd, void *param)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i <= WIN->map.nb_room)
	{
		if (WIN->map.rooms[i].start == true)
			ft_putendl_fd("##start", fd);
		else if (WIN->map.rooms[i].end == true)
			ft_putendl_fd("##end", fd);
		ft_putnbr_fd(i, fd);
		ft_putchar_fd(' ', fd);
		ft_putnbr_fd(WIN->map.rooms[i].coord.x, fd);
		ft_putchar_fd(' ', fd);
		ft_putnbr_fd(WIN->map.rooms[i].coord.y, fd);
		ft_putchar_fd('\n', fd);
		i++;
	}
	ft_export_links(param, fd);
}

void	ft_free_env(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->nb_room)
	{
		free(map->rooms[i].link);
		i++;
	}
	free(map->rooms);
}
