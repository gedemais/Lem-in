#include "../includes/ft_lmbf.h"

int	ft_solve(t_room *map, t_map *env, int room, int index)
{
	int	i;

	i = 0;
	if (room == -1 || map[room].end == true)
		return (index);
	while (map[room].links[i] != -1)
	{	
		if (map[map[room].links[i]].end == true && (room = -1) == -1)
			return (index + 1);
		i++;
	}
	i = 0;
	while (map[room].links[i] != -1)
	{
		ft_solve(map, env, map[room].links[i], index + 1);
		i++;
	}
	return (-1);
}
