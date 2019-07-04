/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_fix_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:06:05 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/06/25 23:35:53 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ftpf_fix_zero(t_pinfo *i, t_string *s)
{
	size_t	ii;
	char	*aux;
	char	fchars[4];

	RETURN_IF_FAIL((i->flags & ZERO || i->precision > 1));
	ft_strcpy(fchars, "-+ ");
	ii = 0;
	while (++ii < s->length)
		if ((aux = ft_strchr(fchars, s->data[ii])))
		{
			s->data[0] = *aux;
			s->data[ii] = '0';
			break ;
		}
}
