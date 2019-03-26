/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:28:52 by qudesvig          #+#    #+#             */
/*   Updated: 2018/11/15 11:25:39 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	if (c == 0)
		return ((char*)&s[i]);
	i--;
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char*)&s[i]);
		i--;
	}
	return (NULL);
}
