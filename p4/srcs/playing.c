/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:24:54 by qudesvig          #+#    #+#             */
/*   Updated: 2019/04/06 17:26:54 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

double		*extract_data_from_game(double *data, char **game)
{
	int		i;
	int		j;

	i = 0;
	while (i < 7)
	{
		j = 0;
		while (j < 7)
		{
			if (game[i][j] == '.')
				data[i * 7 + j] = 0;
			else if (game[i][j] == 'X')
				data[i * 7 + j] = 1;
			else
				data[i * 7 + j] = 2;
			j++;
		}
		i++;
	}
	return (data);
}


