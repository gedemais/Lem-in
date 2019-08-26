/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:43:03 by gedemais          #+#    #+#             */
/*   Updated: 2019/06/10 22:13:58 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"
#include "stdio.h"

int		ft_set_env(t_mlx *env)
{
	srand(time(0));
	env->room_size = 5;
	if (!(env->graph = (t_room*)malloc(sizeof(t_room) * 2)))
		return (-1);
	for (int i = 0; i < 2; i++)
	{
		env->graph[i].x = rand() % WDT;
		env->graph[i].y = rand() % HGT;
	}
	env->nb_pipes = 1;
	if (!(env->pipes = (t_pipe*)malloc(sizeof(t_pipe) * 1)))
		return (-1);
	env->pipes[0].start = 0;
	env->pipes[0].end = 1;
	if (!(env->mlx_ptr = mlx_init()))
		return (-1);
	if (!(env->mlx_win = mlx_new_window(env->mlx_ptr, WDT, HGT, "Fract'ol")))
		return (-1);
	if (!(env->img_ptr = mlx_new_image(env->mlx_ptr, WDT, HGT)))
		return (-1);
	if (!(env->img_data = mlx_get_data_addr(env->img_ptr, &env->bpp,
					&env->s_l, &env->endian)))
		return (-1);
	return (0);
}

int		visualiser(void)
{
	t_mlx		env;

	if (ft_set_env(&env) == -1)
		return (-1);
	render(&env);
	mlx_put_image_to_window(&env, env.mlx_win, env.img_ptr, 0, 0);
//	mlx_hook(env.mlx_win, KEY_PRESS, KEY_PRESS_MASK, ft_deal_key, &env);
//	mlx_hook(env.mlx_win, 4, (1L << 2), ft_press, &env);
//	mlx_hook(env.mlx_win, 6, 0, ft_pos, &env);
	mlx_hook(env.mlx_win, 17, (1L << 17), ft_exit, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}

int		main(int argc, char **argv)
{
	if (visualiser() == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}
