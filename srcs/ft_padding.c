#include "ft_printf.h"

char	*ft_width(p_list *lst, int len)
{
	char	*width;
	int		i;

	i = 0;
	if (len - lst->width <= 0)
		return (NULL);
	if (lst->prec)
		lst->width -= lst->prec;
	if (!(width = ft_strnew(lst->width)))
		return (NULL);
	while(width[i++])
		width[i] = ' ';
	return (width);
}

char	*ft_prec(p_list *lst, int len)
{
	char	*prec;
	int		i;

	i = 0;
	if (len - lst->prec <= 0)
		return (NULL);
	prec = ft_strnew(lst->prec);
	while(prec[i++])
		prec[i] = '0';
	return (prec);
}

char	*ft_padding(char *width, char *prec)
{
	char	*padding;

	if (!(padding = ft_strjoin(width, prec)))
		return (NULL);
	return (padding);
}
