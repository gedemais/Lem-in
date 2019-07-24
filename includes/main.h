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

typedef struct		s_env
{
	int				**graph;
	int				**r_graph;
	char			**rooms;
	char			*file;
	unsigned int	nb_rooms;
	unsigned int	nb_pipes;
}					t_env;

typedef struct		s_room
{
	char			*name;
	unsigned int	*pipes;
}					t_room;

/*
** Parsing
*/
char				*read_fd_zero(void);
int					parsing(t_env *env);

#endif
