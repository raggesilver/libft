/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_prepend.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:03:49 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/06/05 23:25:59 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_string_priv.h"

void			ft_string_prepend(t_string *self, const char *s)
{
	ssize_t tmp;
	char	*old;

	if (self->data == NULL)
		self->length = ft_strdupsz(&self->data, s);
	else
	{
		tmp = ft_strlen(s);
		old = self->data;
		self->data = malloc(self->length + tmp + 1);
		self->data[0] = 0;
		ft_strcat(self->data, s);
		ft_strcat(self->data, old);
		self->length += tmp;
		self->data[self->length] = 0;
		ft_strdel(&old);
	}
}

void			ft_string_prepend_s(t_string *self, const char *s)
{
	ft_string_prepend(self, s);
	ft_strdel((char **)&s);
}
