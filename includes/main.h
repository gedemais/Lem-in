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

# define BUFF_READ 65536
# define BUFF_WRITE 65536

typedef struct s_queue	t_queue;

struct				s_queue
{
	t_queue			*next;
	unsigned int		index;
	int			_pad;
};

typedef struct			s_room
{
	char			*name;
	unsigned int		index;
	int			x;
	int			y;
	int			ant;
	char			type;
	char			_pad[7];
}				t_room;

typedef struct			s_path
{
	int			*path;
	int			*ants;
	unsigned int		ammos;
	unsigned int		len;
}				t_path;

typedef struct			s_env
{
	char			**matrix;
	int			**path_moves;
	char			*file;
	t_room			*graph;
	t_path			*paths;
	int			*parent;
	bool			*arriveds;
	bool			*visited;
	long long int		nb_ants;
	int			start;
	int			end;
	int			file_len;
	unsigned int		nb_rooms;
	unsigned int		nb_paths;
	unsigned int		max_flow;
	unsigned int		count;
	unsigned int		pipes_start;
}				t_env;

/*
** Parsing
*/
char				*read_fd_zero(int *len);
t_room				*parsing(t_env *env);
void				next_line(char *file, unsigned int *i);
unsigned int			count_rooms(char *file, unsigned int *j);
t_room				*make_graph(t_env *env);
bool				room_err_cases(t_env *env);

/*
** Micro state-machine
*/
int				load_line(t_env *env, char s, unsigned int i, int room);
char				get_line_state(char *line, bool flush);
bool				is_room(char *line);
bool				is_pipe(char *line);
bool				is_comment(char *line);
bool				is_cmd(char *line);

/*
** Matrice d'adjacence
*/
int				make_matrix(t_env *env, unsigned int i);
int				find_from(t_env *env, char *line);
int				find_to(t_env *env, char *line);

/*
** Resolution
*/
unsigned int			edmond_karp(t_env *env, bool up);
bool				breadth_first_search(t_env *env, int s, int e, bool up);
t_path				*allocate_paths(t_env *env);
int				sort_paths(t_env *env);
int				treat_paths(t_env *env);
bool				is_disjoint(t_env *env);

/*
** Output buffering
*/
int				crossing(t_env *env);
int				output_buffer(t_env *env, int move[2], bool n_l, bool f);
bool				*space(void);

/*
** Lists
*/
t_queue				*lm_lstnew(int room);
int				lm_lstdel(t_queue *queue);
int				lm_lst_pop(t_queue **lst);
int				lm_lst_push(t_queue **lst, int index);

/*
** Free
*/
t_env				*free_graph(t_env *env);
t_env				*free_env(t_env *env);
char				**free_matrix(char **matrix, unsigned int n);

#endif
