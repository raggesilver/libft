/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 23:17:46 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/14 23:18:57 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_priv.h"

t_string		*ft_sprintf(const char *s, ...)
{
	va_list		ap;
	t_string	*buf;

	va_start(ap, s);
	buf = ft_vsprintf(s, ap);
	va_end(ap);
	return (buf);
}
