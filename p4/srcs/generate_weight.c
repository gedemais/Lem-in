/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_weight.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:03:41 by qudesvig          #+#    #+#             */
/*   Updated: 2019/04/09 11:00:05 by qudesvig         ###   ########.fr       */
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
	while (j < NB_INPUT * 7)
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

double	**ft_save_weights(double **weight, double **best)
{
	int		i;

	i = 0;
	while (i < (49 * 7))
	{
		best[0][i] = weight[0][i];
		i++;
	}
	return (best);
}

void	ft_export_weigths(double **weights)
{
	char		*tmp;
	int		fd;
	int		i;

	i = 0;
	fd = open("weights", O_CREAT | O_WRONLY, 777);
	while (i < 343)
	{
		dprintf(fd, "%f\n", weights[0][i]);
		ft_strdel(&tmp);
		i++;
	}
	close(fd);
	exit (EXIT_SUCCESS);
}
