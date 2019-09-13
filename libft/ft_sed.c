/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demaisonclaire <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 05:54:23 by demaisonc         #+#    #+#             */
/*   Updated: 2019/09/13 06:21:12 by demaisonc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

unsigned int	count_insts(char *str, char *needle, unsigned int len)
{
	unsigned int	i;
	unsigned int	ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (ft_strncmp(&str[i], needle, len) == 0)
			ret++;
		i++;
	}
	return (ret);
}

unsigned int	*get_insts(char *str, char *needle)
{
	unsigned int	*insts;
	unsigned int	n_i;
	unsigned int	len;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	len = ft_strlen(needle);
	if ((n_i = count_insts(str, needle, len) + 1) == 1
		|| !(insts = (unsigned int*)malloc(sizeof(unsigned int) * n_i)))
		return (NULL);
	while (str[i])
	{
		if (ft_strncmp(&str[i], needle, len) == 0)
		{
			printf("%u\n", i);
			insts[j] = i;
			j++;
		}
		i++;
	}
	return (insts);
}

char		*ft_sed(char *str, char *needle, char *replace)
{
//	char		*dest;
	unsigned int	*insts;

	if (!str || str[0] == '\0' || !needle || needle[0] == '\0' || !replace)
		return (NULL);
	if (!(insts = get_insts(str, needle)))
		return (NULL);
	return (str);
}
