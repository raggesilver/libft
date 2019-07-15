/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:44:00 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/14 22:45:03 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_priv.h"

int				ft_printf(const char *s, ...)
{
	int			res;
	va_list		ap;

	va_start(ap, s);
	res = ft_vdprintf(1, s, ap);
	va_end(ap);
	return (res);
}
