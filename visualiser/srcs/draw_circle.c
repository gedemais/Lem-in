#include "../includes/main.h"

void		draw_circle(t_mlx *env, t_room *room, float radius, int color)
{
	unsigned int	i;
	unsigned int	j;
	float		dx;
	float		dy;

	i = room->x - radius;
	while (i < room->x + radius)
	{
		j = room->y - radius;
		while (j < room->y + radius)
		{
			dx = (float)(i - room->x);
			dy = (float)(j - room->y);
			if (sqrt((dx * dx) + (dy * dy)) <= radius)
				ft_fill_pixel(env->img_data, i, j, color);
			j++;
		}
		i++;
	}
}

