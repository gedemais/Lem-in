#include "main.h"

int		display(t_env *env)
{
	write(1, env->file, (size_t)env->file_len);
	write(1, "\n", 1);

	return (0);
}
