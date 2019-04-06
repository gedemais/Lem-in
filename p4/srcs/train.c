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
			pop->pop[i].fitness = 100;
		else
			pop->pop[i].fitness = pop->pop[i].wins / pop->pop[i].loose;
		if (pop->pop[i].fitness > best)
			best = i;
		i++;
	}
	pop->index_best = i;
}

void	ft_gangbang(t_netw *n, int index_best, t_popu *pop)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	while (pop->pop[i].weight && y < 3)
	{
		printf("i = %d\ny = %d\nx = %d\n", i, y, x);
		if (i != index_best)
		{
	//		pop->pop[i].weight = ft_memcpy(&pop->pop[i].weight, &pop->pop[index_best].weight, sizeof(pop->pop[i].weight));
			pop->pop[i].weight[y][x] += random_dbl(-0.5, 0.5);
		}
		if (x > n->layer_size[y] && pop->pop[i].weight)
		{
			x = -1;
			y++;
		}
		x++;
		i++;
	}
}

void	ft_train(void)
{
	char	**chess;
	double	*input;
	t_popu	pop;
	t_netw	n1;
	t_netw	n2;
	int		gen;

	if (!(input = (double*)malloc(sizeof(double) * 49)))
		return ;
	gen = 0;
	if (!(chess = ft_init_chess()))
		return ;
	if (!prepare_init_netw(&n1, chess))
		return ;
	if (!prepare_init_netw(&n2, chess))
		return ;
	if (!(pop.pop = ft_init_pop()))
		return ;
	while (gen <= 1000)
	{
		ft_fight(chess, &n1, &n2, &pop, gen);
		ft_get_best(&pop);
		ft_gangbang(&n1, pop.index_best, &pop);
//		ft_save_weights(pop.pop[dest]);
		printf("Generation %d\n", gen);
		gen++;
	}
	ft_print_chess(chess);
}
