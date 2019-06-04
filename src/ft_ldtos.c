/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:35:59 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/06/03 14:05:33 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

#define LD long double
#define BIAS			16383
#define MANT_SIZE		63
#define _15BITS			32767
#define MAX_EXPONENT	(32767 - BIAS - MANT_SIZE)
#define EMPTY			9223372036854775808u

#define INF				(f.exponent == MAX_EXPONENT && f.mantissa == EMPTY)
#define NAN_			(f.exponent == MAX_EXPONENT && f.mantissa != EMPTY)

static char		g_carry[2] = " \0";

static void		fk_strm(t_string *s, int n)
{
	size_t	i;
	int		carry;
	int		c;

	i = s->length;
	carry = 0;
	while (i-- > 0)
	{
		if (s->data[i] == '.')
			continue ;
		else if (s->data[i] == '-')
			break ;
		c = ((s->data[i] - '0') * n) + carry;
		carry = (c > 9) ? (int)c / 10 : 0;
		s->data[i] = '0' + (c % 10);
	}
	if (carry > 0)
	{
		g_carry[0] = '0' + carry;
		ft_string_inpend(s, i + 1, g_carry);
	}
}

static void		fk_strd2(t_string *s)
{
	char *aux;

	fk_strm(s, 5);
	if (s->data[0] == '.')
	{
		ft_string_prepend(s, ".");
		s->data[1] = '0';
	}
	else if ((aux = ft_strchr(s->data, '.')))
	{
		*aux = *(aux - 1);
		*(aux - 1) = '.';
	}
	else
		ft_string_inpend(s, s->length - 1, ".");
}

static void		fk_ldround(t_string *s, int precision)
{
	char		*pt;
	char		*zeros;
	size_t		aux;

	if ((pt = ft_strchr(s->data, '.')) &&
		s->length - (pt - 1 - s->data) < (unsigned)precision)
	{
		zeros = ft_strnew(precision - s->length - (pt - 1 - s->data));
		ft_memset(zeros, '0', precision - s->length - (pt - 1 - s->data));
		ft_string_append(s, zeros);
		ft_strdel(&zeros);
	}
	else if (pt && s->length - (pt + 1 - s->data) > (unsigned)precision)
	{
		if (precision == 0)
			ft_string_remove(s, pt - s->data, s->length);
		else
		{
			aux = pt - s->data + precision + 1;
			if (s->data[aux] >= '5' && ft_string_remove(s, aux, s->length))
				ft_bignum_add(s, 1);
			else
				ft_string_remove(s, aux, s->length);
		}
	}
	else
	{
		zeros = ft_strnew(precision + 1);
		ft_memset(zeros, '0', precision + 1);
		*zeros = '.';
		ft_string_append(s, zeros);
		ft_strdel(&zeros);
	}
}

t_string		*ft_ldtos(long double n, int precision)
{
	t_float		f;
	t_string	*res;
	char		*tmp;

	f = ft_float_new(n);
	RETURN_VAL_IF_FAIL(ft_string_new(f.sign ? "-inf" : "inf"), !INF);
	RETURN_VAL_IF_FAIL(ft_string_new("nan"), !NAN_);
	tmp = ft_ulltoa(f.mantissa);
	res = ft_string_new_steal(&tmp);
	if (f.exponent > 0)
		while (f.exponent-- > 0)
			fk_strm(res, 2);
	else
		while (f.exponent++ < 0)
			fk_strd2(res);
	fk_ldround(res, precision);
	if (res->data[0] == '.')
		ft_string_prepend(res, "0");
	if (n < 0)
		ft_string_prepend(res, "-");
	return (res);
}
