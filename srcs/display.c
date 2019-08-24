#include "main.h"

static inline void	flush_buffer(char buffer[BUFF_WRITE])
{
	unsigned int	i;

	i = BUFF_WRITE - 1;
	while (buffer[i] == '\0')
		i--;
	write(1, buffer, i);
	ft_memset(&buffer[0], 0, sizeof(char) * BUFF_WRITE);
}

static inline int	store_move(t_env *env, int ant, int room, bool newline)
{
	static char buff[BUFF_WRITE];
	static int	index = 0;
	char		*tmp;

	buff[0] = '\0';
	if (newline)
	{
		buff[index++] = '\n';
		return (0);
	}
	if (!(tmp = ft_itoa(ant))) // Bricoler
		return (-1);
	if (ft_strlen(tmp) + ft_strlen(env->graph[room].name) + 3 + (unsigned int)index > BUFF_WRITE)
	{
		flush_buffer(buff);
		index = 0;
	} // Donner &buff[index] a strcat pour eviter des iterations.
	ft_strcat(buff, "L");
	ft_strcat(buff, tmp);
	ft_strcat(buff, "-");
	ft_strcat(buff, env->graph[room].name);
	ft_strcat(buff, " ");
	while (buff[index])
		index++;
	return (0);
}

static inline unsigned int	get_max_len(t_env *env)
{
	unsigned int	len;
	unsigned int	i;
	unsigned int	j;

	len = 0;
	i = 0;
	while (env->path_moves[i])
	{
		j = 0;
		while (env->path_moves[i][j] != -1)
			j++;
		if (j > len)
			len = j;
		i++;
	}
	return (len);
}

int		display_moves(t_env *env)
{
	unsigned int	len;
	unsigned int	i;
	unsigned int	j;

	len = get_max_len(env);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (env->path_moves[j])
		{
			if (env->path_moves[j][i] != -1 && env->path_moves[j][i + 1] != -1)
			{
				store_move(env, env->path_moves[j][i], env->path_moves[j][i + 1], false);
			}
			j++;
		}
		store_move(env, 0, 0, true);
		i += 2;
	}
	return (0);
}

