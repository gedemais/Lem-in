#include "main.h"

static inline t_env		*load_room(t_env *env, unsigned int i, int room)
{
	(void)i;
	(void)room;
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
	else if (!(env = load_room(env, i, room)))
		return (1);
	return (0);
}
