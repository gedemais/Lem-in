/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:22:01 by gedemais          #+#    #+#             */
/*   Updated: 2019/03/13 21:21:43 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lmbf.h"

char	*ft_read(int fd)
{
	char	buff[BUFF_READ + 1];
	char	*dest;
	int		ret;
	int		size;
	int		i;

	i = 0;
	size = 0;
	if (!(dest = ft_strnew(0)))
		return (NULL);
	while ((ret = read(fd, buff, BUFF_READ)) > 0)
	{
		size += ret;
		if (ret == -1 || !(dest = ft_strrealloc(dest, size)))
			return (NULL);
		buff[ret] = '\0';
		dest = ft_strcat(dest, buff);
		i++;
	}
	return (dest);
}

void	ft_print_map(t_room *map)
{
	int		i;

	i = 0;
	while (map[i].x != -42)
	{
		ft_putstr("##### ");
		ft_putnbr(map[i].index);
		ft_putstr(" #####\n");
		ft_putendl(map[i].name);
		ft_putstr("x : ");
		ft_putnbr(map[i].x);
		ft_putchar('\n');
		ft_putstr("y : ");
		ft_putnbr(map[i].y);
		ft_putchar('\n');
		ft_putstr("lock : ");
		ft_putnbr(map[i].lock);
		ft_putchar('\n');
		ft_putstr("start : ");
		ft_putnbr(map[i].start);
		ft_putchar('\n');
		ft_putstr("end : ");
		ft_putnbr(map[i].end);
		ft_putchar('\n');
		i++;
	}
}

