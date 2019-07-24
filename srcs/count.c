#include "main.h"

static inline unsigned int	get_name_len(char *line, bool last)
{
	unsigned int	i;
	unsigned int	ret;

	i = 0;
	ret = 0;
	while (line[i] && line[i] != '\n' && line[i] != '-')
		i++;
	if (last)
	{
		while (line[i + ret] && line[i + ret] != '\n')
			ret++;
		return (ret);
	}
	else
		return (i);

}

/*
** Find the index of a room by chasing its name in the file string
*/
static inline int		find_from(t_env *env, char *line)
{
	unsigned int	i;
	unsigned int	len;
	int		ret;
	char		s;

	i = 0;
	ret = 0;
	s = 0;
	len = get_name_len(line, false);
	while (env->file[i] && (s = get_line_state(&env->file[i], false)))
	{
		if (s == 'p' && ft_strncmp(&env->file[i], line, len) == 0)
			return (ret);
		while (env->file[i] && env->file[i] != '\n')
			i++;
		i++;
		ret++;
	}
	if (s == 0)
		return (-1);
	return (ret);
}

static inline int		find_to(t_env *env, char *line)
{
	unsigned int	i;
	unsigned int	len;
	int		ret;
	char		s;
	
	i = 0;
	ret = 0;
	s = 0;
	len = get_name_len(line, false);
	while (env->file[i] && (s = get_line_state(&env->file[i], false)))
	{
		while (env->file[i] && env->file[i] != '\n' && env->file[i] != '-')
			i++;
		i++;
		if (s == 'p' && ft_strncmp(&env->file[i], line, len) == 0)
			return (ret);
		while (env->file[i] && env->file[i] != '\n')
			i++;
		i++;
		ret++;
	}
	if (s == 0)
		return (-1);
	return (ret);
}

/*
** Count the number of rooms in the file
*/
unsigned int			count_rooms(char *file, unsigned int *j)
{
	unsigned int	ret;
	unsigned int	i;
	char		s;

	i = *j;
	ret = 0;
	while (file[i] && (s = get_line_state(&file[i], 0)) != 'p')
	{
		if (s == 'r')
			ret++;
		else if (s == 0)
			return (0);
		while (file[i] && file[i] != '\n')
			i++;
		i++;
	}
	get_line_state(file, true);
	*j = i;
	return (ret);
}

/*
** Count the number of pipes per rooms
*/
unsigned int			*count_pipes(t_env *env, unsigned int i)
{
	char		s;
	int		from;
	int		to;

	if (!(env->nb_pipes = (unsigned int*)malloc(sizeof(unsigned int)
			* env->nb_rooms)))
		return (NULL);
	ft_memset(env->nb_pipes, 0, sizeof(unsigned int) * env->nb_rooms);
	ft_putendl(&env->file[i]);
	while (env->file[i] && (s = get_line_state(&env->file[i], false)))
	{
		if (s == 'p')
		{
			if ((from = find_from(env, &env->file[i])) == -1)
				return (NULL);
			else if ((to = find_to(env, &env->file[i])) == -1)
				return (NULL);
			env->nb_pipes[from]++;
			env->nb_pipes[to]++;
		}
		while (env->file[i] && env->file[i] != '\n')
			i++;
	}
	i = 0;
	while (i < env->nb_rooms)
	{
		printf("room %d : %u pipes\n", i, env->nb_pipes[i]);
		i++;
	}
	return (env->nb_pipes);
}
