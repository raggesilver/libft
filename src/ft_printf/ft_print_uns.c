/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 22:06:18 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/05 16:06:56 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_priv.h"

/*
** Returns 1 if precision must be fixed
*/

static int		ftpf_uns_edge(t_pinfo *i, t_string *s)
{
	if (i->precision == 0 && s->data[i->fix] == '0')
	{
		if (i->min_width == 0)
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

void			ftpf_print_uns(t_pinfo *i, va_list *ap)
{
	t_string	*str;
	char		*tmp;

	if (i->flags & LL)
		tmp = ft_ulltoa(va_arg(*ap, unsigned long long));
	else if (i->flags & L)
		tmp = ft_ultoa(va_arg(*ap, unsigned long));
	else if (i->flags & HH)
		tmp = ft_utoa((unsigned char)va_arg(*ap, unsigned int));
	else if (i->flags & H)
		tmp = ft_utoa((unsigned short)va_arg(*ap, unsigned int));
	else
		tmp = ft_utoa(va_arg(*ap, unsigned int));
	str = ft_string_new(tmp);
	i->fix = 0;
	if (ftpf_uns_edge(i, str))
		ftpf_fix_precision(i, str);
	ftpf_fix_width(i, str);
	i->res = write(1, str->data, str->length);
	ft_strdel(&tmp);
	ft_string_destroy(&str);
}
