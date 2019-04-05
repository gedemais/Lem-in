/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libia.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:04:23 by qudesvig          #+#    #+#             */
/*   Updated: 2019/04/05 14:22:25 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBIA_H
# define LIBIA_H
# include "../../libft/libft.h"
# include "neural_network.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <pthread.h>

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

//struct for multithread firing
typedef struct		s_fire
{
	int			i;
	int			j;
	int			k;
	pthread_t	th[4];
}					t_fire;

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
	t_fire			fire;
	int				nbth;
}					t_netw;

//init env neural network
int					init_neurone(t_neurone *n, int nb_weight, double (*f)(double));
int					init_network(t_netw *n, double *data_in, int *layer_size, double *bias);

//activation function
double				id_dbl(double input);
double				sig_dbl(double input);
double				heaviside_dbl(double input);

double				*firing(t_netw *n);
double				neurone_output(t_neurone n, int out);
void				apply_weight(t_netw *n, double *weight);

void				mapping_netw(t_netw n);
void				display_weight(t_netw n);
void				display_inputs(t_netw n);
void				display_outputs(t_netw n, int layer);

int					export_weight(t_netw n);
#endif
