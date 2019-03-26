/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:16:32 by qudesvig          #+#    #+#             */
/*   Updated: 2018/11/16 11:09:20 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoasize(int n)
{
	int		ret;
	long	tmp;

	ret = 0;
	tmp = n;
	if (tmp < 0)
	{
		ret++;
		tmp *= -1;
	}
	while (tmp >= 10)
	{
		ret++;
		tmp %= 10;
	}
	return (ret + 1);
}

static char	*ft_strrev(char *s)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	i--;
	while (i > j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		j++;
		i--;
	}
	return (s);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		i;
	long	tmp;
	int		sign;

	i = 0;
	sign = 0;
	if (!(ret = (char*)malloc(sizeof(char) * (ft_itoasize(n) + 2))))
		return (NULL);
	tmp = n;
	if (tmp < 0)
	{
		sign = -1;
		tmp *= -1;
	}
	while (tmp >= 10)
	{
		ret[i] = tmp % 10 + 48;
		i++;
		tmp /= 10;
	}
	ret[i] = tmp + 48;
	ret[i + 1] = (sign == -1) ? '-' : '\0';
	ret[i + 2] = '\0';
	return (ft_strrev(ret));
}
