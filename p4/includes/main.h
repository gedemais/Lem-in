#ifndef MAIN_H
# define MAIN_H

# include "../libft/libft.h"
# include "neural_network.h"
# include "../libia/includes/libia.h"

# define PUT ft_putstr("There\n");

int		ft_check_win(char **chess);
void	ft_print_chess(char **chess);
double	*extract_data_from_game(double *data, char **game);
t_netw	*prepare_init_netw(t_netw *n, char **game);
char	**ft_init_chess(void);
double	**generate_weight(double **weight);
void	ft_train();

typedef struct		s_indiv
{

	double			**weight;
	double			*bias;
	double			*out;
	int				fitness;
}					t_indiv;

typedef struct		s_popu
{

	t_indiv			*pop;
	int				index_best;
}					t_popu;


#endif
