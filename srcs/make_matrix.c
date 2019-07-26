#include "main.h"

void	add_bit(unsigned int *integer, unsigned int bit)
{
	static unsigned int		vals[INT_BITS] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512,
		1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288,
		1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864,
		134217728, 268435456, 536870912, 1073741824, 2147483648};
	*integer += vals[bit];
}

unsigned int		**allocate_matrix(t_env *env)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = (env->nb_rooms / 32) + 1;
	if (!(env->matrix = (unsigned int**)malloc(sizeof(unsigned int*) * len)))
			return (NULL);
	while (i < len)
	{
		if (!(env->matrix[i] = (unsigned int*)malloc(sizeof(unsigned int)
			* env->nb_rooms)))
		env->matrix[i] = ft_memset(env->matrix[i], 0, sizeof(unsigned int)
			* env->nb_rooms);
			return (NULL);
		i++;
	}
	return (env->matrix);
}

static inline unsigned int	**write_pipe(t_env *env, char *line)
{
	int				from;
	int				to;
	unsigned int	which;

	if ((from = find_from(env, line)) == -1)
			return (NULL);
	if ((to = find_to(env, line)) == -1)
			return (NULL);
	env->matrix[][to]
	return (env->matrix);
}

unsigned int		**make_matrix(t_env *env, unsigned int i)
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
