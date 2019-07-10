/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_prepend.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:03:49 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/07/10 01:10:30 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string_priv.h"

void			ft_string_prepend(t_string *self, const char *s)
{
	size_t		len;
	ssize_t		i;

	len = ft_strlen(s);
	if (self->length + len >= self->size)
		ft_string_grow(self, len);
	i = self->length;
	while (--i >= 0)
		self->data[i + len] = self->data[i];
	i = -1;
	while (++i < (ssize_t)len)
		self->data[i] = s[i];
	self->length += len;
	self->data[self->length] = 0;
}

inline void		ft_string_prepend_s(t_string *self, const char *s)
{
	ft_string_prepend(self, s);
	ft_strdel((char **)&s);
}
