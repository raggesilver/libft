/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 19:36:18 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/11 16:05:18 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** '-' is the only flag that works with %c
*/

void		ftpf_print_chr(t_pinfo *i, va_list *ap)
{
	t_string	*str;

	str = ft_string_new(" ");
	str->data[0] = va_arg(*ap, int);
	ftpf_fix_width(i, str);
	i->res = write(1, str->data, str->length);
	ft_string_destroy(&str);
}
