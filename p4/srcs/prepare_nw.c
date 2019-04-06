/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_nw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:18:23 by qudesvig          #+#    #+#             */
/*   Updated: 2019/04/06 15:12:58 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

t_netw		*prepare_init_netw(t_netw *n, char **game)
{
	double	*data;
	double	*bias;
	int		*layer_size;
	
	if ((!(data = (double*)malloc(sizeof(double) * NB_INPUT)))
		|| (!(bias = (double*)malloc(sizeof(double) * (NB_LAYER - 1))))
		|| (!(layer_size = (int*)malloc(sizeof(int) * NB_LAYER))))
		return (NULL);
	layer_size[0] = 49;
	layer_size[1] = 14;
	layer_size[2] = 14;
	layer_size[3] = 7;
	bias[0] = 1;
	bias[1] = 1;
	bias[2] = 1;
	data = extract_data_from_game(data, game);
	if (init_network(n, data, layer_size, bias))
		return (NULL);
	return (n);
}
