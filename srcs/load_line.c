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
//	printf("Room %d :\nName = %s\nx = %d\ny = %d\n\n", room, env->graph[room].name, env->graph[room].x, env->graph[room].y);
	return (env);
}

static inline t_env		*load_pipe(t_env *env, unsigned int i)
{
	int				from;
	int				to;

	if ((from = find_from(env, &env->file[i])) == -1 || 
		(to = find_to(env, &env->file[i])) == -1)
			return (NULL);
	env->graph[from].pipes[env->nb_pipes[from] - 1] = (unsigned int)to;
	env->graph[to].pipes[env->nb_pipes[to] - 1] = (unsigned int)from;
	env->nb_pipes[from]--;
	env->nb_pipes[to]--;
	return (env);
}

int		load_line(t_env *env, char s, unsigned int i, int room)
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
	if (pipe && s == 'p')
	{
		if (!(env = load_pipe(env, i)))
			return (1);
		return (0);
	}
	else if (!pipe && s == 'r')
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
