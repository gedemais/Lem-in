#ifndef MAIN_H
# define MAIN_H

# include "../libft/libft.h"
# include "neural_network.h"
# include "../libia/includes/libia.h"
# include <time.h>

# define PUT ft_putstr("There\n");
# define PUT1 ft_putstr("There1\n");
# define PUT2 ft_putstr("There2\n");
# define PUT3 ft_putstr("There3\n");
# define PUT4 ft_putstr("There4\n");
# define PUT5 ft_putstr("There5\n");
# define PUT6 ft_putstr("There6\n");
# define PUT7 ft_putstr("There7\n");
# define PUT8 ft_putstr("There8\n");
# define PUT9 ft_putstr("There9\n");

typedef struct		s_indiv
{

	double			**weight;
	double			*bias;
	double			*out;
	int				wins;
	int				loose;
}					t_indiv;

typedef struct		s_popu
{

	t_indiv			*pop;
	int				index_best;
	double			fitness;
	int				*elite;
}					t_popu;

int		ft_check_win(char **chess);
void	ft_print_chess(char **chess);
double	*extract_data_from_game(double *data, char **game);
t_netw	*prepare_init_netw(t_netw *n, char **game);
char	**ft_init_chess(void);
double 	random_dbl(double min, double max);
double	**generate_weight(double **weight);
void	ft_apply_weights(t_netw *n, double **weights);
void	ft_train();
void	ft_fight2(char **chess, t_netw *n1, t_netw *n2, t_popu *pop, int gen);
int		ft_p4(t_netw *n1, t_netw *n2, char **chess, int gen);
void	ft_fight(t_netw *n, char **chess, t_popu *pop, int gen);
void	ft_train2(double **best);
int		ft_p41(t_netw *n1, char **chess, int gen, int first, int display);
char	**ft_clear_chess(char **chess);


int		ft_col(int blc, int *fills);
int		ft_line(int blc, int *fills);
int		ft_casselescouilles(int blc, int *fills);
int		ft_rand(int blc, int *fills);

#endif
