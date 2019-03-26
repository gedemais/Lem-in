/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:41:25 by qudesvig          #+#    #+#             */
/*   Updated: 2019/03/22 16:16:11 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_creator.h"

int		main(int ac, char **av)
{
	if (ac == 2)
		map_creator(av[1]);
	else
		ft_usage();
	return (0);
}
