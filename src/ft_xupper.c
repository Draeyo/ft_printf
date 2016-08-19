#include "ft_printf.h"

char  *ft_xupper(char *str)
{
  int   i;

  i = 0;
  while (str[i])
  {
    if ((str[i] >= 'a' && str[i] <= 'f') || str[i] == 'x')
      str[i] -= 32;
    i++;
  }
  return (str);
}
