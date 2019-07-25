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
		i++;
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

int		find_from(t_env *env, char *line)
{
	unsigned int	len;
	int				ret;

	ret = 0;
	len = get_name_len(line, false);
	while (ret < (int)env->nb_rooms)
	{
		if (line[0] == env->graph[ret].name[0])
			if (ft_strncmp(line, env->graph[ret].name, len) == 0)
				return (ret);
		ret++;
	}
	return (-1);
}


int		find_to(t_env *env, char *line)
{
	unsigned int	len;
	unsigned int	i;
	int				ret;

	i = 0;
	ret = 0;
	len = get_name_len(line, true);
	while (line[i] && line[i] != '\n' && line[i] != '-')
			i++;
	i++;
	while (ret < (int)env->nb_rooms)
	{
		if (line[i] == env->graph[ret].name[0])
			if (ft_strncmp(&line[i], env->graph[ret].name, len) == 0)
					return (ret);
		ret++;
	}
	return (-1);
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
		next_line(file, &i);
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
	while (env->file[i] && (s = get_line_state(&env->file[i], false)))
	{
		if (s == 'p')
		{
			if ((from = find_from(env, &env->file[i])) == -1
				|| (to = find_to(env, &env->file[i])) == -1)
					return (NULL);
			env->nb_pipes[from]++;
			env->nb_pipes[to]++;
		}
		next_line(env->file, &i);
	}
	return (env->nb_pipes);
}
