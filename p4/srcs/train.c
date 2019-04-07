#include "../includes/main.h"

t_indiv		*ft_init_pop(void)
{
	t_indiv		*dest;
	int			i;

	i = 0;
	if (!(dest = (t_indiv*)malloc(sizeof(t_indiv) * 981)))
		return (NULL);
	while (i < 980)
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
		dest[i].wins = 0;
		dest[i].loose = 0;
		i++;
	}
	dest[i].weight = NULL;
	return (dest);
}

void	ft_get_best(t_popu *pop)
{
	int		i;
	int		best;

	i = 0;
	best = 0;
	while (i < 980)
	{
		if (pop->pop[i].loose == 0)
			pop->pop[i].loose = 1;
		if (pop->pop[i].wins == 0)
			pop->pop[i].wins = 1;
		pop->pop[i].fitness = (double)(((double)pop->pop[i].wins / (double)pop->pop[i].loose));
		if (pop->pop[i].fitness >= best)
			best = i;
		i++;
	}
	pop->index_best = best;
}

void	ft_gangbang(t_netw *n, int index_best, t_popu *pop, double best_fit)
{
	int		i;
	int		x;
	int		y;
	(void)best_fit;

	i = 0;
	x = 0;
	y = 0;
	while (pop->pop[i].weight && y < 3)
	{
		pop->pop[i].weight = ft_memcpy(pop->pop[i].weight, pop->pop[index_best].weight, sizeof(pop->pop[i].weight));
		if (i != pop->index_best)
		{
			
			pop->pop[i].weight[y][x] += random_dbl(-1, 1);
		}
		if (x > n->layer_size[y] && pop->pop[i].weight)
		{
			x = 0;
			y++;
		}
		x++;
		i++;
	}
}

void	ft_clear_stats(t_popu *pop)
{
	int		i;

	i = 0;
	while (pop->pop[i].weight)
	{
//		pop->pop[i].loose = 0;
//		pop->pop[i].wins = 0;
//		pop->pop[i].draw = 0;
		i++;
	}
}

double	**ft_save_weights(double **weight, double **best)
{
	int		i;

	i = 0;
	while (i < (49 * 14))
	{
		best[0][i] = weight[0][i];
		i++;
	}
	i = 0;
	while (i < (14 * 14))
	{
		best[1][i] = weight[1][i];
		i++;
	}
	i = 0;
	while (i < (14 * 7))
	{
		best[2][i] = weight[2][i];
		i++;
	}
	return (best);
}

void	ft_train(void)
{
	char	**chess;
	double	*input;
	double	**best;
	double	best_fitness;
	int		comeback;
	t_popu	pop;
	t_netw	n1;
	t_netw	n2;
	int		gen;

	best_fitness = -100;
	if (!(input = (double*)malloc(sizeof(double) * 49)))
		return ;
	if (!(best = (double**)malloc(sizeof(double*) * 3)) || 
		!(best[0] = (double*)malloc(sizeof(double) * (49 * 14))) ||
		!(best[1] = (double*)malloc(sizeof(double) * (14 * 14))) ||
		!(best[2] = (double*)malloc(sizeof(double) * (14 * 7))))
	gen = 0;
	if (!(chess = ft_init_chess()))
		return ;
	if (!prepare_init_netw(&n1, chess))
		return ;
	if (!prepare_init_netw(&n2, chess))
		return ;
	if (!(pop.pop = ft_init_pop()))
		return ;
	comeback = 0;
	while (gen <= 100000)
	{
		ft_fight(chess, &n1, &n2, &pop, gen);
		ft_get_best(&pop);
		printf("---------- Generation %d ----------\nBest fitness : %f (%d)\n%d looses for %d wins and %d draws\n", gen, pop.pop[pop.index_best].fitness, pop.index_best, pop.pop[pop.index_best].loose, pop.pop[pop.index_best].wins, pop.pop[pop.index_best].draw);
		if (best_fitness < pop.pop[pop.index_best].fitness)
		{
			ft_apply_weights(&n1, pop.pop[pop.index_best].weight);
			ft_apply_weights(&n2, best);
			if (ft_p4(&n1, &n2, chess, 1) == 2)
			{
				printf("Improve !\n\n");
			}
			best = ft_save_weights(pop.pop[pop.index_best].weight, best);
			best_fitness = pop.pop[pop.index_best].fitness;
			ft_gangbang(&n1, pop.index_best, &pop, pop.pop[pop.index_best].fitness);
			comeback = 0;
		}
		else
		{
			printf("Nothing best found ! (best = %f)\n\n", best_fitness);
			pop.pop[pop.index_best + comeback].weight = ft_save_weights(best, pop.pop[pop.index_best].weight);
			ft_gangbang(&n1, pop.index_best, &pop, pop.pop[pop.index_best].fitness);
			comeback++;
		}
		ft_clear_stats(&pop);
		gen++;
	}
	ft_print_chess(chess);
}
