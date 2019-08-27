#include "../includes/main.h"

void		draw_circle(t_mlx *env, t_point point, float radius, int color)
{
	unsigned int	i;
	unsigned int	j;
	float		dx;
	float		dy;

	i = point.x - radius;
	while (i < point.x + radius)
	{
		j = point.y - radius;
		while (j < point.y + radius)
		{
			dx = (float)(i - point.x);
			dy = (float)(j - point.y);
			if (sqrt((dx * dx) + (dy * dy)) <= radius)
				ft_fill_pixel(env->img_data, i, j, color);
			j++;
		}
		i++;
	}
}

