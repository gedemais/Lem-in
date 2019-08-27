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

t_ant	*make_ants(t_mlx *env)
{
	unsigned int	i;
	unsigned int	start;

	i = 0;
	start = 0;
	if (!(env->ants = (t_ant*)malloc(sizeof(t_ant) * env->nb_ants)))
		return (NULL);
	while (start < env->nb_ants && env->graph[start].type != 's')
		start++;
	while (i < env->nb_ants)
	{
		env->ants[i].id = i;
		env->ants[i].pos.x = env->graph[start].x;
		env->ants[i].pos.y = env->graph[start].y;
		i++;
	}
	return (env->ants);
}

int		ft_set_env(t_mlx *env)
{
	srand(time(0));
	env->room_size = 20;
	env->nb_pipes = 1;
	env->speed = 3;
	env->nb_ants = (unsigned int)ft_atoi(env->input);
	if (!(env->mlx_ptr = mlx_init()))
		return (-1);
	if (!(env->mlx_win = mlx_new_window(env->mlx_ptr, WDT, HGT, "Lem_in visualiser")))
		return (-1);
	if (!(env->img_ptr = mlx_new_image(env->mlx_ptr, WDT, HGT)))
		return (-1);
	if (!(env->img_data = mlx_get_data_addr(env->img_ptr, &env->bpp,
					&env->s_l, &env->endian)))
		return (-1);
	return (0);
}

int		toultemps(void *param)
{
	t_mlx			*env;

	env = ((t_mlx*)param);
	while (env->input[env->i])
	{
		cross_ant(env, env->graph[1], 0);
		next_line(&env->input[env->i], &env->i);
	}
	render(env);
	mlx_put_image_to_window(env, env->mlx_win, env->img_ptr, 0, 0);
//	usleep(100000);
	return (0);
}

int		visualiser(void)
{
	t_mlx			env;
	int				i;

	i = 0;
	if (ft_set_env(&env) == -1)
		return (-1);
	if (!(env.input = read_fd_zero(&env.file_size))
		|| !(env.graph = make_graph(&env, &i))
		|| !(env.pipes = make_pipes(&env, &i))
		|| !(env.ants = make_ants(&env)))
		return (-1);
	env->i = i;
//	mlx_hook(env.mlx_win, KEY_PRESS, KEY_PRESS_MASK, ft_deal_key, &env);
//	mlx_hook(env.mlx_win, 4, (1L << 2), ft_press, &env);
//	mlx_hook(env.mlx_win, 6, 0, ft_pos, &env);
	mlx_loop_hook(env.mlx_ptr, &toultemps, &env);
	mlx_hook(env.mlx_win, 17, (1L << 17), ft_exit, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}

int		main(void)
{
	if (visualiser() == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}
