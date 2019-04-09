/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_weight.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:57:04 by qudesvig          #+#    #+#             */
/*   Updated: 2019/04/01 17:38:54 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libia.h"

int			export_weight(t_netw n)
{
	int		i;
	int		j;
	int		k;
	int		fd;

	if ((fd = open("fichier", O_CREAT | O_WRONLY, 0777)))
		return (-1);
	i = -1;
	while (++i < NB_LAYER - 1)
	{
		j = -1;
		while (++j < n.layer_size[i + 1])
		{
			k = -1;
			while (++k < n.layer_size[i])
				dprintf(fd, "%f\t", n.netw[i][j].weight[k]);
			dprintf(fd, "\n");
		}
		dprintf(fd, "\n");
	}
	close(fd);
	return (0);
}
