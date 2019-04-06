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

char	**ft_play_move(char **chess, int move)
{
	static int	cols[7] = {0, 0, 0, 0, 0, 0, 0};
	static int	player = 0;

	if (move == -1)
	{
		cols[0] = 0;
		cols[1] = 0;
		cols[2] = 0;
		cols[3] = 0;
		cols[4] = 0;
		cols[5] = 0;
		cols[6] = 0;
		player = 0;
		return (NULL);
	}
	if (cols[move] >= 7)
		return (NULL);
	chess[6 - cols[move]][move] = (player == 0) ? 'X' : 'O';
	cols[move]++;
	player = (player == 1) ? 0 : 1;
	return (chess);
}

int		ft_get_brightest(double *output)
{
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	while (i < NB_OUTPUT)
	{
//		printf("output[%d] = %f\n", i, output[i]);
		if (output[i] > output[ret])
			ret = i;
		i++;
	}
	free(output);
	return (ret);
}

void	fill_netw_in(t_netw *n)
{
	int		j;

	j = 0;
	while (j < n->layer_size[0])
	{
		n->netw[0][j].in = n->input[j];
		n->netw[0][j].out = n->netw[0][j].act(n->input[j]);
		j++;
	}
}

int		ft_p4(t_netw *n1, t_netw *n2, char **chess, int gen)
{
	double	*input;
	int		stop;
	int		turns;
	int		move;

	stop = 1;
	turns = 0;
//	ft_print_chess(chess);
	if (!(input = (double*)malloc(sizeof(double) * 49)))
		return (-1);
	while (ft_check_win(chess) == 0)
	{
		stop = 1;
		while (stop > 0)
		{
			input = extract_data_from_game(input, chess);
			if (turns % 2 == 0)
			{
				fill_data_in(n1, input);
				fill_netw_in(n1);
		//		display_inputs(*n1);
				move = ft_get_brightest(firing(n1));	
			}
			else
			{	
				fill_data_in(n2, input);
				fill_netw_in(n2);
				move = ft_get_brightest(firing(n2));
			}
			if (!ft_play_move(chess, move))
			{
				ft_play_move(chess, -1);
				return ((turns % 2 == 0) ? 1 : 2);
			}
			//	ft_putstr("Wrong move. Retry :\n");
			turns++;
			stop = 0;
			if (gen == 1000)
			{
				ft_print_chess(chess);
				sleep(1);
			}
		}
	}
	ft_play_move(chess, -1);
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
