#include "../includes/main.h"

void		draw_rooms(t_mlx *env)
{
	unsigned int	i;
	float		center;

	i = 0;
	center = env->room_size - (env->room_size / 10);
	while (i < 2)
	{
		draw_circle(env, &env->graph[i], env->room_size, 0xffffff);
		draw_circle(env, &env->graph[i], center, 0xc8c800);
		i++;
	}
}

int		render(t_mlx *env)
{
	ft_memset(env->img_data, 0x192800, sizeof(int) * HGT * WDT);
	link_pipes(env);
	draw_rooms(env);
	return (0);
}
