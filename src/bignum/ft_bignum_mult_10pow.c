/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bignum_mult_10pow.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:39:05 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/06/07 19:31:13 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** self * (10^n)
*/

t_bignum		*ft_bignum_mult_10pow(t_bignum *self, size_t n)
{
	if (n == 0)
		return (self);
	if (self->point == -1)
	{
		ft_string_padding(self->str, self->str->length, n, '0');
		return (self);
	}
	if (self->point + n >= self->str->length - 1)
		ft_string_padding(self->str, self->str->length,
			(self->point + n + 2) - self->str->length, '0');
	while (n > 0)
	{
		self->str->data[self->point] = self->str->data[self->point + 1];
		self->str->data[self->point + 1] = '.';
		self->point++;
		n--;
		if (self->str->data[0] == '0' && self->str->data[1] == '0')
		{
			ft_string_remove(self->str, 0, 1);
			self->point--;
		}
	}
	return (self);
}
