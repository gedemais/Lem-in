/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_weight.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:03:41 by qudesvig          #+#    #+#             */
/*   Updated: 2019/04/06 18:04:10 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"
#include <time.h>
#include <math.h>
/*
double 		random_dbl(double min, double max) 
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
}*/

double		random_dbl(double min, double max)
{
	return (rand() / (double)RAND_MAX) * (max - min) + min;
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

void	ft_apply_weights(t_netw *n, double **weights)
{
	int		i;
	int		j;
	int		k;
	int		l;

	i = 0;
	while (i < NB_LAYER - 1)
	{
		j = 0;
		l = 0;
		while (j < n->layer_size[i])
		{
			k = 0;
			while (k < n->layer_size[i + 1])
			{
				n->netw[i][j].weight[k] = weights[i][l];
				k++;
				l++;
			}
			j++;
		}
		i++;
	}
}
