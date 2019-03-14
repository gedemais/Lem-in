#include "../includes/ft_lmbf.h"

bool	ft_is_room(char *input)
{
	int	i;

	i = 0;
	ft_putendl(input);
	if (input[i] == ' ' || input[i] == '\n' || input[i] == '\0')
		return (false);
	while (input[i] && input[i] != '\n' && input[i] != ' ')
		i++;
	if (input[i] != ' ')
		return (false);
	i++;
	while (input[i] && input[i] != '\n' && input[i] != ' ')
		i++;
	if (input[i] != ' ')
		return (false);
	i++;
	while (input[i] && input[i] != '\n' && input[i] != ' ')
		i++;
	if (input[i] && input[i] != '\n')
		return (false);
	i++;
	return (true);
}

bool	ft_is_pipe(char *input)
{
	int	i;

	i = 0;
	if (input[i] == ' ' || input[i] == '\n' || input[i] == '\0'
	|| input[i] == '-')
		return (false);
	while (input[i] && input[i] != '-' && input[i] != '\n')
		i++;
	i++;
	if (input[i] == ' ' || input[i] == '\n' || input[i] == '\0'
	|| input[i] == '-')
		return (false);
	while (input[i] && input[i] != '\n')
		i++;
	if (input[i] == '\0')
		return (false);
	return (true);
}

int	ft_count_rooms(char *input, t_map *var)
{
	int	i;

	i = 0;
	var->nb_rooms = 0;
	var->nb_lems = ft_atoi(input);
	while (input[i] != '\n')
		i++;
	while (input[++i])
	{
		if (input[i] == '#')
		{
			while (input[i] != '\n')
				i++;
			continue ;
		}
		else if (ft_is_room(&input[i]))
			var->nb_rooms++;
		else if (ft_is_pipe(&input[i]))
			break ;
		while (input[i] != '\n')
			i++;
	}
	return (0);
}

t_room	*ft_loadmap(char *input, t_map *var)
{
	t_room	*map;

	var->nb_rooms = ft_count_rooms(input, var);
	if (!(map = (t_room*)malloc(sizeof(t_room) * (var->nb_rooms + 1))))
		return (NULL);

	return (map);
}
