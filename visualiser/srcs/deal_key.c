/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 07:35:36 by gedemais          #+#    #+#             */
/*   Updated: 2019/09/09 07:43:47 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void		hud(t_mlx *env)
{
	char	*tmp;

	if (!(tmp = ft_strnew(10)))
		return ;
	sprintf(tmp, "%.2f\n", env->speed);
	mlx_string_put(env->mlx_ptr, env->mlx_win, 10, 50, 0xFFFFFF, "Speed :");
	mlx_string_put(env->mlx_ptr, env->mlx_win, 100, 50, 0xFFFFFF, tmp);
	free(tmp);
}

int			deal_key(int key, void *param)
{
	if (key == 69 && ((t_mlx*)param)->speed < 4.99)
		((t_mlx*)param)->speed += 0.01;
	else if (key == 78 && ((t_mlx*)param)->speed > 0.06)
		((t_mlx*)param)->speed -= 0.01;
	return (0);
}
