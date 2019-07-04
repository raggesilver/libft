/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 21:29:41 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/11 22:59:40 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ftpf_print_pct(t_pinfo *i)
{
	t_string	*str;

	str = ft_string_new("%");
	i->fix = 0;
	ftpf_fix_width(i, str);
	i->res = write(1, str->data, str->length);
	ft_string_destroy(&str);
}