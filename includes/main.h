#ifndef MAIN_H
# define MAIN_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <time.h>

# define PUT ft_putstr("There\n");
# define PUT1 ft_putstr("There1\n");
# define PUT2 ft_putstr("There2\n");
# define PUT3 ft_putstr("There3\n");
# define PUT4 ft_putstr("There4\n");
# define PUT5 ft_putstr("There5\n");
# define PUT6 ft_putstr("There6\n");
# define PUT7 ft_putstr("There7\n");

# define BUFF_READ 65536
# define BUFF_WRITE 65536
# define INT_BITS 32

typedef struct		s_room
{
	char			*name;
	unsigned int	index;
	int				x;
	int				y;
	char			type;
	char			_pad[3];
}					t_room;

typedef struct		s_env
{
	char			*file;
	t_room			*graph;
	char			**matrix;
	unsigned int	nb_rooms;
	unsigned int	pad;
}					t_env;

/*
** Parsing
*/
char				*read_fd_zero(void);
t_room				*parsing(t_env *env);
void				next_line(char *file, unsigned int *i);
unsigned int		count_rooms(char *file, unsigned int *j);
unsigned int		*count_pipes(t_env *env, unsigned int i);
t_room				*make_graph(t_env *env);
unsigned int		**make_matrix(t_env *env, unsigned int i);
unsigned int		**allocate_matrix(t_env *env);
void				add_bit(unsigned int *integer, unsigned int bit);
int					load_line(t_env *env, char s, unsigned int i, int room);
char				get_line_state(char *line, bool flush);
bool				is_room(char *line);
bool				is_pipe(char *line);
bool				is_comment(char *line);
int					find_from(t_env *env, char *line);
int					find_to(t_env *env, char *line);

t_env				*free_env(t_env *env);

#endif
