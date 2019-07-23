#include "main.h"

int					start_check(char *file, unsigned int *nb_rooms)
{
	unsigned int	i;
	char			state;

	i = 0;
	if (check_nb_ant(file))
			return (-1);
	while (file[i])
	{
		if ((state = get_state()))
		if (state == 'r')
				(*nb_rooms)++;
		ft_putendl(&file[i]);
		replace(&file[i], &i);
	}
	return (0);
}
