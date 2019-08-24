#include "main.h"

int		*max_index(void)
{
	static int	index = 0;

	(void)index;
	return (&index);
}
