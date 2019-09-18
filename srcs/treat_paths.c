#include "main.h"

static inline unsigned int	graph_cap(t_env *env)
{
	unsigned int	i;
	unsigned int	ret;

	i = 0;
	ret = 0;
	while (i < env->nb_paths)
	{
		ret += env->paths[i].len;
		i++;
	}
	return (ret);
}

static inline int		load_ammos(t_env *env)
{
	unsigned int	i;
	unsigned int	min;
	unsigned int	tot;

	tot = 0;
	min = env->paths[0].len;
	i = 0;
	while (tot <= env->nb_ants)
	{
		i = 0;
		while (i < env->nb_paths && tot <= env->nb_ants)
		{
			if (env->paths[i].len <= min)
			{
				env->paths[i].len++;
				env->paths[i].ammos++;
				tot++;
			}
			i++;
		}
		min++;
	}
	return (0);
}

int				treat_paths(t_env *env)
{
	unsigned int	graph_c;

	if ((graph_c = graph_cap(env)) == 0)
		return (1);
	sort_paths(env);
	load_ammos(env);
/*	if (env->nb_ants < env->paths[0].len) // Si il y a moins de fourmis que de salle dans le chemin le plus court, on envoie toutes les fourmis dedans en condamnant le tableau de paths
	{
		env->nb_paths = 1;
		env->paths[1].path[0] = -1;
	}*/
/*	else if (env->nb_ants <= graph_c)
	{
	}
//	else
//		choose_paths(env);
	// Sinon, aucun traitement supplementaire*/
	return (0);
}
