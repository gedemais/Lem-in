#include "main.h"

char			get_line_state(char *line, bool flush)
{
	static bool	pipe = false;


	if (flush)
		pipe = false;
	if (!pipe)
	{
		if (ft_strncmp(line, "##start\n", 8) == 0)
			return ('s');
		else if (ft_strncmp(line, "##end\n", 6) == 0)
			return ('e');
		else if (is_room(line))
			return ('r');
	}
	if (is_pipe(line))
	{
		pipe = true;
		return ('p');
	}
	else if (is_comment(line))
		return ('c');
	return (0);
}

/*
** debug
*/
/*
static inline void	print_line(char *file, unsigned int i)
{
	unsigned int	j;

	j = 0;
	while (file[i + j] && file[i + j] != '\n')
		j++;
	write(1, &file[i], j + 1);
}*/


/*
** Replace the index going through the file string at the start of the next line
*/
static inline void	next_line(char *file, unsigned int *i)
{
	unsigned int	j;

	j = *i;
	while (file[j] && file[j] != '\n')
		j++;
	*i = j + 1;
}

/*
** Notifiy if a start or end is readed. If one of those is not present, ERROR
*/
static inline int	note_start_end(bool *s_e, char state)
{
	if (state == 's')
		s_e[0] = true;
	else if (state == 'e')
		s_e[1] = true;
	return (0);
}

/*
** Create the t_room array
*/
t_room			*make_graph(t_env *env)
{
	unsigned int	i;
	bool		s_e[2];
	int		room;
	char		s; // 's' for start, 'e' for end, 'r' for regular

	i = 0;
	room = -1;
	ft_memset(&s_e[0], 0, sizeof(bool) * 2);
	next_line(env->file, &i);
	if (!(env->graph = (t_room*)malloc(sizeof(t_room) * (env->nb_rooms + 1))))
		return (NULL);
	env->graph = ft_memset(env->graph, 0, sizeof(t_room) * (env->nb_rooms + 1));
	while (env->file[i] && (s = get_line_state(&env->file[i], false)) && room < (int)env->nb_rooms)
	{
		if (s == 'r' && load_line(env, s, i, ++room))
			return (env->graph);
		else if ((s == 's' || s == 'e') && note_start_end(&s_e[0], s))
			return (env->graph);
		next_line(env->file, &i);
	}
	if (!s_e[0] && !s_e[1])
		return (NULL);
	return (env->graph);
}
