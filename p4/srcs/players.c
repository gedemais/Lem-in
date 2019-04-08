#include "../includes/main.h"

int		ft_col(int blc, int *fills)
{
	static int	moves[28] = {0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6};
	static int	i = -1;

	(void)blc;
	i++;	
	while (fills[moves[i]] == 6)
	{
		i++;
		if (i == 28)
			i = 0;
	}
	return (moves[i]);
}

int		ft_line(int blc, int *fills)
{
	static int	moves[28] = {0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6};
	static int	i = -1;

	(void)blc;
	i++;
	while (fills[moves[i]] == 6)
	{
		i++;
		if (i == 28)
			i = 0;
	}
	return (moves[i]);
}

int		ft_casselescouilles(int blc, int *fills)
{
	int		i;

	i = 0;
	while (fills[blc] == 6)
	{
		blc++;
		if (blc == 6)
			blc = 0;
	}
	return (blc);
}

int		ft_rand(int blc, int *fills)
{
	int		random;

	random = rand() % 7;
	(void)blc;
	while (fills[random] == 6)
	{
		random = rand() % 7;
	}
	return (random);
}

