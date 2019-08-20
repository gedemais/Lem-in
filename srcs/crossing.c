#include "main.h"

static inline void	flush_moves(char *buffer)
{
	unsigned int	i;

	i = BUFF_WRITE;
	while (buffer[i] == '\0')
		i--;
	write(1, buffer, i);
	buffer = ft_memset(buffer, 0, sizeof(char) * BUFF_WRITE);
}

static inline int	store_moves(t_env *env, int ant, int room, bool new_line)
{
	static int	index = 0;
	unsigned int	len;
	char		*tmp;

	if (new_line)
	{
		if (ant == -1)
			flush_moves(env->moves);
		else
			env->moves[index++] = '\n';
		return (0);
	}
	if ((!env->moves && !(env->moves = ft_strnew(BUFF_WRITE)))
		|| !(tmp = ft_itoa(ant)))
		return (-1);
	len = (unsigned int)(1 + ft_strlen(tmp) + 1 + ft_strlen(env->graph[room].name) + 1);
	if (index + (int)len > BUFF_WRITE)
		flush_moves(env->moves);
	env->moves[index++] = 'L';
	ft_strcat(&env->moves[index], tmp);
	index += ft_strlen(tmp);
	free(tmp);
	env->moves[index++] = '-';
	ft_strcat(&env->moves[index], env->graph[room].name);
	index += ft_strlen(env->graph[room].name);
	env->moves[index++] = ' ';
	return (0);
}

static inline void	rotate_path(t_env *env, unsigned int p)
{
	unsigned int	i;

	i = 0;
	env->paths[p].ants[i] = (int)env->count;
	while (env->paths[p].path[i] != env->end)
	{
		env->paths[p].ants[i + 1] = env->paths[p].ants[i];
		if (store_moves(env, env->paths[p].ants[i], env->paths[p].path[i + 1], false) != 0)
			return ;
		i++;
	}
	if (store_moves(env, env->paths[p].ants[i], env->end, true) != 0)
		return ;
	env->count++;
}

int					crossing(t_env *env)
{
	unsigned int	i;
	int				k;
	int				epoch = 0;

	env->count = 0;
	while (env->count < env->nb_ants)
	{
//		printf("Epoch %d\n", epoch);
		i = 0;
		while (env->paths[i].path && env->paths[i].path[0] != -1)
		{
//			printf("path %u :\n", i);
			rotate_path(env, i);
			k = 0;
			while (env->paths[i].path[k] != -1)
			{
//				printf("%s : %d\n", env->graph[env->paths[i].path[k]].name, env->paths[i].ants[k]);
				k++;
			}
//			printf("\n---------------\n");
			i++;
		}
		epoch++;
	}
	store_moves(env, -1, 0, true);
	return (0);
}
