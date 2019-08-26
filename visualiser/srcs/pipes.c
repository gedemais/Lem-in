#include "../includes/main.h"

static void	draw_line(t_mlx *env, t_point f, t_point s)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	delta.x = abs(s.x - f.x);
	delta.y = abs(s.y - f.y);
	sign.x = f.x < s.x ? 1 : -1;
	sign.y = f.y < s.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = f;
	while (cur.x != s.x || cur.y != s.y)
	{
		ft_fill_pixel(env->img_data, cur.x, cur.y, 0xffffff);
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

void	fill_pipe(t_pipe *pipe, t_room *start, t_room *end, float scale)
{
	float	sq[2];
	float	tmp;
	float	dist;

	sq[0] = end->x - start->x;
	sq[1] = end->y - start->y;
	dist = sqrt((sq[0] * sq[0]) + (sq[1] * sq[1]));
	sq[0] /= dist;
	sq[1] /= dist;
	tmp = sq[0];
	sq[0] = sq[1];
	sq[1] = tmp;
	pipe->x_ls = start->x - (sq[1] * scale);
	pipe->y_ls = start->y - (sq[0] * scale);
	pipe->x_le = end->x + (sq[1] * scale);
	pipe->y_le = end->y + (sq[0] * scale);
	pipe->x_rs = start->x + (sq[1] * scale);
	pipe->y_rs = start->y + (sq[0] * scale);
	pipe->x_re = end->x - (sq[1] * scale);
	pipe->y_re = end->y - (sq[0] * scale);
}

void	draw_pipe(t_mlx *env, t_point start, t_point end)
{
	unsigned int	i;
	unsigned int	j;
	t_point		s;
	t_point		e;

	s = start;
	e = end;
	i = 0;
	start.x--;
	start.y--;
	end.x--;
	end.y--;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			start.x = s.x + j;
			start.y = s.y + i;
			end.x = e.x + j;
			end.y = e.y + i;
			draw_line(env, start, end);
			j++;
		}
		i++;
	}
}

int	link_pipes(t_mlx *env)
{
	t_point		start;
	t_point		end;
	unsigned int	i;

	i = 0;
	start.x = 0;
	start.y = 0;
	end.x = 100;
	end.y = 200;
	while (i < env->nb_pipes)
	{
		fill_pipe(&env->pipes[i], &env->graph[(int)env->pipes[i].start], &env->graph[(int)env->pipes[i].end], 10);
		start.x = env->pipes[i].x_ls;
		start.y = env->pipes[i].y_ls;
		end.x = env->pipes[i].x_le;
		end.y = env->pipes[i].y_le;
		draw_pipe(env, start, end);
		i++;
	}
	return (0);
}
