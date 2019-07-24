#ifndef MAIN_H
# define MAIN_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

# define PUT ft_putstr("There\n");
# define PUT1 ft_putstr("There1\n");
# define PUT2 ft_putstr("There2\n");
# define PUT3 ft_putstr("There3\n");
# define PUT4 ft_putstr("There4\n");
# define PUT5 ft_putstr("There5\n");
# define PUT6 ft_putstr("There6\n");
# define PUT7 ft_putstr("There7\n");

# define BUFF_READ 4194304

typedef struct		s_room
{
	char		*name;
	unsigned int	*pipes;
	unsigned int	index;
	int		x;
	int		y;
	char		type;
	char		_pad[3];
}			t_room;

typedef struct		s_env
{
	char		*file;
	t_room		*graph;
	unsigned int	*nb_pipes;
	unsigned int	nb_rooms;
	unsigned int	pad;
}			t_env;

/*
** Parsing
*/
char				*read_fd_zero(void);
t_room				*parsing(t_env *env);
unsigned int			count_rooms(char *file, unsigned int *j);
unsigned int			*count_pipes(t_env *env, unsigned int i);
t_room				*make_graph(t_env *env);
int				load_line(t_env *env, char s, unsigned int i, int room);
char				get_line_state(char *line, bool flush);
bool				is_room(char *line);
bool				is_pipe(char *line);
bool				is_comment(char *line);


t_env				*free_env(t_env *env);

#endif
