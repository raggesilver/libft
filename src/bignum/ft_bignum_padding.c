/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bignum_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:56:40 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/06/25 23:50:43 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Quick reminder this function does not decrease decimal places as that could
** cut part of the number. Also the second if doesn't need to change self->point
** as it only adds zeros to the end, self->point's index remains intact.
*/

t_bignum		*ft_bignum_set_decimal_padding(t_bignum *self, size_t s)
{
	if (self->point == -1)
	{
		self->point = self->str->length;
		ft_string_padding(self->str, self->str->length, s + 1, '0');
		self->str->data[self->point] = '.';
	}
	else if (self->str->length - self->point - 1 < s)
	{
		ft_string_padding(self->str, self->str->length,
			s - (self->str->length - self->point - 1), '0');
	}
	return (self);
}

t_bignum		*ft_bignum_set_whole_padding(t_bignum *self, size_t s)
{
	size_t		len;

	len = (self->point != -1) ? (size_t)self->point : self->str->length;
	if (len < s)
	{
		ft_string_padding(self->str, 0, s - len, '0');
		if (self->point != -1)
		{
			self->point += s - len;
		}
	}
	return (self);
}
