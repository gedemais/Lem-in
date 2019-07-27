#include "main.h"

char						**allocate_matrix(t_env *env)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = (env->nb_rooms / 32) + (unsigned int)1;
	if (!(env->matrix = (unsigned int**)malloc(sizeof(unsigned int*) * len)))
			return (NULL);
	while (i < len)
	{
		if (!(env->matrix[i] = (unsigned int*)malloc(sizeof(unsigned int)
			* env->nb_rooms)))
			return (NULL);
		i++;
	}
	return (env->matrix);
}

static inline unsigned int	**write_pipe(t_env *env, char *line)
{
	int				from;
	int				to;
	int				which;

	if ((from = find_from(env, line)) == -1)
			return (NULL);
	if ((to = find_to(env, line)) == -1)
			return (NULL);
	return (env->matrix);
}

char					**make_matrix(t_env *env, unsigned int i)
{
	char	s;

	if (!(env->matrix = allocate_matrix(env)))
			return (NULL);
	print_matrix(env);
	while (env->file[i] && (s = get_line_state(&env->file[i], false)))
	{
		if (s == 'p')
			env->matrix = write_pipe(env, &env->file[i]);
		next_line(env->file, &i);
	}
	return (env->matrix);
}
