#include "libft.h"

char		*ft_sed(char *hystack, char *needle, char *replace)
{
	char		*new;
	unsigned int	*instances;
	unsigned int	nb_oc;
	unsigned int	new_len;

	if ((nb_oc = count_insts(hystack, needle)) == 0)
		return (hystack);
	if (!(instances = get_instances(hystack, needle)))
		return (NULL);
	new_len = (ft_strlen(hystack) - (nb_oc * ft_strlen(needle)))
	new_len += (nb_oc * ft_strlen(replace));
	if (!(new = ft_strnew(new_len)))
		return (NULL);
}
