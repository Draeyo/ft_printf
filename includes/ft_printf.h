/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:37:37 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/18 20:12:22 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>
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
char			*ft_uitoa(unsigned int n);
char			*ft_itohex(unsigned int nb);

/* Utilitaires */
void			ft_putnbo(unsigned int nb);
void			ft_putlong(unsigned int nb);
char			*ft_strupper(char *str);
char			*ft_strrev(char *str);
int				ft_nblen(int nb);

/* strsub du % au tag de conversion */
int				ft_get_last(const char *format, int i);
char			*ft_get_tag(const char *format, int last);

/* recuperation du tag dans la structure */
int				ft_conv_tag(const char *format, p_list *lst);
char			*ft_get_flag(char *tag);
char			*ft_get_width(char *tag);
char			*ft_get_prec(char *tag);
char			*ft_get_modif(char *tag);
char			*ft_get_conv(char *tag);

#endif
