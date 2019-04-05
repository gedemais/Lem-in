#include "../includes/main.h"
#include <stdio.h>

char	ft_check_x(char **chess, char p1, char p2)
{
	int		i;
	int		j;

	i = 0;
	while (chess[i])
	{
		j = 0;
		while (j < 4)
		{
			if (chess[i][j] == p1 && chess[i][j + 1] == p1 && chess[i][j + 2] == p1 && chess[i][j + 3] == p1)
				return (p1);
			else if (chess[i][j] == p2 && chess[i][j + 1] == p2 && chess[i][j + 2] == p2 && chess[i][j + 3] == p2)
				return (p2);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_check_y(char **chess, char p1, char p2)
{
	int		i;
	int		j;

	j = 0;
	while (j < 7)
	{
		i = 0;
		while (i < 4)
		{
			if (chess[i][j] == p1 && chess[i + 1][j] == p1 && chess[i + 2][j] == p1 && chess[i + 3][j] == p1)
				return (p1);
			else if (chess[i][j] == p2 && chess[i + 1][j] == p2 && chess[i + 2][j] == p2 && chess[i + 3][j] == p2)
				return (p2);
			i++;
		}
		j++;
	}
	return (0);
}

int		ft_check_LT(char **chess, char p1, char p2)
{
	int		i;
	int		j;
	int		ti;
	int		acc[2];

	i = 3;
	while (i < 7)
	{
		ti = i;
		j = 0;
		acc[0] = 0;
		acc[1] = 0;
		while (ti >= 0 && j < 7)
		{
				if (chess[ti][j] == p1)
				{	
					acc[0]++;
					acc[1] = 0;
				}
				else if (chess[ti][j] == p2)
				{
					acc[1]++;
					acc[0] = 0;
				}
				else
				{
					acc[0] = 0;
					acc[1] = 0;
				}
				if (acc[0] == 4 || acc[1] == 4)
					return (acc[0] == 4) ? p1 : p2;
				ti--;
				j++;
		}
		i++;
	}
	return (0);
}

int		ft_check_LB(char **chess, char p1, char p2)
{
	int		i;
	int		j;
	int		tj;
	int		acc[2];

	j = 1;
	while (j < 4)
	{
		i = 6;
		tj = j;
		acc[0] = 0;
		acc[1] = 0;
		while (tj < 7 && i >= 0)
		{
			if (chess[tj][i] == p1)
			{	
				acc[0]++;
				acc[1] = 0;
			}
			else if (chess[tj][i] == p2)
			{
				acc[1]++;
				acc[0] = 0;
			}
			else
			{
				acc[0] = 0;
				acc[1] = 0;
			}
			if (acc[0] == 4 || acc[1] == 4)
				return (acc[0] == 4) ? p1 : p2;
			tj++;
			i--;
		}
		j++;
	}
	return (0);
}

int		ft_check_RT(char **chess, char p1, char p2)
{
	int		i;
	int		j;
	int		tj;
	int		acc[2];

	j = 3;
	while (j >= 0)
	{
		i = 0;
		tj = j;
		acc[0] = 0;
		acc[1] = 0;
		while (tj < 7 && i >= 0)
		{
			if (chess[tj][i] == p1)
			{
				acc[0]++;
				acc[1] = 0;
			}
			else if (chess[tj][i] == p2)
			{
				acc[1]++;
				acc[0] = 0;
			}			
			else
			{
				acc[0] = 0;
				acc[1] = 0;
			}
			if (acc[0] == 4 || acc[1] == 4)
				return (acc[0] == 4) ? p1 : p2;
			tj++;
			i++;
		}
		j--;
	}
	return (0);
}

int		ft_check_RB(char **chess, char p1, char p2)
{
	int		i;
	int		j;
	int		ti;
	int		acc[2];

	i = 1;
	while (i < 4)
	{
		j = 0;
		ti = i;
		acc[0] = 0;
		acc[1] = 0;
		while (ti < 7 && j < 7)
		{
			if (chess[ti][j] == p1)
			{
				acc[0]++;
				acc[1] = 0;
			}
			else if (chess[ti][j] == p2)
			{
				acc[1]++;
				acc[0] = 0;
			}
			else
			{
				acc[0] = 0;
				acc[1] = 0;
			}
			if (acc[0] == 4 || acc[1] == 4)
				return (acc[0] == 4) ? p1 : p2;
			ti++;
			j++;
		}
		i++;;
	}
	return (0);
}

int		ft_check_draw(char **chess)
{
	int		i;
	int		j;

	i = 0;
	while (chess[i])
	{
		j = 0;
		while (chess[i][j])
		{
			if (chess[i][j] == '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_check_win(char **chess)
{
	char	p1;
	char	p2;
	char	winner;

	p1 = 'X';
	p2 = 'O';
	if ((winner = ft_check_x(chess, p1, p2)) != 0
		|| (winner = ft_check_y(chess, p1, p2)) != 0
			|| (winner = ft_check_LT(chess, p1, p2)) != 0 
				|| (winner = ft_check_LB(chess, p1, p2)) != 0
					|| (winner = ft_check_RT(chess, p1, p2)) != 0
						|| (winner = ft_check_RB(chess, p1, p2)) != 0)
	{
		ft_putchar(winner);
		ft_putstr(" wins !\n");
		ft_print_chess(chess);
		return (1);
	}
	else if (ft_check_draw(chess) == 1)
	{
		ft_putstr("Draw !\n");
		return (1);
	}
	return (0);
}
