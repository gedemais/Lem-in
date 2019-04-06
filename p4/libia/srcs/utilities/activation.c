/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:50:21 by qudesvig          #+#    #+#             */
/*   Updated: 2019/04/06 17:41:47 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libia.h"

double		id_dbl(double input)
{
	return (input);
}

double		sig_dbl(double input)
{     
	double exp_value;
    double return_value;

    /*** Exponential calculation ***/
    exp_value = exp((double) -input);
    /*** Final sigmoid value ***/
    return_value = 1 / (1 + exp_value);
	return return_value;
}

double		heaviside_dbl(double input)
{
	return ((input < 0) ? 0 : 1);
}
