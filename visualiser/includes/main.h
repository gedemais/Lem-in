/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:50:23 by gedemais          #+#    #+#             */
/*   Updated: 2019/06/10 22:47:32 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HGT 400
# define WDT 400
# define KEY_PRESS 2
# define KEY_PRESS_MASK (1L<<0)
# define BUFF_READ 8192

# define NB_C 4

# include "../../libft/libft.h"
# include "mlx.h"
# include "/System/Library/Frameworks/OpenCL.framework/Versions/A/Headers/cl.h"
# include <stdbool.h>
# include <time.h>

typedef struct				s_point
{
	int	x;
	int	y;
}					t_point;

typedef struct				s_pipe
{
	float				start;
	float				end;
	float				x_ls;
	float				y_ls;
	float				x_le;
	float				y_le;
	float				x_rs;
	float				y_rs;
	float				x_re;
	float				y_re;
}					t_pipe;

typedef struct				s_room
{
	char				*name;
	float				x;
	float				y;
	char				type;
}					t_room;

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*mlx_win;
	void				*img_ptr;
	char				*img_data;
	t_room				*graph;
	t_pipe				*pipes;
	int					bpp;
	int					s_l;
	int					endian;
	unsigned int				room_size;
	unsigned int				nb_pipes;
}						t_mlx;

int					render(t_mlx *env);
void					ft_fill_pixel(char *img_str, int x, int y, int color);
char					*ft_clear_image(void *param, char *img_data);
void					draw_circle(t_mlx *env, t_room *room, float radius, int color);
int					link_pipes(t_mlx *env);

int						ft_exit(void);
int						ft_deal_key(int key, void *param);

int						ft_press(int button, int x, int y, void *param);
int						ft_pos(int x, int y, void *param);

#endif
