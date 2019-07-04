/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bignum_mult.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:02:44 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/04 11:41:28 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char		g_carry[2] = " \0";

static void		fk_bn_mult(t_bignum *s, int n)
{
	ssize_t	i;
	int		carry;
	int		c;

	i = s->str->length;
	carry = 0;
	while (i-- > 0)
	{
		if (s->str->data[i] == '.')
			continue ;
		else if (s->str->data[i] == '-')
			break ;
		c = ((s->str->data[i] - '0') * n) + carry;
		carry = (c > 9) ? (int)c / 10 : 0;
		s->str->data[i] = '0' + (c % 10);
	}
	if (carry > 0)
	{
		g_carry[0] = '0' + carry;
		ft_string_prepend(s->str, g_carry);
		if (s->point != -1)
			s->point++;
	}
}

t_bignum		*ft_bignum_mult(t_bignum *self, t_ull n)
{
	t_bignum	*a1;
	t_bignum	*a2;
	size_t		i;

	i = 0;
	a1 = ft_bignum_new("0");
	a2 = ft_bignum_new(self->str->data);
	while (n > 0)
	{
		if (n % 10 != 0)
		{
			fk_bn_mult(a2, n % 10);
			ft_bignum_mult_10pow(a2, i);
			ft_bignum_real_add(a1, a2);
		}
		n /= 10;
		i++;
		if (n > 0)
			a2 = ft_bignum_set(a2, self->str->data);
	}
	ft_bignum_set(self, a1->str->data);
	ft_bignum_destroy(&a1);
	ft_bignum_destroy(&a2);
	return (self);
}
