/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 06:38:55 by gedemais          #+#    #+#             */
/*   Updated: 2019/07/23 23:58:36 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static inline int		lem_in(void)
{
	t_env	env;

	if (!(env.file = read_fd_zero()) || parsing(&env) != 0)
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
