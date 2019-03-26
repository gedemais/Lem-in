/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:51:48 by qudesvig          #+#    #+#             */
/*   Updated: 2018/11/16 19:51:26 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s;
	unsigned char	*t;

	s = (unsigned char*)s1;
	t = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (s[i] - t[i] != 0)
			return (s[i] - t[i]);
		i++;
	}
	return (0);
}
