#include "main.h"

static inline char		get_room_type(int s_e)
{
	if (s_e == 0)
		return ('r');
	if (s_e == 1)
		return ('s');
	if (s_e == 2)
		return ('e');
	return (0);
}

static inline t_env		*load_room(t_env *env, unsigned int j, int room, int s_e)
{
	unsigned int	i;

	i = j;
	env->graph[room].type = get_room_type(s_e);
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
	printf("Room %d :\nName = %s\nx = %d\ny = %d\n\n", room, env->graph[room].name, env->graph[room].x, env->graph[room].y);
	return (env);
}

static inline t_env		*load_pipe(t_env *env, unsigned int i)
{
	(void)i;
	return (env);
}

int		load_line(t_env *env, char s, unsigned int i, int room)
{
	static bool	pipe = false;

	if (s == 'p')
		pipe = true;
	if (pipe)
	{
		if (!(env = load_pipe(env, i)))
			return (1);
		return (0);
	}
	else if (!(env = load_room(env, i, room, s)))
		return (1);
	return (0);
}
