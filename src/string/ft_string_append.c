/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:06:19 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/12/26 15:22:38 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string_priv.h"

void			ft_string_append(t_string *self, const char *s)
{
	size_t		len;

	len = ft_strlen(s);
	if (len + self->length >= self->size)
		ft_string_grow(self, len);
	ft_memcpy(self->data + self->length, s, len + 1);
	self->length += len;
	self->data[self->length] = 0;
}

void			ft_string_appendn(t_string *self, const char *s, size_t n)
{
	if (self->length + n >= self->size)
		ft_string_grow(self, n);
	ft_memcpy(self->data + self->length, s, n);
	self->length += n;
	self->data[self->length] = 0;
}

void			ft_string_real_append(t_string *self, t_string *s)
{
	if (s->length == 0)
		return ;
	if (self->length + s->length >= self->size)
		ft_string_grow(self, s->length);
	ft_memcpy(self->data + self->length, s->data, s->length + 1);
	self->length += s->length;
	self->data[self->length] = 0;
}
