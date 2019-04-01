/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:01:45 by qudesvig          #+#    #+#             */
/*   Updated: 2019/04/01 16:56:52 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libia.h"

double		neurone_output(t_neurone n, int out)
{
	return (n.act(n.in) * n.weight[out]);
}

double		*last_out(t_neurone *n, int nb_out)
{
	double	*outs;
	int		i;

	if (!(outs = (double*)malloc(sizeof(double) * nb_out)))
		return (NULL);
	i = 0;
	while (i < nb_out)
	{
		outs[i] = n[i].act(n[i].in);
		i++;
	}
	return (outs);
}

double		*firing(t_netw n)
{
	int		i;
	int		j;
	int		k;
	double	out;

	i = 0;
	while (i < NB_LAYER - 1)
	{
		j = 0;
		while (j < n.layer_size[i + 1])
		{
			k = 0;
			out = 0;
			while (k < n.layer_size[i])
			{
				out += neurone_output(n.netw[i][k], j);
				k++;
			}
			n.netw[i + 1][j].in = out;
		}
		i++;
	}
	return (last_out(n.netw[i], n.layer_size[i]));
}
