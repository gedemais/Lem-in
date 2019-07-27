#include "main.h"

char						**allocate_matrix(t_env *env)
{
	unsigned int	i;

	i = 0;
	if (!(env->matrix = (char**)malloc(sizeof(char*) * env->nb_rooms)))
			return (NULL);
	while (i < env->nb_rooms)
	{
		if (!(env->matrix[i] = (char*)malloc(sizeof(char)
			* env->nb_rooms)))
			return (NULL);
		ft_memset(env->matrix[i], 0, sizeof(char) * env->nb_rooms);
		i++;
	}
	return (env->matrix);
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
/*
static inline void			print_matrix(t_env *env)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < env->nb_rooms)
	{
		j = 0;
		while (j < env->nb_rooms)
		{
			ft_putnbr(env->matrix[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}*/

char					**make_matrix(t_env *env, unsigned int i)
{
	char	s;

	if (!(env->matrix = allocate_matrix(env)))
			return (NULL);
	while (env->file[i] && (s = get_line_state(&env->file[i], false)))
	{
		if (s == 'p')
			env->matrix = write_pipe(env, &env->file[i]);
		next_line(env->file, &i);
	}
	return (env->matrix);
}
