#include "../includes/main.h"

char	**ft_clear_chess(char **chess)
{
	int		i;
	int		j;

	i = 0;
	while (chess[i])
	{
		j = 0;
		while (chess[i][j])
		{
			chess[i][j] = '.';
			j++;
		}
		i++;
	}
	return (chess);
}

void	ft_fight(char **chess, t_netw *n1, t_netw *n2, t_popu *pop, int gen)
{
//	int		wins[10];
	int		pool;
	int		i;
	int		j;
	int		res;

	i = 0;
	pool = 1;
	while (pool <= 10)
	{
		i = 100 * (pool - 1);
		while (i < (100 * pool) - 1 && pop->pop[i].weight)
		{
			j = i + 1;
			while (j < (100 * pool) && pop->pop[j].weight)
			{
				ft_apply_weights(n1, pop->pop[i].weight);
				ft_apply_weights(n2, pop->pop[j].weight);
//				display_weight(*n1);
				res = ft_p4(n1, n2, chess, gen);
				chess = ft_clear_chess(chess);
				if (res == 1)
				{
					pop->pop[i].wins++;
					pop->pop[j].loose++;
				}
				else if (res == 2)
				{
					pop->pop[j].wins++;
					pop->pop[i].loose++;
				}
				j++;
			}
			i++;
		}
		pool++;
	}
}
