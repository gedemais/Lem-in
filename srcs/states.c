#include "main.h"

static inline bool	is_coords(char *line, unsigned int *j)
{
	unsigned int	i;

	i = *j;
	while (ft_is_whitespace(line[i]) && i > 0)
		i--;
	if (i == 0 || ft_isdigit(line[i]) == 0)
		return (false);
	while (ft_isdigit(line[i]) && i > 0)
		i--;
	if (i == 0 || ft_is_whitespace(line[i]) == 0)
		return (false);
	while (ft_is_whitespace(line[i]) && i > 0)
		i--;
	if (i == 0 || ft_isdigit(line[i]) == 0)
		return (false);
	while (ft_isdigit(line[i]) && i > 0)
		i--;
	if (i == 0 || ft_is_whitespace(line[i]) == 0)
		return (false);
	*j = i;
	return (true);
}

bool			is_room(char *line)
{
	unsigned int	i;

	i = 0;
	if (line[0] == '#' || line[0] == 'L')
		return (false);
	while (line[i] && line[i] != '\n')
		i++;
	if (i < 5)
		return (false);
	i--;
	if (is_coords(line, &i) == false)
		return (false);
	while (i > 0 && ft_is_whitespace(line[i]))
		i--;
	if (i == 0 && ft_is_whitespace(line[i]))
		return (false);
	while (i > 0 && ft_is_whitespace(line[i]) == 0)
		i--;
	if (i > 0)
		return (false);
	return (true);
}

bool			is_pipe(char *line)
{
	unsigned int	i;
	unsigned int	dash;

	i = 0;
	dash = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '-')
		{
			if (i == 0 || line[i + 1] == 0 || line[i + 1] == '\n')
				return (false);
			dash++;
		}
		i++;
	}
	if (dash != 1 ||  i < 3)
		return (false);
	return (true);
}

bool			is_comment(char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (true);
	return (false);
}

bool			is_cmd(char *line)
{
	if (line[0] == '#' && line[1] == '#' && line[2] != '#')
		return (true);
	return (false);
}
