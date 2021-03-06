/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 22:27:09 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/14 22:36:12 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_priv.h"

void		ftpf_print_ptr(t_string *buf, t_pinfo *i, va_list *ap)
{
	unsigned long int	v;
	t_string			*str;
	char				*tmp;

	v = (unsigned long int)va_arg(*ap, void *);
	str = ft_string_new("0x");
	tmp = ft_ulltoa_base(v, 16);
	ft_string_append(str, tmp);
	ft_string_to_lower(str);
	ft_strdel(&tmp);
	ftpf_fix_width(i, str);
	ft_string_appendn(buf, str->data, str->length);
	ft_string_destroy(&str);
}
