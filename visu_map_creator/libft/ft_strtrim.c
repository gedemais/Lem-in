/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:20:49 by qudesvig          #+#    #+#             */
/*   Updated: 2018/11/15 17:22:01 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sizetrim(char const *s)
{
	size_t	size;
	int		i;

	size = ft_strlen(s);
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		i++;
		size--;
	}
	i = ft_strlen(s);
	i--;
	while (i >= 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		i--;
		size--;
	}
	return (size);
}

char			*ft_strtrim(char const *s)
{
	char	*ret;
	int		i;
	size_t	size;
	int		j;
	int		k;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s);
	k = 0;
	size = ft_sizetrim(s);
	if (size == ft_strlen(s))
		return (ft_strdup(s));
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (!s[i])
		return (ft_strdup(""));
	if (!(ret = ft_strsub(s, i, size)))
		return (NULL);
	ret[size] = 0;
	return (ret);
}
