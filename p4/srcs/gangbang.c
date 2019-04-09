/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gangbang.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 10:57:21 by qudesvig          #+#    #+#             */
/*   Updated: 2019/04/09 10:57:33 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	ft_bornes(int *min, int *max)
{
	int		random;

	random = rand() % 7;
	*min = random * 49;
	*max = (random + 1) * 49;
}

void	ft_influence(t_popu *pop, int flush, int comeback)
{
	static int		i = 0;
	int		min;
	int		max;
	int		j;
	int		pos;

	(void)comeback;
	j = 0;
	if (flush)
	{
		i = 0;
		return ;
	}
	if ((pos = ft_find_next(pop, 0)) == -1)
		return ;
	ft_bornes(&min, &max);
	while (j < 343)
	{
		pop->pop[pos].weight[0][j] = pop->pop[pop->elite[i]].weight[0][j];
		if (j >= min && j <= max)
			pop->pop[pos].weight[0][j] += random_dbl(-1.0, 1.0);
		j++;
	}
	i++;
}

void	ft_source(t_popu *pop, int pos, double **save)
{
	int		i;
	int		min;
	int		max;

	i = 0;
	ft_bornes(&min, &max);
	while (i < 343)
	{
		pop->pop[pos].weight[0][i] = save[0][i];
		if (i >= min && i <= max)
			pop->pop[pos].weight[0][i] += random_dbl(-0.1, 0.1);
		i++;
	}
}

void	ft_gangbang(t_popu *pop, double **save, int comeback)
{
	int		to_inf;
	int		i;
	int		pos;

	i = 0;
	to_inf = (int)pop->fitness + 10;
	while (i < to_inf)
	{
		ft_influence(pop, 0, comeback);
		i++;
	}
	while (i < 343)
	{
		if ((pos = ft_find_next(pop, 0)) != -1)
			ft_source(pop, pos, save);
		i++;
	}
	ft_influence(pop, 1, comeback);
	ft_find_next(pop, 1);
}
