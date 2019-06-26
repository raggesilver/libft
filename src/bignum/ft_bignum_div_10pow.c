/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bignum_div_10pow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 19:27:01 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/06/26 13:12:42 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** self / (10^n)
*/

t_bignum		*ft_bignum_div_10pow(t_bignum *self, size_t n)
{
	RETURN_VAL_IF_FAIL(self, (n != 0));
	if (self->point == -1)
	{
		if (self->str->length <= n)
		{
			ft_string_padding(self->str, 0, (n - self->str->length) + 2, '0');
			self->str->data[1] = '.';
			self->point = 1;
		}
		else
		{
			ft_string_inpend(self->str, self->str->length - n, ".");
			self->point = self->str->length - n;
		}
		return (self);
	}
	if ((ssize_t)n >= self->point &&
		ft_string_padding(self->str, 0, (n - self->point) + 1, '0'))
		self->point += (n - self->point) + 1;
	while (n-- > 0)
	{
		self->str->data[self->point] = self->str->data[self->point - 1];
		self->str->data[--self->point] = '.';
	}
	return (self);
}
