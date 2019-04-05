#include "../includes/main.h"

char	**ft_init_chess(void)
{
	char	**tab;
	int		i;

	i = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * 8)))
		return (NULL);
	while (i < 7)
	{
		if (!(tab[i] = ft_strdup(".......")))
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	ft_print_chess(char **chess)
{
	int		i;
	int		j;

	i = 0;
	while (chess[i])
	{
		j = 0;
		while (chess[i][j])
		{
			ft_putchar(chess[i][j]);
			ft_putstr("  ");
			j++;
		}
		ft_putstr("\n\n");
		i++;
	}
}

int		ft_parse_input(char *input, int *x)
{
	int		len;

	len = ft_strlen(input);
	if (len > 2)
		return (-1);
	if (ft_isdigit(input[0]) == 0)
		return (-1);
	*x = ft_atoi(input);
	if (*x < 0 || *x > 6)
		return (-1);
	return (0);
}

char	**ft_play_move(char **chess, char *input)
{
	static int	cols[7] = {0, 0, 0, 0, 0, 0, 0};
	static int	player = 0;
	int			x;

	if (ft_parse_input(input, &x) == -1)
		return (NULL);
	if (cols[x] == 7)
		return (NULL);
	chess[6 - cols[x]][x] = (player == 0) ? 'X' : 'O';
	cols[x]++;
	player = (player == 1) ? 0 : 1;
	return (chess);
}

int		ft_p4(void)
{
	char	**chess;
	char	*input;
	int		stop;
	int		turns;

	stop = 1;
	turns = 0;
	if (!(chess = ft_init_chess()))
		return (-1);
	ft_print_chess(chess);
	while (ft_check_win(chess) == 0)
	{
		stop = 1;
		while (stop > 0)
		{
			if (get_next_line(0, &input) == -1)
				return (-1);
			write(STDOUT_FILENO, "\e[1;1H\e[2J", 11);
			if (!ft_play_move(chess, input))
				ft_putstr("Wrong move. Retry :\n");
			else
			{
				stop = 0;
				turns++;
			}
			ft_print_chess(chess);
			ft_strdel(&input);
		}
	}
	return (0);
}

int		main(void)
{
//	write(STDOUT_FILENO, "\e[1;1H\e[2J", 11);
//	if (ft_p4() == -1)
//		return (1);
	ft_train();
	return (0);
}
