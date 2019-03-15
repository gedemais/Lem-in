#include "../includes/ft_lmbf.h"

bool	ft_is_room(char *input)
{
	int	i;

	i = 0;
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

int		ft_count_rooms(char *input, t_map *var)
{
	int		i;

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

char	*ft_strdup_ws(char *src, int *len)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i] && src[i] != ' ')
		i++;
	if (!(dest = ft_strnew(i)))
		return (NULL);
	i = 0;
	while (src[i] && src[i] != ' ')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	*len = i;
	return (dest);
}

int		ft_fill_room(char *input, t_room *room)
{
	int		i;

	i = 0;
	if (!(room->name = ft_strdup_ws(input, &room->name_len)))
		return (-1);
	while (input[i] != ' ')
		i++;
	i++;
	room->x = ft_atoi(&input[i]);
	while (input[i] != ' ')
		i++;
	i++;	
	room->y = ft_atoi(&input[i]);
	return (0);
}

t_room	*ft_loadrooms(char *input, t_map *var, int *index)
{
	t_room	*map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(map = (t_room*)malloc(sizeof(t_room) * (var->nb_rooms + 1))))
		return (NULL);
	while (input[i] && input[i] != '\n')
		i++;
	while (j < var->nb_rooms)
	{
		map[j].index = j;
		if (input[++i] == '#')
		{
			if (ft_strncmp(&input[i], "##start", 7) == 0)
			{
				PUT1
				map[j].start = true;
			}
			else
				map[j].start = false;
			if (ft_strncmp(&input[i], "##end", 5) == 0)
			{
				PUT2
				map[j].end = true;
			}
			else
				map[j].end = false;
			while (input[i] && input[i] != '\n')
				i++;
			continue ;
		}
		else if (input[i] != '#')
		{
			if (ft_fill_room(&input[i], &map[j]) == -1)
				return (NULL);
			while (input[i] && input[i] != '\n')
				i++;
		}
		j++;
	}
	map[j].x = -42;
	*index = i + 1;
	return (map);
}



t_room	*ft_loadlinks(char *input, t_room *map, t_map *var, int *index)
{
	int		i;

	i = 0;
	while (i < var->nb_rooms)
	{
		if (!(map[i].links = (int*)malloc(sizeof(int) * (ft_count_pipes(&input[*index], map[i].name, map[i].name_len) + 1))))
			return (NULL);
		i++;
	}
	return (map);
}


t_room	*ft_loadmap(char *input, t_map *var)
{
	t_room	*map;
	int		border;

	ft_count_rooms(input, var);
	if (!(map = ft_loadrooms(input, var, &border)))
		return (NULL);
	ft_print_map(map);
	if (!(map = ft_loadlinks(input, map, var, &border)))
		return (NULL);
	return (map);
}
