/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:37:37 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/19 14:43:16 by vlistrat         ###   ########.fr       */
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

/*
** strcture de recuperation du tag entier puis des elements du tag 1 par 1
*/
typedef struct		s_print
{
	char			*tag;
	char			*flag;
	int				width;
	int				prec;
	char			*modif;
	char			conv;
	int				len;
	int				neg;
	char			*hex;
	char			*str;
	char			*wstr;
	char			*pstr;
}					t_print;

/*
** fonction principale
*/
int					ft_printf(const char *format, ...);

/*
** envoi vers fonction de conv correspondante
*/
int					ft_tag(va_list ap, t_print *lst);

/*
** fonctions de recuperation argument et conversion
*/
int					ft_conv_s(va_list ap, t_print *lst);
int					ft_conv_d(va_list ap, t_print *lst);
int					ft_conv_p(va_list ap, t_print *lst);
int					ft_conv_x(va_list ap, t_print *lst);
int					ft_conv_c(va_list ap, t_print *lst);
int					ft_conv_o(va_list ap, t_print *lst);
int					ft_conv_ws(va_list ap, t_print *lst);
int					ft_conv_wc(va_list ap, t_print *lst);
int					ft_conv_u(va_list ap, t_print *lst);
int					ft_noconv(t_print *lst);

/*
** conversions divers
*/
uintmax_t		ft_itoo(uintmax_t nb);
char				*ft_itohex(uintmax_t nb);
int					ft_s_atoi(char *str);
char				*ft_xtoa(intmax_t nb);
char				*ft_uxtoa(uintmax_t nb);

/*
** Utilitaires
*/
char				*ft_uitooa(uintmax_t nb);
char				*ft_strupper(char *str);
char				*ft_strrev(char *str);
int					ft_nblen(intmax_t nb);
int					ft_uxnblen(uintmax_t nb);
void				lst_init(t_print *lst);
void				ft_putwchar_fd(wchar_t c, int fd);
void				ft_putwstr_fd(wchar_t *wstr, int fd);
char				*ft_strnewcpy(char *str);
char				*ft_strcut(char *str, int n);
char				*ft_xupper(char *str);
char				*ft_strnew_digit(int nb, int fill);
int					ft_tag_error(t_print *lst, const char *format);
int					ft_plus(t_print *lst);
int					ft_ishex(t_print *lst);
/*
** strsub du % au tag de conversion
*/
int					ft_get_last(const char *format, int i);
char				*ft_get_tag(const char *format, int last);

/*
** recuperation du tag dans la structure
*/
int					ft_conv_tag(const char *format, t_print *lst);
int					ft_get_flag(char *tag, t_print *lst);
int					ft_get_width(char *tag, t_print *lst);
int					ft_get_prec(char *tag, t_print *lst);
int					ft_get_modif(char *tag, t_print *lst);
int					ft_get_conv(char *tag, t_print *lst);

/*
** verifications du flag
*/
int					ft_isconv(int c);
int					ft_ismod(int c);
int					ft_validmod(char *str);
int					ft_after_flag(int c);
int					ft_after_width(int c);
int					ft_after_prec(int c);
int					ft_is_c(t_print *lst);

/*
** Options
*/
char				*ft_width(t_print *lst, int len);
char				*ft_prec(t_print *lst, int len);
char				*ft_padding(char *width, char *prec, char *elem, t_print *lst);
int					ft_padding_str(t_print *lst, char *str);
int					ft_padding_int(t_print *lst, intmax_t nb);
int					ft_padding_uint(t_print *lst, uintmax_t nb);

#endif
