/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:50:21 by qudesvig          #+#    #+#             */
/*   Updated: 2019/03/27 17:15:08 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libia.h"

double		id_dbl(double input)
{
	return (input);
}

double		sig_dble(double input)
{
	double exp;

	exp = (input + 1 / input) * input;
	return (1 / 1 + exp);
}

double		heaviside_dbl(double input)
{
	return ((input < 0) ? 0 : 1);
}
