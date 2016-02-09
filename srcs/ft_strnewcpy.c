#include "ft_printf.h"

char	*ft_strnewcpy(char *str)
{
	char	*ret;
	int		i;

	ret = ft_strnew((int)ft_strlen(str));
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	return (ret);
}