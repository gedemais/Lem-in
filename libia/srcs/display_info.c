/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:05:10 by qudesvig          #+#    #+#             */
/*   Updated: 2019/03/27 18:15:29 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libia.h"

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
		}
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
