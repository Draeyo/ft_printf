/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 14:26:16 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/19 13:58:37 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  ft_flags(t_print *lst)
{
  if (lst->flag && !lst->neg && ft_strchr(lst->flag, '+') && ft_plus(lst))
    return (ft_putstr("+"));
  else if (lst->flag && !lst->neg && ft_strchr(lst->flag, ' ') && ft_plus(lst))
    return (ft_putstr(" "));
  return (0);
}

static char   *ft_diese_o(t_print *lst, char *str)
{
  if ((lst->conv == 'O' || lst->conv == 'o') && ft_strchr(lst->flag, '#'))
    str = ft_strjoin("0", str);
  return (str);
}

static int    ft_diese_x(t_print *lst, char *str)
{
  if (ft_ishex(lst))
  {
    if (!ft_strstr(str, "0") && ft_strchr(lst->flag, '#') && (!ft_strchr(lst->flag, '0')
				|| (ft_strchr(lst->flag, '0') && ft_strchr(lst->flag, '-'))))
    {
      lst->prec -= 2;
      return (ft_putstr(lst->hex));
    }
  }
  return (0);
}

int   ft_padding_str(t_print *lst, char *str)
{
  int 	ret;
  int	len;

  ret = 0;
  str = ft_diese_o(lst, str);
  len = (int)ft_strlen(str);
  if (lst->conv == 'c')
	  len = 1;
  if ((lst->conv == 'x' || lst->conv == 'X') && ft_strchr(lst->flag, '#'))
	  len += 2;
  else if (lst->neg == 1)
	  len++;
  if (!ft_strchr(lst->flag, '-'))
    ret += ft_putstr(ft_width(lst, len));
  ret += ft_flags(lst);
  ret += ft_diese_x(lst, str);
  if (lst->conv != 's' && lst->conv != 'S')
    ret += ft_putstr(ft_prec(lst, len));
  if (lst->conv == 'X')
    str = ft_xupper(str);
  if (lst->conv == 's' || lst->conv == 'S')
    ret += write(1, str, (lst->prec < len && lst->prec > 0) ? lst->prec : len);
  else if (lst->conv == 'c')
	  ret += ft_putchar(*str);
  else
    ret += ft_putstr(str);
  if (ft_strchr(lst->flag, '-'))
    ret += ft_putstr(ft_width(lst, len));
  return (ret);
}

int   ft_padding_int(t_print *lst, intmax_t nb)
{
  int ret;
  char *str;

  ret = 0;
  if (nb < 0)
  {
    nb *= -1;
	// negatif a changer avec conditions
    ret += ft_putstr("-");
    lst->neg = 1;
  }
  str = ft_xtoa(nb);
  ret += ft_padding_str(lst, str);
  return (ret);
}

int   ft_padding_uint(t_print *lst, uintmax_t nb)
{
  int ret;
  char *str;

  ret = 0;
  str = ft_uxtoa(nb);
  ret += ft_padding_str(lst, str);
  return (ret);
}
