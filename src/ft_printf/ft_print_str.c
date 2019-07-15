/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 21:13:04 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/14 22:37:15 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_priv.h"

/*
** '-' is the only flag that works with %s
** precision limits the length of the original string before the min-width
**     is applied.
*/

void		ftpf_print_str(t_string *buf, t_pinfo *i, va_list *ap)
{
	t_string	*str;
	char		*tmp;

	tmp = va_arg(*ap, char *);
	if (i->precision > -1)
		tmp = ft_strndup((tmp) ? tmp : "(null)", i->precision);
	str = ft_string_new((tmp) ? tmp : "(null)");
	ftpf_fix_width(i, str);
	ft_string_appendn(buf, str->data, str->length);
	ft_string_destroy(&str);
	if (i->precision > -1)
		ft_strdel(&tmp);
}
