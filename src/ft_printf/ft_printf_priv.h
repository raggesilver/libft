/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_priv.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:07:25 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/14 22:57:16 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRIV_H
# define FT_PRINTF_PRIV_H

# include "ft_printf.h"

void			blah(t_pinfo *i, int *p, int n);

void			ftpf_fix_precision(t_pinfo *i, t_string *s);
void			ftpf_fix_width(t_pinfo *i, t_string *s);
void			ftpf_fix_zero(t_pinfo *i, t_string *s);
void			ftpf_plus(t_pinfo *i, t_string *s);

void			ftpf_print_chr(t_string *buf, t_pinfo *i, va_list *ap);
void			ftpf_print_flt(t_string *buf, t_pinfo *i, va_list *ap);
void			ftpf_print_hex(t_string *buf, t_pinfo *i, va_list *ap);
void			ftpf_print_int(t_string *buf, t_pinfo *i, va_list *ap);
void			ftpf_print_oct(t_string *buf, t_pinfo *i, va_list *ap);
void			ftpf_print_pct(t_string *buf, t_pinfo *i);
void			ftpf_print_ptr(t_string *buf, t_pinfo *i, va_list *ap);
void			ftpf_print_str(t_string *buf, t_pinfo *i, va_list *ap);
void			ftpf_print_uns(t_string *buf, t_pinfo *i, va_list *ap);

int				ftpf_print_color(t_string *buf, const char **str);

#endif
