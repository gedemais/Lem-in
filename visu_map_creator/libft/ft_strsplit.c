/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:20:40 by qudesvig          #+#    #+#             */
/*   Updated: 2018/11/16 17:43:20 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_splitcpy(char *dest, char const *src, char c)
{
	int		i;

	i = 0;
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

static char	*ft_firstwrd(const char *s, char c, char *str, int i)
{
	if (!(str = (char*)malloc(sizeof(char) * (ft_lensplit(&s[i], c) + 1))))
		return (NULL);
	str = ft_splitcpy(str, &s[i], c);
	return (str);
}

static char	**ft_splitsplit(char **tab, char const *s, char c, int i)
{
	int		k;

	k = 0;
	if (s[i] != c)
	{
		tab[k] = ft_firstwrd(s, c, tab[k], i);
		i += ft_lensplit(s, c);
		k++;
	}
	while (k < ft_nbwrd(s, c))
	{
		if (s[i] != c)
		{
			tab[k] = ft_firstwrd(s, c, tab[k], i);
			i += ft_lensplit(&s[i], c);
			k++;
		}
		i++;
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (!s || s[0] == 0)
	{
		if (!(tab = (char**)malloc(sizeof(char*) * 1)))
			return (NULL);
		tab[0] = 0;
	}
	else
	{
		if (!(tab = (char**)malloc(sizeof(char*) * (ft_nbwrd(s, c) + 1))))
			return (NULL);
		tab = ft_splitsplit(tab, s, c, 0);
		tab[ft_nbwrd(s, c)] = 0;
	}
	return (tab);
}
