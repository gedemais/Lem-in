#include "../includes/main.h"

int		cross_ant(t_mlx *env, t_room goal, unsigned int ant)
{
	float			v[2];
	float			dist;

	env->ants[ant].goal.x = goal.x;
	env->ants[ant].goal.y = goal.y;
	
	v[0] = goal.x - env->ants[ant].pos.x;
	v[1] = goal.y - env->ants[ant].pos.y;

	dist = sqrt((v[0] * v[0]) + (v[1] * v[1]));
	v[0] /= dist;
	v[1] /= dist;
	env->ants[ant].pos.x += (v[0] * env->speed);
	env->ants[ant].pos.y += (v[1] * env->speed);
	return (0);
}
