/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:05:10 by qudesvig          #+#    #+#             */
/*   Updated: 2019/04/04 18:09:51 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libia.h"

void	display_weight(t_netw n)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < NB_LAYER - 1)
	{
		k = 0;
		while (k < n.layer_size[i + 1])
		{
			j = 0;
			printf("weight going to layer %d neurone %d :\n", i, k);
			while (j < n.layer_size[i])
			{
				printf("from neurone %d : %.2f\n", j, n.netw[i][j].weight[k]);
				j++;
			}
			k++;
		}
		i++;
	}
}

void	display_inputs(t_netw n)
{
	int		i;

	i = 0;
	printf("Input of network:\n");
	while (i < n.layer_size[0])
	{
		printf("from n.inputs : %f and from neurone %d : %f\n", n.input[i], i, n.netw[0][i].in);
		i++;
	}
}

void	mapping_netw(t_netw n)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < NB_LAYER)
	{
		j = 0;
		printf("layer %d\n", i);
		while (j < n.layer_size[i])
		{
			printf("%d\t", k);
			k++;
			j++;
		}
		printf("\n");
		i++;
	}
}

void	display_outputs(t_netw n, int layer)
{
	int		i;

	i = 0;
	printf("Output of layer %d:\n", layer);
	while (i < n.layer_size[0])
	{
		printf("from neurone %d : %f\n", i, n.netw[layer][i].out);
		i++;
	}
}
