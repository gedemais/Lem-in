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

double	ft_get_fitness(int *elite)
{
	int		i;

	i = 0;
	while (elite[i] != -1)
		i++;
	return ((double)((double)i / 343) * 100);
}

char	*ft_dtoa(double nb)
{
	char	*dest;
	int	i;

	i = 0;
	printf("%f\n", nb);
	if (!(dest = (char*)malloc(sizeof(char) * 5)))
		return (NULL);
	dest[0] = (int)nb + '0';
	nb -= (int)nb;
	dest[1] = '.';
	while (i < 3)
	{
		nb = nb * 10;
		dest[i + 2] = (int)nb + '0';
		nb -= (int)nb;
		i++;
	}
	dest[i + 2] = '\n';
	return (dest);
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
	while (gen <= 1000000)
	{
		ft_fight(&n, chess, &pop, player);
		pop.fitness = ft_get_fitness(pop.elite);
		printf("------- Generation %d -------\nFitness %f\n", gen, pop.fitness);
		if (pop.fitness >= 90)
		{
			ft_export_weigths(pop.pop[pop.elite[0]].weight);
			player++;
			save = ft_save_weights(pop.pop[pop.elite[0]].weight, save);
		}
		else
			comeback++;
		ft_gangbang(&pop, save, comeback);
		ft_clear_stats(&pop);
		gen++;
	}
	ft_print_chess(chess);
	free(pop.elite);
//	ft_train2(best);
}
