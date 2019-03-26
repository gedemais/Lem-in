/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lmbf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:51:16 by gedemais          #+#    #+#             */
/*   Updated: 2019/03/15 14:37:44 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LMBF_H
# define FT_LMBF_H

# define BUFF_READ 1048576

# define PUT ft_putstr("There\n");
# define PUT1 ft_putstr("There1\n");
# define PUT2 ft_putstr("There2\n");
# define PUT3 ft_putstr("There3\n");
# define PUT4 ft_putstr("There4\n");
# define PUT5 ft_putstr("There5\n");
# define PUT6 ft_putstr("There6\n");
# define PUT7 ft_putstr("There7\n");

# define TRI ((t_room)(map[i]))

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>

typedef struct	s_room t_room;

struct s_room
{
	char	*name;
	int		name_len;
	int		index;
	int		x;
	int		y;
	bool	lock;
	bool	start;
	bool	end;
	int		nlinks;
	int		*links;
};

typedef struct 	s_map
{
	int		nb_rooms;
	int		nb_lems;
	int		nb_pipes;
	int		start;
	int		end;
}				t_map;


char	*ft_read(int fd);
t_room	*ft_loadmap(char *input, t_map *var);
int		ft_count_rooms(char *input, t_map *var);
void	ft_print_map(t_room *map);


#endif
