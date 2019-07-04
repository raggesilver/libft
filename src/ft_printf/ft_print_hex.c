/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 22:29:24 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/06/26 13:03:45 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ftpf_int_edge(t_pinfo *i, t_string *s)
{
	if (i->precision == 0 && s->data[i->fix] == '0')
	{
		if (i->min_width == 0 || i->flags & PLUS)
		{
			s->data[i->fix] = 0;
			s->length--;
			return (0);
		}
		else
			s->data[i->fix] = ' ';
	}
	return (1);
}

static char		*get_int_string(t_pinfo *i, va_list *ap)
{
	char		*tmp;

	if (i->flags & LL)
		tmp = ft_ulltoa_base(va_arg(*ap, unsigned long long), 16);
	else if (i->flags & L)
		tmp = ft_ultoa_base(va_arg(*ap, unsigned long), 16);
	else if (i->flags & HH)
		tmp = ft_utoa_base((unsigned char)va_arg(*ap, unsigned), 16);
	else if (i->flags & H)
		tmp = ft_utoa_base((unsigned short)va_arg(*ap, unsigned), 16);
	else
		tmp = ft_utoa_base(va_arg(*ap, unsigned), 16);
	return (tmp);
}

void			ftpf_print_hex(t_pinfo *i, va_list *ap)
{
	t_string	*str;
	char		*tmp;

	tmp = get_int_string(i, ap);
	if (i->precision == 0 && *tmp == '0')
		str = ft_string_new("");
	else
		str = ft_string_new((i->flags & HASH && *tmp != '0') ? "0X" : "");
	ft_string_append(str, tmp);
	if (i->conv == 'x')
		ft_string_to_lower(str);
	ftpf_plus(i, str);
	if (ftpf_int_edge(i, str))
		ftpf_fix_precision(i, str);
	ftpf_fix_width(i, str);
	i->res = write(1, str->data, str->length);
	ft_strdel(&tmp);
	ft_string_destroy(&str);
}
