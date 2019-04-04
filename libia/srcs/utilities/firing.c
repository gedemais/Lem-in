/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:01:45 by qudesvig          #+#    #+#             */
/*   Updated: 2019/04/04 18:26:28 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libia.h"

double		*last_out(t_neurone *n, int nb_out)
{
	double	*outs;
	int		i;

	printf("Computing last layer output\n");
	if (!(outs = (double*)malloc(sizeof(double) * nb_out)))
		return (NULL);
	i = 0;
	while (i < nb_out)
	{
		outs[i] = n[i].act(n[i].in);
		n[i].out = outs[i];
		printf("input at neurone %d = %f\noutput = %f\n", i, n[i].in, n[i].out);
		i++;
	}
	return (outs);
}

double		*firing(t_netw *n)
{
	int		k;
	int		i;
	int		j;

	i = 0;
	//for each layer
	while (i < NB_LAYER - 1)
	{
		j = 0;
		//for each neurone of layer i + 1
		while (j < n->layer_size[i + 1])
		{
			n->netw[i + 1][j].in = n->bias[i];
			printf("bias of layer %d = %f\n", i + 1, n->bias[i]);
			k = 0;
			//for each neurone of layer i
			while (k < n->layer_size[i])
			{
				//neurone j at layer i + 1 += output de neurone k at layer i * weight to neurone j
				n->netw[i + 1][j].in += n->netw[i][k].out * n->netw[i][k].weight[j];
				printf("at neurone %d input of neurone %d = %f\n", k, j, n->netw[i + 1][j].in);
				k++;
			}
			n->netw[i + 1][j].out = n->netw[i + 1][j].act(n->netw[i + 1][j].in);
			j++;
		}
		display_outputs(*n, i);
		i++;
	}
	printf("at the end i = %d\n", i);
	return (last_out(n->netw[i], n->layer_size[i]));
}
