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

# define HGT 820
# define WDT 1280
# define KEY_PRESS 2
# define KEY_PRESS_MASK (1L<<0)
# define BUFF_READ 8192

# define NB_C 4

# define MAX_PIPES 8192

# include "../../libft/libft.h"
# include "mlx.h"
# include "/System/Library/Frameworks/OpenCL.framework/Versions/A/Headers/cl.h"
# include <stdbool.h>
# include <stdio.h>
# include <time.h>
# include <limits.h>

typedef struct			s_point
{
	float				x;
	float				y;
}						t_point;

typedef	struct			s_ant
{
	t_point				pos;
	t_point				goal;
	unsigned int		id;
}						t_ant;

typedef struct				s_pipe
{
	t_point				start;
	t_point				end;
	unsigned int		i_start;
	unsigned int		i_end;
}					t_pipe;

typedef struct			s_room
{
	char				*name;
	float				x;
	float				y;
	int					ant;
	char				type;
}						t_room;

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*mlx_win;
	void				*img_ptr;
	char				*img_data;
	char				*input;
	t_room				*graph;
	t_pipe				*pipes;
	t_ant				*ants;
	int					bpp;
	int					s_l;
	int					endian;
	int					file_size;
	unsigned int		nb_rooms;
	unsigned int		nb_ants;
	unsigned int		room_size;
	unsigned int		nb_pipes;
	float				speed;
}						t_mlx;

int						render(t_mlx *env);
int						cross_ant(t_mlx *env, t_room goal, unsigned int ant);
void					ft_fill_pixel(char *img_str, int x, int y, int color);
char					*ft_clear_image(void *param, char *img_data);
void					draw_circle(t_mlx *env, t_point point, float radius, int color);
int						draw_pipes(t_mlx *env);

int						ft_exit(void);
int						ft_deal_key(int key, void *param);

int						ft_press(int button, int x, int y, void *param);
int						ft_pos(int x, int y, void *param);

// parsing
char					*read_fd_zero(int *len);
bool					is_room(char *line);
bool					is_pipe(char *line);
bool					is_comment(char *line);
int						load_line(t_mlx *env, char s, unsigned int i, int room);
t_room					*make_graph(t_mlx *env, int *j);
t_pipe					*make_pipes(t_mlx *env, int *index);
char					get_line_state(char *line, bool flush);
void					next_line(char *file, unsigned int *i);
unsigned int			count_rooms(char *file, unsigned int *j);
int						find_from(t_mlx *env, char *line);
int						find_to(t_mlx *env, char *line);




#endif
