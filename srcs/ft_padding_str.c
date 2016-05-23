#include "ft_printf.h"

static int  ft_flags(p_list *lst)
{
  if (lst->flag && !lst->neg && ft_strchr(lst->flag, '+') && ft_plus(lst))
    return (ft_putstr("+"));
  else if (lst->flag && !lst->neg && ft_strchr(lst->flag, ' ') && ft_plus(lst))
    return (ft_putstr(" "));
  return (0);
}

static char   *ft_flag_octal(p_list *lst, char *str)
{
  if ((lst->conv == 'O' || lst->conv == 'o') && ft_strchr(lst->flag, '#'))
    str = ft_strjoin("0", str);
  return (str);
}

int   ft_padding_str(p_list *lst, char *str)
{
  int ret;
  int len;

  ret = 0;
  str = ft_flag_octal(lst, str);
  len = (int)ft_strlen(str);
  ret += ft_putstr(ft_width(lst, len));
  ret += ft_flags(lst);
  if (lst->conv != 's' && lst->conv != 'S')
    ret += ft_putstr(ft_prec(lst, len));
  if (lst->conv == 'X')
    str = ft_xupper(str);
  if (lst->conv == 's' || lst->conv == 'S')
    ret += write(1, str, (lst->prec > len && lst->prec > 0) ? lst->prec : len);
  else
    ret += ft_putstr(str);
  return(ret);
}

int   ft_padding_int(p_list *lst, intmax_t nb)
{
  int ret;
  char *str;

  ret = 0;
  if (nb < 0)
  {
    nb *= -1;
    ret += ft_putstr("-");
    lst->neg = 1;
  }
  str = ft_xtoa(nb);
  ret += ft_padding_str(lst, str);
  return (ret);
}

int   ft_padding_uint(p_list *lst, uintmax_t nb)
{
  int ret;
  char *str;

  ret = 0;
  str = ft_uxtoa(nb);
  ret += ft_padding_str(lst, str);
  return (ret);
}
