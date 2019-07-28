/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 06:38:55 by gedemais          #+#    #+#             */
/*   Updated: 2019/07/28 19:44:26 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static inline int		lem_in(void)
{
	t_env			env;

	ft_memset(&env, 0, sizeof(env));
	if (!(env.file = read_fd_zero()) || !(env.graph = parsing(&env)))
		return (-1);
	if (bfs(&env, env.start, env.end))
	printf("%d", solve(&env));
	free_env(&env);
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
