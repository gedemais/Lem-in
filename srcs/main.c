/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:50:58 by gedemais          #+#    #+#             */
/*   Updated: 2019/03/13 21:21:28 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lmbf.h"

int		ft_lmbf(char *file_name)
{
//	t_room	*map;
	t_map	var;
	char	*input;
	int		fd;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (-1);
	if (!(input = ft_read(fd)))
		return (-1);
	ft_putstr(input);
	ft_count_rooms(input, &var);
	ft_putnbr(var.nb_rooms);

//	if (!(map = ft_loadmap(input, &var)))
//		return (-1);
//	ft_putnbr(ft_solve(map, &var));
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		if (ft_lmbf(argv[1]) != 0)
			return (1);
	return (0);
}
