/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_priv.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:07:25 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/05 16:05:32 by pqueiroz         ###   ########.fr       */
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

void			ftpf_print_chr(t_pinfo *i, va_list *ap);
void			ftpf_print_flt(t_pinfo *i, va_list *ap);
void			ftpf_print_hex(t_pinfo *i, va_list *ap);
void			ftpf_print_int(t_pinfo *i, va_list *ap);
void			ftpf_print_oct(t_pinfo *i, va_list *ap);
void			ftpf_print_pct(t_pinfo *i);
void			ftpf_print_ptr(t_pinfo *i, va_list *ap);
void			ftpf_print_str(t_pinfo *i, va_list *ap);
void			ftpf_print_uns(t_pinfo *i, va_list *ap);

int				ftpf_print_color(const char **str, size_t *res);

#endif
