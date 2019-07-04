/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_fix_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:16:49 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/06/03 23:13:49 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ftpf_fix_precision(t_pinfo *i, t_string *s)
{
	char	*aux;
	int		diff;
	int		acc;

	aux = NULL;
	acc = (i->flags & HASH && (ft_tolower(s->data[1]) == 'x')) ? 2 : 0;
	if (i->precision > 1 && i->precision > (diff = (s->length - i->fix - acc)))
	{
		diff = i->precision - diff;
		aux = ft_strnew(diff);
		ft_memset(aux, '0', diff);
		ft_string_inpend(s, i->fix + acc, aux);
		ft_strdel(&aux);
	}
}

static void	ftpf_fix_hex(t_pinfo *i, t_string *s, char *aux)
{
	if (i->flags & HASH)
		i->fix += 2;
	if (i->precision > 0 && (long long)s->length < i->precision)
	{
		aux = ft_strnew(i->precision - s->length);
		ft_memset(aux, '0', i->precision - s->length);
		ft_string_inpend(s, i->fix, aux);
		ft_strdel(&aux);
	}
	if (s->length < (size_t)i->min_width)
	{
		aux = ft_strnew(i->min_width - s->length);
		ft_memset(aux, (i->flags & ZERO && i->precision == -1) ?
			'0' : ' ', i->min_width - s->length);
		if (i->flags & MINUS)
			ft_string_append(s, aux);
		else
			ft_string_inpend(s, *aux == ' ' ? 0 : i->fix, aux);
	}
}

void		ftpf_fix_width(t_pinfo *i, t_string *s)
{
	char	*aux;

	aux = NULL;
	if (i->conv == 'x' || i->conv == 'X')
		ftpf_fix_hex(i, s, aux);
	else if (s->length < ((size_t)i->min_width))
	{
		aux = ft_strnew(i->min_width - s->length);
		ft_memset(aux, (i->flags & ZERO && i->precision == -1) ? '0' :
			' ', i->min_width - s->length);
		if (i->flags & ZERO || !(i->flags & MINUS))
			ft_string_inpend(s, *aux == '0' ? i->fix : 0, aux);
		else
			ft_string_append(s, aux);
	}
	ft_strdel(&aux);
}
