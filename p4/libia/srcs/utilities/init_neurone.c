/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_neurone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:31:20 by qudesvig          #+#    #+#             */
/*   Updated: 2019/04/06 17:20:26 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libia.h"

static double 		random_dbl(double min, double max) 
{
	double randomNumber;
	double range;
	double tempRan;
	double finalRan;

	srand( (unsigned int) time(NULL) );
	randomNumber = (double)rand() / (double)RAND_MAX;
	range = max - min;
	tempRan = randomNumber * range;
	finalRan = tempRan + min;
	return (finalRan);
}

int		init_neurone(t_neurone *n, int nb_weight, double (*f)(double))
{
	int		i;

	i = 0;
	n->act = f;
	n->in = 0;
	n->in = 0;
	n->nb_out = nb_weight;
	if (nb_weight == 0)
		return (0);
	if (!(n->weight = (double*)malloc(sizeof(double) * nb_weight)))
		return (-1);
	while (i < nb_weight)
	{
		n->weight[i] = random_dbl(-5, 5);
		i++;
	}
	return (0);
}
