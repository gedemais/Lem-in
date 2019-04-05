/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p4.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:01:19 by qudesvig          #+#    #+#             */
/*   Updated: 2019/04/05 14:02:12 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P4_H
# define P4_H

#include "../../libia/includes/libia.h"

typedef struct		s_indiv
{
	double			**weight;
	double			*bias;
	double			*out;
	double			fitness;
}					t_indiv;

typedef struct		s_popu
{
	t_indiv			*pop;
	int				index_best;
}					t_popu;

double				*extract_data_from_game(double *data, char **game);
t_netw				*prepare_init_netw(t_netw *n, char **game);
char				**ft_init_chess(void);

#endif
