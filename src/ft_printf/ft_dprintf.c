/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 23:09:27 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/14 23:17:26 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_priv.h"

int		ft_dprintf(int fd, const char *s, ...)
{
	int			res;
	va_list		ap;

	va_start(ap, s);
	res = ft_vdprintf(fd, s, ap);
	va_end(ap);
	return (res);
}
