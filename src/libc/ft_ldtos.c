/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:35:59 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/04 11:44:25 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#define BIAS			16383
#define MANT_SIZE		63
#define _15BITS			32767
#define MAX_EXPONENT	(32767 - BIAS - MANT_SIZE)
#define EMPTY			9223372036854775808u

#define INF				(f.exponent == MAX_EXPONENT && f.mantissa == EMPTY)
#define NAN_			(f.exponent == MAX_EXPONENT && f.mantissa != EMPTY)

const t_ull		g_2pow_arr[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024,
	2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576,
	2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728,
	268435456, 536870912, 1073741824, 2147483648, 4294967296, 8589934592,
	17179869184, 34359738368, 68719476736, 137438953472, 274877906944,
	549755813888, 1099511627776, 2199023255552, 4398046511104, 8796093022208,
	17592186044416, 35184372088832, 70368744177664, 140737488355328,
	281474976710656, 562949953421312, 1125899906842624, 2251799813685248,
	4503599627370496, 9007199254740992, 18014398509481984,
	36028797018963968, 72057594037927936, 144115188075855872,
	288230376151711744, 576460752303423488, 1152921504606846976,
	2305843009213693952, 4611686018427387904 };

const t_ull		g_5pow_arr[] = { 1, 5, 25, 125, 625, 3125, 15625, 78125, 390625,
	1953125, 9765625, 48828125, 244140625, 1220703125, 6103515625, 30517578125,
	152587890625, 762939453125, 3814697265625, 19073486328125, 95367431640625,
	476837158203125, 2384185791015625, 11920928955078125, 59604644775390625,
	298023223876953125, 1490116119384765625, 7450580596923828125 };

static void		fk_ldround_with_decimal(t_bignum *s, int precision)
{
	size_t aux;

	if (precision == 0)
	{
		aux = s->str->data[s->point + 1] >= '5';
		ft_string_remove(s->str, s->point, s->str->length);
		if (aux)
			ft_bignum_add(s->str, 1);
	}
	else if ((aux = s->str->length - s->point) < (size_t)precision)
	{
		ft_string_padding(s->str, s->str->length, precision - aux + 1, '0');
	}
	else if (aux > (unsigned)precision)
	{
		aux = s->str->data[s->point + precision + 1] >= '5';
		ft_string_remove(s->str, s->point + precision + 1, s->str->length);
		if (aux)
			ft_bignum_add(s->str, 1);
	}
}

static void		fk_ldround(t_bignum *s, int precision)
{
	size_t		aux;

	aux = 0;
	if (s->point != -1)
		fk_ldround_with_decimal(s, precision);
	else if (precision > 0)
	{
		aux = s->str->length;
		ft_string_padding(s->str, aux, precision + 1, '0');
		s->str->data[aux] = '.';
	}
}

/*
** VIT stands for Valid Incomplete Ternary and is used because norminette does
** not like `(a) ?: b` which translates to `(a) ? a : b`
*/

#define VIT(a, b) ((a) ? (a) : (b))

static void		fk_do_expo(t_bignum *n, t_float *f)
{
	RETURN_IF_FAIL((f->mantissa != 0));
	if (f->exponent > 0)
		while (f->exponent > 0)
		{
			ft_bignum_mult(n, g_2pow_arr[VIT((f->exponent % 62), 62)]);
			f->exponent -= VIT((f->exponent % 62), 62);
		}
	else
		while (f->exponent < 0)
		{
			ft_bignum_mult(n, g_5pow_arr[VIT((MOD(f->exponent) % 27), 27)]);
			ft_bignum_div_10pow(n, VIT((MOD(f->exponent) % 27), 27));
			f->exponent += VIT((MOD(f->exponent) % 27), 27);
		}
}

t_string		*ft_ldtos(long double n, int precision)
{
	t_float		f;
	t_bignum	*res;
	t_string	*aux;
	char		*tmp;

	f = ft_float_new(n);
	RETURN_VAL_IF_FAIL(ft_string_new(f.sign ? "-inf" : "inf"), !INF);
	RETURN_VAL_IF_FAIL(ft_string_new("nan"), !NAN_);
	tmp = ft_ulltoa(f.mantissa);
	res = ft_bignum_new_s(tmp);
	fk_do_expo(res, &f);
	fk_ldround(res, precision);
	if (res->str->data[0] == '.' || res->str->data[0] == 0)
		ft_string_prepend(res->str, "0");
	if (n < 0)
		ft_string_prepend(res->str, "-");
	aux = res->str;
	ft_memdel((void **)&res);
	return (aux);
}
