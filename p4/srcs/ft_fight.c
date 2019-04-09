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
/*
void	ft_fight2(char **chess, t_netw *n1, t_netw *n2, t_popu *pop, int gen)
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
				(void)gen;
				res = ft_p4(n1, n2, chess, 0);
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
				else if (res == 0)
				{
					pop->pop[j].loose++;
					pop->pop[i].loose++;
				}
				j++;
			}
			i++;
		}
		pool++;
	}
}*/

void	ft_fight(t_netw *n, char **chess, t_popu *pop, int player)
{
	static int	dis = 0;
	int		i;
	int		j;
	double	*out;
	double	*in;
	int		score;
	int		tmp;

	score = 0;
	if (!(out = (double*)malloc(sizeof(double) * 49)))
		return ;
	if (!(in = (double*)malloc(sizeof(double) * 7)))
		return ;
	i = 0;
	j = 0;
	while (i < 343)
	{
//		PUT
		ft_apply_weights(n, pop->pop[i].weight);
//		if (i % 10 == 0)
	//		score = ft_p41(n, chess, player, 0, 1); // Player first'
	//	else
			score = ft_p41(n, chess, player, 0, 0); // Player first'
//		PUT1
	//	if (i % 10 == 0)
	//		tmp = ft_p41(n, chess, player, 1, 1); // Network first
	//	else
			tmp = ft_p41(n, chess, player, 1, 0); // Network first
//		PUT2
		if (score == 1 && tmp == 2) // Defaite
		{
//			ft_putnbr(i);
//			ft_putchar(' ');
//			ft_putstr("Loose\n");
			pop->pop[i].wins = 1;
		}
		else if (score == 2 && tmp == 1) // Victoire
		{
//			ft_putnbr(i);
//			ft_putchar(' ');
//			ft_putstr("Win\n");
			pop->elite[j] = i;
			pop->pop[i].loose = 1;
			j++;
		}
		else
		{
			pop->pop[i].wins = 0;
			pop->pop[i].loose = 0;
//			ft_putnbr(i);
//			ft_putchar(' ');
//			ft_putstr("Draw\n");
		}
		i++;
	}
	dis++;
	pop->elite[j] = -1;
}
