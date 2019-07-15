/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 21:29:41 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/14 22:35:40 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_priv.h"

void		ftpf_print_pct(t_string *buf, t_pinfo *i)
{
	t_string	*str;

	str = ft_string_new("%");
	i->fix = 0;
	ftpf_fix_width(i, str);
	ft_string_appendn(buf, str->data, str->length);
	ft_string_destroy(&str);
}
