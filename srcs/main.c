/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 06:38:55 by gedemais          #+#    #+#             */
/*   Updated: 2019/07/23 07:05:30 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static inline int		lem_in(void)
{
	char	*file;
	t_room	*graph;

	if (!(file = read_fd_zero()) || !(graph = parsing(file)))
		return (-1);
	return (0);
}

int						main(void)
{
	if (lem_in() == -1)
	{
		ft_putstr("ERROR\n");
		return (1);
	}
	return (0);
}
