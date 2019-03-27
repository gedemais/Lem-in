/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libia.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:04:23 by qudesvig          #+#    #+#             */
/*   Updated: 2019/03/27 18:23:25 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBIA_H
# define LIBIA_H
# include "../../visu_map_creator/libft/libft.h"
# include "neural_network.h"
# include <stdio.h>

typedef	struct		s_neurone
{
	int				nb_out;
	//res of wi * xi + bias
	double			in;
	//activating function
	double			(*act)(double);
	double			out;
	//weight to next layer
	double			*weight;
}					t_neurone;


typedef struct		s_netw
{
	t_neurone		**netw;
	//size of each layer
	int				*layer_size;
	//data input
	double			*input;
	//bias per layer
	double			*bias;
	//data output
	double			*out;
}					t_netw;

//init env neural network
int					init_neurone(t_neurone *n, int nb_weight, double (*f)(double));
int					init_network(t_netw *n, double *data_ini, int *layer_size);

//activation function
double				id_dbl(double input);
double				sig_dbl(double input);
double				heaviside_dbl(double input);

#endif
