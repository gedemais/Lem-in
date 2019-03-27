/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_neurone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:31:20 by qudesvig          #+#    #+#             */
/*   Updated: 2019/03/27 18:25:45 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libia.h"

int		init_neurone(t_neurone *n, int nb_weight, double (*f)(double))
{

	n->act = f;
	n->in = 0;
	n->in = 0;
	n->nb_out = nb_weight;
	if (!(n->weight = (double*)malloc(sizeof(double) * nb_weight)))
		return (-1);
	return (0);
}
