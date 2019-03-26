
#include "../includes/ft_lmbf.h"

void	ft_print_map(t_room *map)
{
	int		i;

	i = 0;
	while (map[i].x != -42)
	{
		ft_putstr("##### ");
		ft_putnbr(map[i].index);
		ft_putstr(" #####\n");
		ft_putendl(map[i].name);
		ft_putstr("name_len : ");
		ft_putnbr(map[i].name_len);
		ft_putchar('\n');
		ft_putstr("nlinks : ");
		ft_putnbr(map[i].nlinks);
		ft_putchar('\n');
		ft_putstr("x : ");
		ft_putnbr(map[i].x);
		ft_putchar('\n');
		ft_putstr("y : ");
		ft_putnbr(map[i].y);
		ft_putchar('\n');
		ft_putstr("lock : ");
		ft_putnbr(map[i].lock);
		ft_putchar('\n');
		ft_putstr("start : ");
		ft_putnbr(map[i].start);
		ft_putchar('\n');
		ft_putstr("end : ");
		ft_putnbr(map[i].end);
		ft_putchar('\n');
		ft_putchar('\n');
		i++;
	}
}

