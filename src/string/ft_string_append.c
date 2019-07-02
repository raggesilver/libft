/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:06:19 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/06/30 16:33:44 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string_priv.h"

void			ft_string_append(t_string *self, const char *s)
{
	ssize_t tmp;

	if (self->data == NULL)
		self->length = ft_strdupsz(&self->data, s);
	else
	{
		tmp = ft_strlen(s);
		self->data = ft_reallocsz(
			self->data, self->length, self->length + tmp + 1);
		self->length += tmp;
		self->data[self->length] = 0;
		while (tmp >= 0)
			self->data[self->length - tmp--] = *s++;
	}
}

void			ft_string_appendn(t_string *self, const char *s, size_t n)
{
	if (self->data == NULL)
	{
		self->data = ft_strndup(s, n);
		self->length = n;
	}
	else
	{
		self->data = ft_reallocsz(
			self->data, self->length, self->length + n + 1);
		ft_memcpy(self->data + self->length, s, n);
		self->length += n;
		self->data[self->length] = 0;
	}
}

void			ft_string_real_append(t_string *self, t_string *s)
{
	RETURN_IF_FAIL((s->length > 0));
	if (self->data == NULL)
	{
		self->data = malloc(s->length + 1);
		ft_memcpy(self->data, s->data, s->length + 1);
		self->length = s->length;
	}
	else
	{
		self->data = ft_reallocsz(
			self->data, self->length, self->length + s->length + 1);
		ft_memcpy(self->data + self->length, s->data, s->length + 1);
		self->length += s->length;
	}
}
