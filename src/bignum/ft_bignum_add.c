/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bignum_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:43:15 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/05/31 21:43:02 by pqueiroz         ###   ########.fr       */
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
	(n > 0) ? ft_string_prepend(self, ft_itoa(n)) : 0;
	return (self);
}
