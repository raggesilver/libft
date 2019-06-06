/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:06:19 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/06/05 15:06:47 by pqueiroz         ###   ########.fr       */
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
