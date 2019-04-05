/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_network.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:31:45 by qudesvig          #+#    #+#             */
/*   Updated: 2019/04/05 12:11:09 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libia.h"

int		fill_layer_size(int *dest, int *srcs)
{
	int		i;

	i = 0;
	while (i < NB_LAYER)
	{
		dest[i] = srcs[i];
		i++;
	}
	return (0);
}

int		fill_data_in(t_netw *n, double *data_in)
{
	int		i;

	i = 0;
	while (i < NB_INPUT)
	{
		n->input[i] = data_in[i];
		i++;
	}
	return (0);
}

void	fill_bias(double *bias, double *srcs)
{
	int		i;

	i = 0;
	while (i < NB_LAYER)
	{
		bias[i] = srcs[i];
		i++;
	}
}

int		init_network(t_netw *n, double *data_in, int *layer_size, double *bias)
{
	int		i;
	int		j;

	i = 0;
	if (!(n->netw = (t_neurone**)malloc(sizeof(t_neurone) * NB_LAYER))
			|| !(n->layer_size = (int*)malloc(sizeof(int) * NB_LAYER))
			|| !(n->input = (double*)malloc(sizeof(double) * NB_INPUT))
			|| !(n->bias = (double*)malloc(sizeof(double) * NB_LAYER)))
		return (-1);
	fill_layer_size(n->layer_size, layer_size);
	fill_data_in(n, data_in);
	fill_bias(n->bias, bias);
	if (!(n->out = (double*)malloc(sizeof(double) * n->layer_size[NB_LAYER - 1])))
		return (-1);
	while (i < NB_LAYER)
	{
		j = 0;
		if (!(n->netw[i] = (t_neurone*)malloc(sizeof(t_neurone) * layer_size[i])))
			return (-1);
		while (j < layer_size[i])
		{
			init_neurone(&(n->netw[i][j]),  layer_size[i + 1], id_dbl);
			if (i == 0)
			{
				n->netw[i][j].in = n->input[j];
				n->netw[i][j].out = n->netw[i][j].act(n->input[j]);
			}
			j++;
		}
		i++;
	}
	return (0);
}
