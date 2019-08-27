#include "../includes/main.h"

int		cross_ant(t_mlx *env, float x, float y, unsigned int ant)
{
	float			v[2];
	float			dist;

	env->ants[ant].goal.x = x;
	env->ants[ant].goal.y = y;
	
	v[0] = x - env->ants[ant].pos.x;
	v[1] = y - env->ants[ant].pos.y;

	dist = sqrt((v[0] * v[0]) + (v[1] * v[1]));
	v[0] /= dist;
	v[1] /= dist;
	env->ants[ant].pos.x += (v[0] * env->ants[ant].speed);
	env->ants[ant].pos.y += (v[1] * env->ants[ant].speed);
	return (0);
}
