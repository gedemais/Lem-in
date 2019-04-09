#include "../includes/main.h"
#include "../../libia/includes/libia.h"

void	ft_init(t_netw *n)
{
	double		**weights;
	char		buff[3200];
	int		fd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	fd = open("weights", O_RDONLY);
	read(fd, buff, 3200);
	if (!(weights = (double**)malloc(sizeof(double*))))
		return ;
	if (!(weights[0] = (double*)malloc(sizeof(double) * 343)))
		return ;
	while (i < 343)
	{
		weights[0][i] = strtod(&buff[j], NULL);
		while (buff[j] != '\n')
			j++;
		j++;
		i++;
	}
	ft_apply_weights(n, weights);
}

int        ft_p5(t_netw *n1, char **chess)
{
	double	*input;
	int	*fills;
	char	*in;
	int	stop;
	int	turns;
	int	move;

	stop = 1;
	turns = 0;
	if (!(fills = (int*)malloc(sizeof(int) * 7)))
		return (-1);
	fills[0] = 0;
	fills[1] = 0;
	fills[2] = 0;
	fills[3] = 0;
	fills[4] = 0;
	fills[5] = 0;
	fills[6] = 0;
	if (!(input = (double*)malloc(sizeof(double) * 49)))
		return (-1);
	while (ft_check_win(chess) == 0)
	{
		stop = 1;
		while (stop > 0)
		{
			input = extract_data_from_game(input, chess);
			if (turns % 2 == 1)
			{
				fill_data_in(n1, input);
				fill_netw_in(n1);
				move = ft_get_brightest(firing(n1));
			}
			else
			{
				get_next_line(0, &in);
				move = ft_atoi(in);
				ft_strdel(&in);
			}
			if (!ft_play_move(chess, move, &fills))
			{
				while (fills[move] == 7 && move < 7)
					move++;
				if (move == 7)
				{
					ft_play_move(chess, -1, &fills);
					ft_clear_chess(chess);
					return (0);
				}
				else
					ft_play_move(chess, move, &fills);
			}
			//    ft_putstr("Wrong move. Retry :\n");
			turns++;
			stop = 0;
			ft_putstr("0  1  2  3  4  5  6\n");
			ft_print_chess(chess);
			ft_putchar('\n');
		}
	}
	return (0);
}

int	main(void)
{
	char	**chess;
	t_netw	n;

	chess = ft_init_chess();
	prepare_init_netw(&n, chess);
	ft_init(&n);
	ft_p5(&n, chess);
	return (0);
}
