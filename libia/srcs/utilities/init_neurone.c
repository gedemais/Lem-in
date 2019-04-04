/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_neurone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:31:20 by qudesvig          #+#    #+#             */
/*   Updated: 2019/04/04 17:03:18 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libia.h"

int		init_neurone(t_neurone *n, int nb_weight, double (*f)(double))
{
	int		i;

	i = 0;
	n->act = f;
	n->in = 0;
	n->in = 0;
	n->nb_out = nb_weight;
	if (!(n->weight = (double*)malloc(sizeof(double) * nb_weight)))
		return (-1);
	while (i < nb_weight)
	{
		if (i % 4 == 0)
			n->weight[i] = 0.5;
		else if (i % 4 == 1)
			n->weight[i] = 0.2;
		else if (i % 4 == 2)
			n->weight[i] = 1;
		else
			n->weight[i] = 2;
		i++;
	}
	return (0);
}
