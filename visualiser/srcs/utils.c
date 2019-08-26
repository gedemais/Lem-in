/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 18:28:38 by gedemais          #+#    #+#             */
/*   Updated: 2019/06/10 22:03:40 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int		ft_exit(void)
{
	exit(EXIT_SUCCESS);
}

char	*ft_clear_image(void *param, char *img_data)
{
	ft_memset(((t_mlx*)param)->img_data, 0, HGT * WDT * 4);
	mlx_put_image_to_window((t_mlx*)param, ((t_mlx*)param)->mlx_win,
			((t_mlx*)param)->img_ptr, 0, 0);
	return (img_data);
}
