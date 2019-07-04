/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:33:35 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/06/25 23:35:38 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Returns 1 if precision must be fixed
*/

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

/*
** "+-0 " should be handled
** l, ll, h, hh sizes can be specified
*/

void			ftpf_print_int(t_pinfo *i, va_list *ap)
{
	t_string	*str;
	char		*tmp;

	if (i->flags & LL)
		tmp = ft_lltoa(va_arg(*ap, long long));
	else if (i->flags & L)
		tmp = ft_ltoa(va_arg(*ap, long));
	else if (i->flags & HH)
		tmp = ft_itoa((char)va_arg(*ap, int));
	else if (i->flags & H)
		tmp = ft_itoa((short)va_arg(*ap, int));
	else
		tmp = ft_itoa(va_arg(*ap, int));
	str = ft_string_new(tmp);
	ftpf_plus(i, str);
	if (ftpf_int_edge(i, str))
		ftpf_fix_precision(i, str);
	ftpf_fix_width(i, str);
	i->res = write(1, str->data, str->length);
	ft_strdel(&tmp);
	ft_string_destroy(&str);
}
