/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 22:38:33 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/12/26 14:45:16 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_priv.h"

const char		*g_flags = "#0-+ ";

static t_pinfo	*parse_flags(const char **s)
{
	t_pinfo		*res;

	res = malloc(sizeof(*res));
	res->flags = 0;
	while (**s && ft_strchr(g_flags, **s))
	{
		if (**s == '#')
			res->flags |= HASH;
		else if (**s == '0' && !(res->flags & MINUS))
			res->flags |= ZERO;
		else if (**s == ' ' && !(res->flags & PLUS))
			res->flags |= SPACE;
		else if (**s == '-')
		{
			res->flags &= ~ZERO;
			res->flags |= MINUS;
		}
		else if (**s == '+')
		{
			res->flags &= ~SPACE;
			res->flags |= PLUS;
		}
		(*s)++;
	}
	return (res);
}

static t_pinfo	*parse_width(const char **s, t_pinfo *i, va_list *ap)
{
	i->min_width = 0;
	i->res = 0;
	if (**s == '*' && ((*s)++ || 1))
		blah(i, &i->min_width, va_arg(*ap, int));
	else if (ft_isdigit(**s))
	{
		i->min_width = ft_atoi(*s);
		(*s) += ft_int_len(i->min_width);
	}
	i->precision = -1;
	if (**s == '.')
	{
		if (*(++(*s)) == '*' && ((*s)++ || 1))
		{
			i->precision = va_arg(*ap, int);
			i->precision = (-1 > i->precision) ? -1 : i->precision;
		}
		else
		{
			i->precision = ft_atoi(*s);
			while (ft_isdigit(**s))
				(*s)++;
		}
	}
	return (i);
}

static t_pinfo	*parse_length(const char **s, t_pinfo *i)
{
	if (ft_strncmp(*s, "hh", 2) == 0 && (((*s) += 2) || 1))
		i->flags |= HH;
	else if (ft_strncmp(*s, "ll", 2) == 0 && (((*s) += 2) || 1))
		i->flags |= LL;
	else if (**s == 'l' && (((*s) += 1) || 1))
		i->flags |= L;
	else if (**s == 'h' && (((*s) += 1) || 1))
		i->flags |= H;
	else if (**s == 'L' && (((*s) += 1) || 1))
		i->flags |= LONG_DOUBLE;
	return (i);
}

static void		ftpf_dispatch(t_string *buf, t_pinfo *i, va_list *ap)
{
	if (i->conv == 'c')
		ftpf_print_chr(buf, i, ap);
	else if (i->conv == 'd' || i->conv == 'i')
		ftpf_print_int(buf, i, ap);
	else if (i->conv == 'o')
		ftpf_print_oct(buf, i, ap);
	else if (i->conv == 'u')
		ftpf_print_uns(buf, i, ap);
	else if (i->conv == 'x' || i->conv == 'X')
		ftpf_print_hex(buf, i, ap);
	else if (i->conv == 's')
		ftpf_print_str(buf, i, ap);
	else if (i->conv == 'p')
		ftpf_print_ptr(buf, i, ap);
	else if (i->conv == 'f')
		ftpf_print_flt(buf, i, ap);
	else if (i->conv == '%')
		ftpf_print_pct(buf, i);
}

t_string		*ft_vsprintf(const char *s, va_list ap)
{
	t_pinfo		*i;
	t_string	*buf;
	va_list		lap;

	va_copy(lap, ap);
	buf = ft_string_new_with_config(NULL, (t_string_cfg){
		.growmode=T_STRING_GROWMODE_QUADRATIC, .extra=100
	});
	while (*s)
	{
		if (*s == '{' && ftpf_print_color(buf, &s))
			;
		else if (*s != '%')
			ft_string_appendn(buf, s++, 1);
		else if (*(++s))
		{
			i = parse_flags(&s);
			(*s) ? i = parse_width(&s, i, &lap) : 0;
			(*s) ? i = parse_length(&s, i) : 0;
			(*s) ? i->conv = *s++ : 0;
			ftpf_dispatch(buf, i, &lap);
			ft_memdel((void **)&i);
		}
	}
	return (buf);
}
