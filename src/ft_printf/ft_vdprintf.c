/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 22:58:40 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/14 23:17:08 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_priv.h"

int		ft_vdprintf(int fd, const char *s, va_list ap)
{
	int			res;
	t_string	*buf;

	buf = ft_vsprintf(s, ap);
	res = write(fd, buf->data, buf->length);
	ft_string_destroy(&buf);
	return (res);
}
