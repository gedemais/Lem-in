/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_weight.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:03:41 by qudesvig          #+#    #+#             */
/*   Updated: 2019/04/05 14:12:24 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/p4.h"
#include <time.h>
#include <math.h>

double random_dbl(double min, double max) 
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

double		*generate_weight(double *weight)
{
	int		i;

	i = 0;
	while (i < NB_NEURONE)
	{
		weight[i] = random_dbl(-1, 1);
		i++;
	}
	return (weight);
}
