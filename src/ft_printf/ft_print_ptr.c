/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 22:27:09 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/06/26 13:03:12 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ftpf_print_ptr(t_pinfo *i, va_list *ap)
{
	unsigned long int	v;
	t_string			*s;
	char				*tmp;

	v = (unsigned long int)va_arg(*ap, void *);
	s = ft_string_new("0x");
	tmp = ft_ulltoa_base(v, 16);
	ft_string_append(s, tmp);
	ft_string_to_lower(s);
	ft_strdel(&tmp);
	ftpf_fix_width(i, s);
	i->res = write(1, s->data, s->length);
	ft_string_destroy(&s);
}
