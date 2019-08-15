#include "main.h"
/*
** Returns a char representing the state of line :
** s for the start room
** e for the end room
** r for a regular room
** p for a pipe
** c for a comment
*/
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
void	next_line(char *file, unsigned int *i)
{
	unsigned int	j;

	j = *i;
	while (file[j] && file[j] != '\n')
		j++;
	*i = j + 1;
}

/*
** Create the t_room array
*/
t_room			*make_graph(t_env *env)
{
	unsigned int	i;
	int		room;
	char		s;

	i = 0;
	room = 0;
	next_line(env->file, &i);
	if (!(env->graph = (t_room*)malloc(sizeof(t_room) * (env->nb_rooms + 1))))
		return (NULL);
	env->graph = ft_memset(env->graph, 0, sizeof(t_room) * (env->nb_rooms + 1));
	while (env->file[i] && (s = get_line_state(&env->file[i], false))
		&& room < (int)env->nb_rooms && s != 'p')
	{
		if (load_line(env, s, i, room))
			return (env->graph);
		room += (s == 'r') ? 1 : 0;
		next_line(env->file, &i);
	}
	return (env->graph);
}
