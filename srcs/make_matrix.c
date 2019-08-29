#include "main.h"

static inline char	**allocate_matrix(char **matrix, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (!(matrix = (char**)malloc(sizeof(char*) * (n + 1))))
			return (NULL);
	while (i < n)
	{
		if (!(matrix[i] = (char*)malloc(sizeof(char) * (n + 1))))
			return (NULL);
		ft_memset(matrix[i], 0, sizeof(char) * n);
		i++;
	}
	return (matrix);
}

static inline char	**write_pipe(t_env *env, char *line)
{
	int				from;
	int				to;

	if ((from = find_from(env, line)) == -1)
			return (NULL);
	if ((to = find_to(env, line)) == -1)
			return (NULL);
	env->matrix[from][to] = 1;
	env->matrix[to][from] = 1;
	return (env->matrix);
}

char				**make_matrix(t_env *env, unsigned int i)
{
	char	s;

	if (!(env->matrix = allocate_matrix(env->matrix, env->nb_rooms)))
			return (NULL);
	while (env->file[i] && (s = get_line_state(&env->file[i], false)))
	{
		if (s == 'p')
			env->matrix = write_pipe(env, &env->file[i]);
		next_line(env->file, &i);
	}
	return (env->matrix);
}
