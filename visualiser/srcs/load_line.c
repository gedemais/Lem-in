/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 07:35:51 by gedemais          #+#    #+#             */
/*   Updated: 2019/09/09 07:45:28 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

static inline t_mlx		*load_room(t_mlx *env, unsigned int j, int room, char s)
{
	unsigned int	i;

	i = j;
	env->graph[room].type = s;
	while (env->input[i] && env->input[i] != '\n')
		i++;
	i--;
	while (ft_is_whitespace(env->input[i]) && i > 0)
		i--;
	if (i == 0 || ft_isdigit(env->input[i]) == 0)
		return (NULL);
	while (ft_isdigit(env->input[i]) && i > 0)
		i--;
	if (i == 0 || ft_is_whitespace(env->input[i]) == 0)
		return (NULL);
	env->graph[room].y = (int)ft_atoi(&env->input[i]) + 1;
	while (ft_is_whitespace(env->input[i]) && i > 0)
		i--;
	if (i == 0 || ft_isdigit(env->input[i]) == 0)
		return (NULL);
	while (ft_isdigit(env->input[i]) && i > 0)
		i--;
	if (i == 0 || ft_is_whitespace(env->input[i]) == 0)
		return (NULL);
	env->graph[room].x = (int)ft_atoi(&env->input[i]) + 1;
	while (ft_is_whitespace(env->input[i]) && i > 0)
		i--;
	if (i == 0 || !(env->graph[room].name = ft_strndup(&env->input[j],
		(int)(i - j + 1))))
		return (NULL);
	return (env);
}

int						load_line(t_mlx *env, char s, unsigned int i, int room)
{
	static bool	pipe = false;
	static bool	start = false;
	static bool	end = false;

	if (s == 's')
		start = true;
	if (s == 'e')
		end = true;
	if (s == 'p')
		pipe = true;
	if (!pipe && s == 'r')
	{
		if (start && (s = 's'))
			start = false;
		if (end && (s = 'e'))
			end = false;
		if (!(env = load_room(env, i, room, s)))
			return (1);
	}
	return (0);
}
