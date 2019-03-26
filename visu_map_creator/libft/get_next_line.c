/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 08:32:26 by qudesvig          #+#    #+#             */
/*   Updated: 2019/02/24 05:37:10 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_adjust(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	ft_bzero(str, i + 1);
	i++;
	while (str[i])
	{
		str[j] = str[i];
		i++;
		j++;
	}
	ft_bzero(&str[j], i - j);
}

int		ft_check_endl(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_realloc(char *line, unsigned int size)
{
	char	*tmp;

	if (!(tmp = ft_strnew(size)))
		return (NULL);
	ft_strncpy(tmp, line, size);
	free(line);
	return (tmp);
}

char	*ft_read(const int fd, char *str, unsigned int cycle)
{
	char			*s;
	size_t			len;
	char			tmp[BUFF_SIZE + 1];
	int				len_tmp;

	len = (str) ? ft_strlen(str) : 0;
	if (!(s = ft_strnew(BUFF_SIZE + 1 + len)))
		return (NULL);
	if (str)
		s = ft_strncat(s, str, len);
	free(str);
	while ((len_tmp = read(fd, tmp, BUFF_SIZE)) > 0 && ++cycle)
	{
		tmp[len_tmp] = 0;
		if (!(s = ft_realloc(s, (cycle + 1) * BUFF_SIZE)))
			return (NULL);
		ft_strncat(s, tmp, len_tmp);
		ft_bzero((void*)tmp, BUFF_SIZE + 1);
		if (ft_check_endl(s) == 0)
			return (s);
	}
	if (len_tmp < 0)
		return (NULL);
	return (s);
}

int		get_next_line(const int fd, char **line)
{
	static char		*str[4865] = {NULL};
	size_t			len_tmp;

	if (fd < 0 || BUFF_SIZE < 1 || !line || fd >= 4865)
		return (-1);
	if (str[fd] == NULL || !str[fd][0] || ft_check_endl(str[fd]))
		if (!(str[fd] = ft_read(fd, str[fd], 0)))
			return (-1);
	if (!str[fd][0])
		return (0);
	len_tmp = ft_lensplit(str[fd], '\n');
	if (!(*line = ft_strnew(len_tmp)))
		return (-1);
	*line = ft_strncat(*line, str[fd], len_tmp);
	ft_adjust(str[fd]);
	if (str[fd][0] == '\0')
		ft_strdel(&str[fd]);
	return (1);
}
