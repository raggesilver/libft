/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bignum_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:43:15 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/24 23:04:30 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#define NUM(x) (x - '0')

char				g_carry[2] = " \0";

t_bignum			*ft_bignum_add(t_bignum *self, int n)
{
	ssize_t		i;
	t_string	*s;
	int			carry;

	// if (n < 0)
	// 	return (ft_bignum_sub(self, -n));
	s = BN_TO_STRING(self);
	i = s->length;
	carry = 0;
	while (--i >= 0 && n > 0)
	{
		CONTINUE_IF_FAIL((s->data[i] != '.'));
		carry = NUM(s->data[i]) + (n % self->base) + ((carry > 0) ? carry : 0);
		s->data[i] = g_chars[carry % self->base];
		carry -= self->base;
		if (i == 0 && carry > 0 && ++i && (g_carry[0] = g_chars[carry]))
			ft_string_prepend(s, g_carry);
		n /= self->base;
	}
	(n > 0)	? ft_string_prepend(s, ft_itoa(n)) : 0;
	self->length = s->length;
	self->str = (const char *)s->data;
	return (self);
}
