/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 20:56:41 by qudesvig          #+#    #+#             */
/*   Updated: 2019/03/26 11:22:29 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_creator.h"

void	ft_init_env(void *env, int fd)
{
	t_map	map;

	ENV->len = WDT;
	ENV->fd = fd;
	ENV->height = HEI;
	ENV->mlx_ptr = mlx_init();
	ENV->win_ptr = mlx_new_window(ENV->mlx_ptr, ENV->len, ENV->height, "Lemin Map Creator");
	map.img_ptr = mlx_new_image(ENV->mlx_ptr, ENV->len, ENV->height);
	map.map = mlx_get_data_addr(map.img_ptr, &(map.bpp),
			&(map.size_line), &(map.endian));
	map.rooms = NULL;
	map.nb_room = -1;
	map.squar_size = 10;
	ENV->map = map;
}
