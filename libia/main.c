/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:35:49 by qudesvig          #+#    #+#             */
/*   Updated: 2019/04/04 18:23:57 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libia.h"

int		main(void)
{
	t_netw netw;
	double *data;
	int		*layer_size;
	double	*out;

	if (!(data = (double*)malloc(sizeof(double) * 4)))
		return (EXIT_FAILURE);
	if (!(layer_size = (int*)malloc(sizeof(int) * 2)))
		return (EXIT_FAILURE);
	data[0] = 0.5;
	data[1] = 0.3;
	data[2] = 0;
	data[3] = 0.9;
	layer_size[0] = 4;
	layer_size[1] = 4;
	if (init_network(&netw, data, layer_size))
	{
		printf("error init network\n");
		return (EXIT_FAILURE);
	}
	//display_weight(netw);
	//display_inputs(netw);
	out = firing(&netw);
	//display_outputs(netw, 1);
	printf("in of last out : %f\n", netw.netw[1][0].in);
	printf("fire network 0 : %f\n", out[0]);
	printf("fire network 1: %f\n", out[1]);
	printf("fire network 2: %f\n", out[2]);
	printf("fire network 3: %f\n", out[3]);
	return (0);
}
