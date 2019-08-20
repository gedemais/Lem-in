#include "main.h"

static inline int	store_moves(t_env *env, int ant, int room, bool new_line)
{
	static int	index = 0;
	static int	size = BUFF_READ;
	char		*tmp;

	i = 0;
	if (!env->moves && !(env->moves = ft_strnew(BUFF_READ)))
		return (-1);
	env->moves[index++] = 'L';
	if (!(tmp = ft_itoa(ant)))
		return (-1);
	ft_strcat(&env->moves[index], tmp);
	index += ft_strlen(tmp);
	free(tmp);
	env->moves[index++] = new_line ?i '\n' : ' ';
	return (0);
}
