/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_weight.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:03:41 by qudesvig          #+#    #+#             */
/*   Updated: 2019/04/05 15:25:29 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"
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

double		**generate_weight(double **weight)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < NB_INPUT * NB_L1)
	{
		weight[i][j] = random_dbl(-1, 1);
		j++;
	}
	i++;
	j = 0;
	while (j < NB_L1 * NB_L2)
	{
		weight[i][j] = random_dbl(-1, 1);
		j++;
	}
	i++;
	j = 0;
	while (j < NB_L2 * NB_L3)
	{
		weight[i][j] = random_dbl(-1, 1);
		j++;
	}
	return (weight);
}
