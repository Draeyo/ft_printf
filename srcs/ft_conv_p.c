#include "ft_printf.h"

// HOME

int	ft_conv_p(va_list ap, t_print *lst)
{
	void		*p;
	unsigned int	stock;
	char		*ret;

	stock = 0;
	ret = ft_strnew(30);
	p = va_arg(ap, void*);
	if (!p)
		HEX = "0x";
	else
		HEX = "0x7fff";
	stock = (unsigned int)p;
	if (!ZEROP)
		ret = ft_itohex(stock);
	return (ft_padding_str(lst, ret));
}
