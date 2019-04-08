#include "../includes/main.h"

t_indiv		*ft_init_pop(void)
{
	t_indiv		*dest;
	int			i;

	i = 0;
	if (!(dest = (t_indiv*)malloc(sizeof(t_indiv) * 344)))
		return (NULL);
	while (i < 980)
	{
		if (!(dest[i].weight = (double**)malloc(sizeof(double*) * 1)))
				return (NULL);
		if (!(dest[i].weight[0] = (double*)malloc(sizeof(double) * (49 * 7))))
				return (NULL);
		if (!(dest[i].weight = generate_weight(dest[i].weight)))
			return (NULL);
		dest[i].wins = 0;
		dest[i].loose = 0;
		i++;
	}
	dest[i].weight = NULL;
	return (dest);
}

int		ft_find_next(t_popu *pop, int flush)
{
	static int	i = 0;
	int			j;

	if (flush)
	{
		i = 0;
		return (-1);
	}
	while (i < 343)
	{
		j = 0;
		while (pop->elite[j] != -1)
		{
			if (i == pop->elite[j])
				break ;
			j++;
		}
		if (pop->elite[j] == -1)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_bornes(int *min, int *max)
{
	int		random;

	random = rand() % 7;
	*min = random * 49;
	*max = (random + 1) * 49;
}

void	ft_influence(t_popu *pop, int flush, int comeback)
{
	static int		i = 0;
	int		min;
	int		max;
	int		j;
	int		pos;

	j = 0;
	if (flush)
	{
		i = 0;
		return ;
	}
	if ((pos = ft_find_next(pop, 0)) == -1)
		return ;
	ft_bornes(&min, &max);
	while (j < 343)
	{
		pop->pop[pos].weight[0][j] = pop->pop[pop->elite[i]].weight[0][j];
		if (j >= min && j <= max)
			pop->pop[pos].weight[0][j] += random_dbl(-(comeback / 10), (comeback / 10));
		j++;
	}
	
	i++;
}

void	ft_source(t_popu *pop, int pos, double **save)
{
	int		i;
	int		min;
	int		max;

	i = 0;
	ft_bornes(&min, &max);
	while (i < 343)
	{
		pop->pop[pos].weight[0][i] = save[0][i];
		if (i >= min && i <= max)
			pop->pop[pos].weight[0][i] += random_dbl(-0.1, 0.1);
		i++;
	}
}

void	ft_gangbang(t_popu *pop, double **save, int comeback)
{
	int		to_inf;
	int		i;
	int		pos;

	i = 0;
	to_inf = (int)pop->fitness + 10;
	while (i < to_inf)
	{
		ft_influence(pop, 0, comeback);
		i++;
	}
	while (i < 343)
	{
		if ((pos = ft_find_next(pop, 0)) != -1)
			ft_source(pop, pos, save);
		i++;
	}
	ft_influence(pop, 1, comeback);
	ft_find_next(pop, 1);
}

void	ft_clear_stats(t_popu *pop)
{
	int		i;

	i = 0;
	while (pop->pop[i].weight)
	{
		pop->pop[i].loose = 0;
		pop->pop[i].wins = 0;
		i++;
	}
}

double	**ft_save_weights(double **weight, double **best)
{
	int		i;

	i = 0;
	while (i < (49 * 7))
	{
		best[0][i] = weight[0][i];
		i++;
	}
	return (best);
}

double	ft_get_fitness(int *elite)
{
	int		i;

	i = 0;
	while (elite[i] != -1)
		i++;
	return ((double)(i / 343) * 100);
}

void	ft_train(void)
{
	char	**chess;
	double	*input;
	double	**save;
	double	best_fitness;
	int		comeback;
	t_popu	pop;
	t_netw	n;
	int		gen;
	int		player;

	player = 1;
	best_fitness = -100;
	if (!(input = (double*)malloc(sizeof(double) * 49)))
		return ;
	if (!(save = (double**)malloc(sizeof(double*))))
		return ;
	if (!(save[0] = (double*)malloc(sizeof(double) * 343)))
		return ;
	gen = 0;
	if (!(chess = ft_init_chess()))
		return ;
	if (!prepare_init_netw(&n, chess))
		return ;
	if (!(pop.pop = ft_init_pop()))
		return ;
	if (!(pop.elite = (int*)malloc(sizeof(int) * 350)))
		return ;
	comeback = 0;
	save = ft_save_weights(pop.pop[0].weight, save);
	while (gen <= 100000)
	{
		ft_fight(&n, chess, &pop, player);
		pop.fitness = ft_get_fitness(pop.elite);
		if (pop.fitness >= 90)
		{
			player++;
			save = ft_save_weights(pop.pop[pop.elite[0]].weight, save);
		}
		else
			comeback++;
		ft_gangbang(&pop, save, comeback);
		printf("------- Generation %d -------\nFitness %f\n", gen, pop.fitness);
		ft_clear_stats(&pop);
		gen++;
	}
	ft_print_chess(chess);
	free(pop.elite);
//	ft_train2(best);
}
