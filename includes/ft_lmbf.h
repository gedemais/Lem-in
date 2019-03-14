/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lmbf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:51:16 by gedemais          #+#    #+#             */
/*   Updated: 2019/03/13 20:19:17 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LMBF_H
# define FT_LMBF_H

# define BUFF_READ 1048576

# define TRI ((t_room)(map[i]))

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>

typedef struct	s_room t_room;

struct s_room
{
	char	*name;
	int		index;
	int		x;
	int		y;
	bool	lock;
	bool	start;
	bool	end;
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
int	ft_count_rooms(char *input, t_map *var);


#endif
