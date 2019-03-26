/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 08:12:06 by qudesvig          #+#    #+#             */
/*   Updated: 2018/11/26 20:46:16 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <sys/types.h>
# include <fcntl.h>
# define BUFF_SIZE 1

int		get_next_line(const int fd, char **line);
char	*ft_read(const int fd, char *str, unsigned int cycle);
char	*ft_realloc(char *line, unsigned int size);
void	ft_adjust(char *str);
#endif
