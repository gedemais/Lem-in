/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 21:57:38 by qudesvig          #+#    #+#             */
/*   Updated: 2019/03/08 20:08:00 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char	*ft_opt_err(int code, char *opt)
{
	if (code == 0)
		ft_putendl_fd("Error: malloc failure", 2);
	else if (code == 1)
	{
		ft_putstr_fd("Error: Bad option: authorized option [-", 2);
		ft_putstr_fd(opt, 2);
		ft_putendl_fd("]", 2);
	}
	return (NULL);
}

void	ft_putatend(char *ret, char c)
{
	int		i;

	i = 0;
	while (ret[i])
		i++;
	ret[i] = c;
}

int		ft_find(char *handle, char to_find)
{
	int		i;

	i = 0;
	if (!handle)
		return (0);
	while (handle[i])
	{
		if (handle[i] == to_find)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_scan_arg(char *opt, char *ret, char *arg, int i)
{
	while (arg[++i])
	{
		if (ft_find(opt, arg[i]) && !ft_find(ret, arg[i]))
		{
			if ((!ret && !(ret = ft_strnew(2)))
				|| (!(ret = ft_realloc(ret, ft_strlen(ret) + 1))))
				return (ft_opt_err(0, opt));
			ft_putatend(ret, arg[i]);
		}
		else if (!ft_find(ret, arg[i]) && !ft_find(opt, arg[i]))
			return (ft_opt_err(1, opt));
	}
	return (ret);
}

char	*get_opt(int ac, char **av, char *opt)
{
	char	*ret;
	int		i;
	int		j;
	int		end;

	ret = NULL;
	i = 0;
	end = 0;
	while (++i < ac && av[i][0] == '-' && end == 0)
	{
		j = 0;
		if (av[i][1] && av[i][1] == '-')
		{
			end = 1;
			j++;
		}
		if (!(ret = ft_scan_arg(opt, ret, av[i], j)))
			return (ret);
	}
	return (ret);
}
