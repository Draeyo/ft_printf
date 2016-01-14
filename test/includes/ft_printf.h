#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
#include <wchar.h>
# include "libft.h"

# define DEBUG ft_putendl("DEBUG");

int				ft_printf(const char *format, ...);
int				ft_tag(const char *format, va_list ap);
int				ft_conv_s(const char *format, va_list ap);
int				ft_conv_d(const char *format, va_list ap);
int				ft_conv_p(const char *format, va_list ap);
int				ft_conv_x(const char *format, va_list ap);
int				ft_conv_c(const char *format, va_list ap);
int				ft_conv_o(const char *format, va_list ap);
int				ft_conv_ws(const char *format, va_list ap);
int				ft_conv_wc(const char *format, va_list ap);
int				ft_conv_u(const char *format, va_list ap);
int				ft_noconv(const char *format);
char			*ft_uitoa(unsigned int n);
char			*ft_itohex(unsigned int nb);
unsigned int	ft_itoo(unsigned int nb);
void			ft_putnbo(unsigned int nb);
int				ft_nblen(int nb);
void			ft_putlong(unsigned int nb);
char			*ft_strupper(char *str);
char			*ft_strrev(char *str);
int				ft_get_last(const char *format, int i);
char			*ft_get_tag(const char *format, int last);

#endif
