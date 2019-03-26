/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 02:09:23 by qudesvig          #+#    #+#             */
/*   Updated: 2019/02/24 05:51:44 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_guess_pivot(int *tab, int start, int end)
{
	int		i;
	int		j;
	int		pivot;

	j = 0;
	pivot = tab[end - 1];
	i = -1;
	while (start + j < end && start + i < end)
	{
		if (tab[start + j] < pivot && i < j)
		{
			i++;
			ft_swap(&tab[start + i], &tab[start + j]);
		}
		j++;
	}
	ft_swap(&tab[start + i + 1], &tab[end - 1]);
	return (i + 1);
}

void	quick_sort(int *tab, int start, int end)
{
	int		j;

	j = 0;
	if (end - start > 2)
	{
		j = ft_guess_pivot(tab, start, end);
		quick_sort(tab, 0, j);
		quick_sort(&tab[j], 0, end - j);
	}
	else if (end - start == 2)
	{
		if (tab[start] > tab[end - 1])
			ft_swap(&tab[start], &tab[end - 1]);
	}
}
