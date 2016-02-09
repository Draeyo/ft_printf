#include "ft_printf.h"

int		ft_s_atoi(char *str)
{
	int		ret;
	int		mult;
	int		i;

	i = ft_strlen(str);
	mult = 1;
	ret = 0;
	while (ft_isdigit(str[i]))
	{
		ret += ((str[i] - 48) * mult);
		mult *= 10;
		i--;
	}
	if (str[i] == '-')
		ret *= -1;
	return (ret);
}

long	ft_s_atol(char *str)
{
	long	ret;
	long	mult;
	int		i;

	i = ft_strlen(str);
	mult = 1;
	ret = 0;
	while (ft_isdigit(str[i]))
	{
		ret += ((str[i] - 48) * mult);
		mult *= 10;
		i--;
	}
	if (str[i] == '-')
		ret *= -1;
	return (ret);
}