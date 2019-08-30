#include "main.h"

static inline t_env		*load_room(t_env *env, unsigned int j, int room, char s)
{
	unsigned int	i;

	i = j;
	env->graph[room].type = s;
	env->graph[room].index = (unsigned int)room;
	while (env->file[i] && env->file[i] != '\n')
		i++;
	i--;
	while (ft_is_whitespace(env->file[i]) && i > 0)
		i--;
	if (i == 0 || ft_isdigit(env->file[i]) == 0)
		return (NULL);
	while (ft_isdigit(env->file[i]) && i > 0)
		i--;
	if (i == 0 || ft_is_whitespace(env->file[i]) == 0)
		return (NULL);
	env->graph[room].y = (int)ft_atoi(&env->file[i]);
	while (ft_is_whitespace(env->file[i]) && i > 0)
		i--;
	if (i == 0 || ft_isdigit(env->file[i]) == 0)
		return (NULL);
	while (ft_isdigit(env->file[i]) && i > 0)
		i--;
	if (i == 0 || ft_is_whitespace(env->file[i]) == 0)
		return (NULL);
	env->graph[room].x = (int)ft_atoi(&env->file[i]);
	while (ft_is_whitespace(env->file[i]) && i > 0)
		i--;
	if (i == 0 || !(env->graph[room].name = ft_strndup(&env->file[j], (int)(i - j + 1))))
		return (NULL);
	return (env);
}

int		load_line(t_env *env, char s, unsigned int i, int room)
{
	static bool	pipe = false;
	static bool	start = false;
	static bool	end = false;

	if (s == 'c')
		return (0);
	else if (s == 's')
		start = true;
	else if (s == 'e')
		end = true;
	else if (s == 'p')
		pipe = true;
	else if (!pipe && s == 'r')
	{
		if (start && (s = 's'))
			start = false;
		if (end && (s = 'e'))
			end = false;
		if (!(env = load_room(env, i, room, s)))
			return (1);
	}
	else
		return (-1);
	return (0);
}
