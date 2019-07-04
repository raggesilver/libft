/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 22:27:41 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/23 14:09:32 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Returns 1 if precision must be fixed
*/

static int		ftpf_int_edge(t_pinfo *i, t_string *s)
{
	if (i->precision == 0 && s->data[i->fix] == '0' && !(i->flags & HASH))
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

void			ftpf_print_oct(t_pinfo *i, va_list *ap)
{
	t_string	*str;
	char		*tmp;

	if (i->flags & LL)
		tmp = ft_ulltoa_base(va_arg(*ap, unsigned long long), 8);
	else if (i->flags & L)
		tmp = ft_ultoa_base(va_arg(*ap, unsigned long), 8);
	else if (i->flags & HH)
		tmp = ft_utoa_base((unsigned char)va_arg(*ap, unsigned), 8);
	else if (i->flags & H)
		tmp = ft_utoa_base((unsigned short)va_arg(*ap, unsigned), 8);
	else
		tmp = ft_utoa_base(va_arg(*ap, unsigned), 8);
	str = ft_string_new((i->flags & HASH && *tmp != '0') ? "0" : "");
	ft_string_append(str, tmp);
	ftpf_plus(i, str);
	if (ftpf_int_edge(i, str))
		ftpf_fix_precision(i, str);
	ftpf_fix_width(i, str);
	i->res = write(1, str->data, str->length);
	ft_strdel(&tmp);
	ft_string_destroy(&str);
}
