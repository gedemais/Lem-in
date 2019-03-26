/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:47:24 by qudesvig          #+#    #+#             */
/*   Updated: 2018/11/06 17:59:42 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *s;
	char *ret;

	s = (char*)src;
	ret = (char*)dst;
	while (n--)
		ret[n] = s[n];
	return (dst);
}
