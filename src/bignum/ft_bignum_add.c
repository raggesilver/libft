/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bignum_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:43:15 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/06/08 01:12:43 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#define NUM(x) ((ft_isdigit(x)) ? x - '0' : 10 + ft_toupper(x) - 'A')

static char			g_carry[2] = " \0";

t_string			*ft_bignum_add(t_string *self, int n)
{
	ssize_t		i;
	int			carry;

	i = self->length;
	carry = 0;
	while (--i >= 0 && (n > 0 || carry > 0))
	{
		CONTINUE_IF_FAIL((self->data[i] != '.'));
		carry = NUM(self->data[i]) + (n % 10) + ((carry > 0) ? carry : 0);
		self->data[i] = g_chars[carry % 10];
		carry -= 10 - 1;
		if (i == 0 && carry > 0 && ++i && (g_carry[0] = g_chars[carry]))
		{
			carry = 0;
			ft_string_prepend(self, g_carry);
		}
		n /= 10;
	}
	(n > 0) ? ft_string_prepend_s(self, ft_itoa(n)) : 0;
	return (self);
}

#include <stdio.h>

static void		ftfk_fix_places(t_bignum *a, t_bignum *b)
{
	if (a->point > -1 && b->point > -1)
	{
		// //printf("#1 Before fix a: '%s', b: '%s'\n", a->str->data, b->str->data);
		if (a->str->length - a->point > b->str->length - b->point)
		{
			ft_bignum_set_decimal_padding(b, a->str->length - a->point - 1);
			// //printf("Here 1, set '%lu' digits\n", a->str->length - a->point - 1);
		}
		else if (a->str->length - a->point < b->str->length - b->point)
		{
			ft_bignum_set_decimal_padding(a, b->str->length - b->point - 1);
			// //printf("Here 2, set '%lu' digits\n", a->str->length - a->point - 1);
		}
		// //printf("#1 After fixed places a: '%s', b: '%s'\n", a->str->data, b->str->data);
	}
	else if (a->point > -1 && b->point == -1)
	{
		ft_bignum_set_decimal_padding(b, a->str->length - a->point - 1);
		// //printf("#2 After fixed places a: '%s', b: '%s'\n", a->str->data, b->str->data);
	}
	else if (b->point > -1 && a->point == -1)
	{
		ft_bignum_set_decimal_padding(a, b->str->length - b->point - 1);
		// //printf("#3 After fixed places a: '%s', b: '%s'\n", a->str->data, b->str->data);
	}
	if (a->str->length > b->str->length)
	{
		ft_bignum_set_whole_padding(b, (a->point != -1) ? a->point : a->str->length);
		// //printf("#4 After fixed places a: '%s', b: '%s'\n", a->str->data, b->str->data);
	}
	if (a->str->length < b->str->length)
	{
		ft_bignum_set_whole_padding(a, (b->point != -1) ? b->point : b->str->length);
		// //printf("#5 After fixed places a: '%s', b: '%s'\n", a->str->data, b->str->data);
	}
}

t_bignum		*ft_bignum_real_add(t_bignum *self, t_bignum *num)
{
	ssize_t		i;
	ssize_t		j;
	int			carry;

	ftfk_fix_places(self, num);
	//printf("\nAfter fixed places a: '%s', b: '%s'\n", self->str->data, num->str->data);
	i = self->str->length;
	j = num->str->length;
	carry = 0;
	while (--i >= 0 && --j >= 0)
	{
		if (self->str->data[i] == '.' || num->str->data[j] == '.')
			continue ;
		carry = NUM(self->str->data[i]) + NUM(num->str->data[j]) + carry;
		self->str->data[i] = '0' + carry % 10;
		carry /= 10;
		if (i == 0 && carry > 0 && ++i && (g_carry[0] = g_chars[carry]))
		{
			carry = 0;
			ft_string_prepend(self->str, g_carry);
			if (self->point != -1)
				self->point++;
		}
	}
	return (self);
}
