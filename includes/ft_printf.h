/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:37:37 by vlistrat          #+#    #+#             */
/*   Updated: 2016/02/09 16:53:04 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>
# include <limits.h>
# include "libft.h"

# define DEBUG ft_putendl("DEBUG");

/* strcture de recuperation du tag entier puis des elements du tag 1 par 1 */
typedef struct		ft_list
{
	char			*tag;
	char			*flag;
	int				width;
	int				prec;
	char			*modif;
	char			conv;
	int				len;
}					p_list;

/* fonction principale */
int				ft_printf(const char *format, ...);

/* envoi vers fonction de conv correspondante */
int				ft_tag(va_list ap, p_list *lst);

/* fonctions de recuperation argument et conversion */
int				ft_conv_s(va_list ap, p_list *lst);
int				ft_conv_d(va_list ap, p_list *lst);
int				ft_conv_p(va_list ap, p_list *lst);
int				ft_conv_x(va_list ap, p_list *lst);
int				ft_conv_c(va_list ap, p_list *lst);
int				ft_conv_o(va_list ap, p_list *lst);
int				ft_conv_ws(va_list ap, p_list *lst);
int				ft_conv_wc(va_list ap, p_list *lst);
int				ft_conv_u(va_list ap, p_list *lst);
int				ft_noconv(p_list *lst);

/* conversions divers */
unsigned int	ft_itoo(unsigned int nb);
unsigned long long		ft_lltoo(unsigned long long nb);
char			*ft_uitoa(unsigned int n);
char			*ft_itohex(unsigned int nb);
char			*ft_lltohex(unsigned long long nb);
int 			ft_s_atoi(char *str);
long			ft_s_atol(char *str);
char			*ft_s_itoa(int nb);
char			*ft_s_ltoa(long nb);

/* Utilitaires */
void			ft_putnbo(unsigned int nb);
void			ft_putlong(unsigned long long nb);
void			ft_put_unsigned_int(unsigned int nb);
char			*ft_strupper(char *str);
char			*ft_strrev(char *str);
int				ft_nblen(int nb);
int				ft_unblen(unsigned int nb);
int				ft_llnblen(long long nb);
void			lst_init(p_list *lst);
void			ft_putwchar_fd(wchar_t c, int fd);
void			ft_putwstr_fd(wchar_t *wstr, int fd);
char			*ft_strnewcpy(char *str);

/* strsub du % au tag de conversion */
int				ft_get_last(const char *format, int i);
char			*ft_get_tag(const char *format, int last);

/* recuperation du tag dans la structure */
int				ft_conv_tag(const char *format, p_list *lst);
int				ft_get_flag(char *tag, p_list *lst);
int				ft_get_width(char *tag, p_list *lst);
int				ft_get_prec(char *tag, p_list *lst);
int				ft_get_modif(char *tag, p_list *lst);
int				ft_get_conv(char *tag, p_list *lst);

/* verifications du flag */
int				ft_isconv(int c);
int				ft_ismod(int c);
int				ft_validmod(char *str);
int				ft_after_flag(int c);
int				ft_after_width(int c);
int				ft_after_prec(int c);

/* Options */
char				*ft_width(p_list *lst, int len);
char				*ft_prec(p_list *lst, int len);
char				*ft_padding(char *width, char *prec, char *elem, p_list *lst);

#endif
