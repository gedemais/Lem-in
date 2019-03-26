/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:59:14 by qudesvig          #+#    #+#             */
/*   Updated: 2018/11/06 18:09:13 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	char			*s;
	char			*u;

	u = (char*)dst;
	s = (char*)src;
	i = 0;
	if (s > u)
		while (len--)
		{
			u[i] = s[i];
			i++;
		}
	else
		while (len--)
			u[len] = s[len];
	return ((void*)u);
}
