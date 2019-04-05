#include "../includes/main.h"
/*
int		ft_fight()
{
	char	**chess;
	int		choose;

	if (!(chess = ft_init_chess()))
		return (-1);
	ft_print_chess(chess);
	while (ft_check_win(chess) == 0)
	{
			if (
			if (!ft_play_move(chess, choose))
				ft_putstr("Wrong move. Retry :\n");
			else
				stop = 0;
			ft_print_chess(chess);
			ft_strdel(&input);
	}
	return (0);
}*/

t_indiv		*ft_init_pop(void)
{
	t_indiv		*dest;
	int			i;

	i = 0;
	if (!(dest = (t_indiv*)malloc(sizeof(t_indiv) * 1000)))
		return (NULL);
	while (i < 1000)
	{
		if (!(dest[i].weight = (double**)malloc(sizeof(double*) * 3)))
				return (NULL);
		if (!(dest[i].weight[0] = (double*)malloc(sizeof(double) * (49 * 14))))
				return (NULL);
		if (!(dest[i].weight[1] = (double*)malloc(sizeof(double) * (14 * 14))))
				return (NULL);
		if (!(dest[i].weight[2] = (double*)malloc(sizeof(double) * (7 * 14))))
				return (NULL);
		if (!(dest[i].weight = generate_weight(dest[i].weight)))
			return (NULL);
		i++;
	}
	return (dest);
}

void	ft_get_best(t_popu *pop)
{
	int		i;
	int		best;

	i = 0;
	best = 0;
	while (i < 1000)
	{
		if (pop->pop[i].fitness > best)
			best = i;
		i++;
	}
	pop->index_best = i;
}

void	ft_fight(char **chess, t_popu *pop, t_netw *n)
{	
	int		i;
	int		j;

	i = 0;
	while (i < 1000)
	{
		j = 0;
//		apply_weight(n, pop)
		i++;
	}
	
}

void	ft_train()
{
	char	**chess;
	double	*output;
	double	*input;
	t_popu	pop;
	t_netw	n;
	int		gen;

	if (!(input = (double*)malloc(sizeof(double) * 49)))
		return ;
	gen = 0;
	n = init_network(&n, extract_data_from_game(input, chess));
	if (!(chess = ft_init_chess()))
		return ;
	if (!(pop.pop = ft_init_pop()))
		return ;
	
	while (gen < 1000)
	{
//		ft_fight(chess, &pop);
//		ft_get_best(&pop);
//		ft_gangbang(pop.pop[dest], &pop);
//		ft_export_weights(pop.pop[dest]);
		gen++;
	}
	ft_print_chess(chess);
}
