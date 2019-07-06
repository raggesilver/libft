/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:10:53 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/05 16:06:35 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_priv.h"

void			fk_fhash(t_string *s)
{
	if (!ft_strchr(s->data, '.'))
	{
		ft_string_append(s, ".");
	}
}

void			fk_fix_flt_width(t_pinfo *i, t_string *s)
{
	char *aux;

	aux = NULL;
	if (s->length < (size_t)i->min_width)
	{
		aux = ft_strnew(i->min_width - s->length);
		if (i->flags & ZERO)
		{
			ft_memset(aux, '0', i->min_width - s->length);
			ft_string_inpend(s, *aux == '0' ? i->fix : 0, aux);
		}
		else
		{
			ft_memset(aux, ' ', i->min_width - s->length);
			ft_string_inpend(s, (i->flags & MINUS) ? s->length : 0, aux);
		}
	}
}

void			ftpf_print_flt(t_pinfo *i, va_list *ap)
{
	long double	f;
	t_string	*s;

	f = (!(i->flags & LONG_DOUBLE)) ? (long double)(va_arg(*ap, double)) :
		(va_arg(*ap, long double));
	if (i->precision == -1)
		i->precision = 6;
	s = ft_ldtos(f, i->precision);
	if (i->flags & HASH)
		fk_fhash(s);
	ftpf_plus(i, s);
	fk_fix_flt_width(i, s);
	i->res = write(1, s->data, s->length);
	ft_string_destroy(&s);
}
