/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:11:37 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/03 22:24:28 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define _PF format(printf, 1, 2)

# include "../libft.h"
# include <stdarg.h>

enum			e_pflags
{
	HASH = 1,
	PLUS = 2,
	MINUS = 4,
	ZERO = 8,
	SPACE = 16,
	H = 32,
	HH = 64,
	L = 128,
	LL = 256,
	LONG_DOUBLE = 512
};

typedef struct	s_pinfo
{
	char		conv;
	int			flags;
	int			min_width;
	int			precision;
	int			fix;
	size_t		res;
}				t_pinfo;

int				ft_printf(const char *s, ...) __attribute__((_PF));

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
