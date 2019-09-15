#include "main.h"

static inline int	flush_buffer(char buffer[BUFF_WRITE], int *index)
{
	write(1, buffer, (size_t)(*index));
	*index = 0;
	ft_memset(&buffer[0], 0, sizeof(char) * BUFF_WRITE);
	return (0);
}
/*
static inline char	*ant_itoa(char *buff, int *index, int n)
{
	return (buff);
}

static inline int	ant_itoa(char *dest, long long int n)
{
	long long int	nbr;
	int				size;

	if (n == 0)
	{
		dest[0] = '0';
		dest[1] = '\0';
		return (0);
	}
	size = (n < 0) ? 1 : 0;
	nbr = (n < 0) ? -n : n;
	n = nbr;
	while (nbr > 0 && ++size)
		nbr = nbr / 10;
	dest[size] = '\0';
	while (n > 0)
	{
		dest[--size] = (n % 10) + '0';
		n = n / 10;
	}
	dest[0] = (size) ? '-' : dest[0];
	return (0);
}*/


int					output_buffer(t_env *env, int move[2], bool n_l, bool f)
{
	static char		buff[BUFF_WRITE];
	static int		index = 0;
//	char			tmp[ANT_NLEN];
	char			*tmp;

	if (move && move[0] >= env->nb_ants)
		return (0);
	if (f || index >= BUFF_WRITE)
		return (flush_buffer(buff, &index));
	if (n_l && --index)
	{
		buff[index++] = '\n';
		return (0);
	}
	if (!(tmp = ft_itoa(move[0])))
		return (1);
	if ((3 + ft_strlen(tmp) + ft_strlen(env->graph[move[1]].name) + (unsigned long)index) > BUFF_WRITE)
		flush_buffer(buff, &index);
	buff[index++] = 'L';
	ft_strcat(&buff[index], tmp);
	index += ft_strlen(tmp);
	buff[index++] = '-';
	ft_strcat(&buff[index], env->graph[move[1]].name);
	index += ft_strlen(env->graph[move[1]].name);
	buff[index++] = ' ';
	free(tmp);
	return (0);
}
