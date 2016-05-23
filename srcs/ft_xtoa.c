#include "ft_printf.h"

static int		calc_len(intmax_t nb)
{
	int		len;

	len = 0;
	if (nb < 0)
		return ((len = ft_nblen(nb) - 1));
	else
		return ((len = ft_nblen(nb)));
}

static intmax_t		calc_div(int len)
{
	intmax_t		div;

	div = 1;
	while (--len)
		div *= 10;
	return (div);
}

char			*ft_xtoa(intmax_t nb)
{
	intmax_t		div;
  uintmax_t   n;
	char	      *ret;
	int		      len;
	int		      i;

	i = 0;
	len = calc_len(nb);
	div = calc_div(len);
	ret = ft_strnew(len + 1);
  if (nb < 0)
		n = nb * -1;
  else
    n = nb;
	if (nb == 0)
		return ("0");
	while (len--)
	{
		ret[i] = ((n / div) + 48);
		n -= ((n / div) * div);
		div /= 10;
		i++;
	}
	return (ret);
}
