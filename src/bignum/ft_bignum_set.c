/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bignum_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:18:45 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/06/07 15:57:55 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../string/ft_string_priv.h"

t_bignum		*ft_bignum_set(t_bignum *self, const char *s)
{
	char		*aux;

	ft_string_destroy(&self->str);
	self->str = ft_string_new(s);
	if ((aux = ft_strchr(self->str->data, '.')))
		self->point = aux - self->str->data;
	else
		self->point = -1;
	return (self);
}
