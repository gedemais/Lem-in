#include "../includes/main.h"

void		draw_rooms(t_mlx *env)
{
	t_point			pos;
	unsigned int	i;
	float		center;
	int			color;

	i = 0;
	center = env->room_size - (env->room_size / 8);
	while (env->graph[i].name)
	{
		pos.x = env->graph[i].x;
		pos.y = env->graph[i].y;
		draw_circle(env, pos, env->room_size, 0xffffff);
		color = (env->graph[i].type == 's') ? 0x5962ca : 0xc8c800;
		color = (env->graph[i].type == 'e') ? 0x00cc00 : color;
		draw_circle(env, pos, center, color);
		i++;
	}
}

void	draw_ants(t_mlx *env)
{
	unsigned int	i;

	i = 0;
	while (i < env->nb_ants)
	{
		draw_circle(env, env->ants[i].pos, 10, 0x00ff00);
		i++;
	}
}

int		render(t_mlx *env)
{
	ft_memset(env->img_data, 0x666600, sizeof(int) * HGT * WDT);
	draw_pipes(env);
	draw_rooms(env);
	draw_ants(env);
	mlx_put_image_to_window(env, env->mlx_win, env->img_ptr, 0, 0);
	return (0);
}
