#ifndef MAIN_H
# define MAIN_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <time.h>
# include <assert.h>

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

typedef struct s_queue	t_queue;

struct				s_queue
{
	t_queue			*next;
	unsigned int	index;
	int				_pad;
};

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
	char			**matrix;
	int				**paths;
	char			*file;
	t_room			*graph;
	bool			*visited;
	int				*parent;
	int				start;
	int				end;
	unsigned int	nb_rooms;
	unsigned int	max_flow;
}					t_env;

/*
** Parsing
*/
char				*read_fd_zero(void);
t_room				*parsing(t_env *env);
void				next_line(char *file, unsigned int *i);
unsigned int		count_rooms(char *file, unsigned int *j);
t_room				*make_graph(t_env *env);
char				get_line_state(char *line, bool flush);
bool				is_room(char *line);
bool				is_pipe(char *line);
bool				is_comment(char *line);
int					load_line(t_env *env, char s, unsigned int i, int room);

/*
** Matrices
*/
void				print_matrix(char **matrix, unsigned int n);
char				**make_matrix(t_env *env, unsigned int i);
char				**matrix_cpy(char **dest, char **src, unsigned int n);
char				**allocate_matrix(char **matrix, unsigned int n);
int					find_from(t_env *env, char *line);
int					find_to(t_env *env, char *line);

/*
** Solving
*/
unsigned int		edmond_karp(t_env *env);
bool				breadth_first_search(t_env *env, int s, int e);
int				**allocate_paths(t_env *env);
void				print_path(t_env *env, int *path);

/*
** Lists
*/
void				print_lst(t_env *env, t_queue *lst);
unsigned int		lm_lstlen(t_queue *lst);
t_queue				*lm_lstnew(int room);
int					lm_lst_pop(t_queue **lst);
int					lm_lst_push(t_queue **lst, int index);
int					ft_ms_lst_pushfront(t_queue **lst, t_queue *new);

t_env				*free_env(t_env *env);

#endif
