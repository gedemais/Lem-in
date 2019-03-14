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
